/*
   libember_slim -- ANSI C implementation of the Ember+ Protocol
   Copyright (C) 2012  L-S-B Broadcast Technologies GmbH

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <string.h>
#include <ctype.h>
#include "berio.h"
#include "emberinternal.h"

// ======================================================
//
// Locals
//
// ======================================================

static byte berMemoryInput_readByte(BerInput *pBase)
{
   BerMemoryInput *pThis = (BerMemoryInput *)pBase;
   byte b;

   if(berMemoryInput_isEof(pThis) == false)
   {
      b = pThis->pMemory[pThis->position];
      pThis->position++;
      return b;
   }
   else
   {
      throwError(301, "BerMemoryInput EOF");
   }

   return 0xFF;
}

static byte berFileInput_readByte(BerInput *pBase)
{
   BerFileInput *pThis = (BerFileInput *)pBase;

   int read = fgetc(pThis->pFile);

   if(read >= 0)
      return (byte)(read & 0xFF);
   else
      throwError(302, "BerFileInput EOF");

   return 0xFF;
}

static void berMemoryOutput_writeBytes(BerOutput *pBase, const byte *pBytes, int count)
{
   BerMemoryOutput *pThis = (BerMemoryOutput *)pBase;
   unsigned int left;
   unsigned int ucount;
   unsigned int sendCount;

   if(count > 0)
   {
      if(pThis->position < pThis->size)
      {
         left = pThis->size - pThis->position;
         ucount = (unsigned int)count;
         sendCount = left < ucount ? left : ucount;

         memcpy(pThis->pMemory + pThis->position, pBytes, sendCount);
         pThis->position += sendCount;
      }
      else
      {
         throwError(303, "BerMemoryOutput capacity exceeded");
      }
   }
}

static void berFileOutput_writeByte(BerOutput *pBase, byte b)
{
   BerFileOutput *pThis = (BerFileOutput *)pBase;

   fputc(b, pThis->pFile);
}

static void berFileOutput_writeBytes(BerOutput *pBase, const byte *pBytes, int count)
{
   BerFileOutput *pThis = (BerFileOutput *)pBase;

   fwrite(pBytes, 1, count, pThis->pFile);
}


// ======================================================
//
// Internals
//
// ======================================================

void berMemoryOutput_writeByte(BerOutput *pBase, byte b)
{
   BerMemoryOutput *pThis = (BerMemoryOutput *)pBase;

   if(pThis->position < pThis->size)
   {
      pThis->pMemory[pThis->position] = b;
      pThis->position++;
   }
   else
   {
      throwError(304, "BerMemoryOutput capacity exceeded");
   }
}


// ======================================================
//
// Globals
//
// ======================================================

void berMemoryInput_init(BerMemoryInput *pThis, const byte *pMemory, unsigned int size)
{
   ASSERT(pThis != NULL);

   // init methods
   pThis->base.readByte = berMemoryInput_readByte;

   // init data
   pThis->pMemory = pMemory;
   pThis->position = 0;
   pThis->size = size;
}

bool berMemoryInput_isEof(const BerMemoryInput *pThis)
{
   return pThis->position >= pThis->size;
}

void berFileInput_init(BerFileInput *pThis, FILE *pFile)
{
   ASSERT(pThis != NULL);

   // init methods
   pThis->base.readByte = berFileInput_readByte;

   // init data
   pThis->pFile = pFile;
}

void berMemoryOutput_init(BerMemoryOutput *pThis, byte *pMemory, unsigned int size)
{
   ASSERT(pThis != NULL);

   // init methods
   pThis->base.writeByte = berMemoryOutput_writeByte;
   pThis->base.writeBytes = berMemoryOutput_writeBytes;

   // init data
   pThis->pMemory = pMemory;
   pThis->position = 0;
   pThis->size = size;
}

void berMemoryOutput_reset(BerMemoryOutput *pThis)
{
   ASSERT(pThis != NULL);

   pThis->position = 0;
}

void berFileOutput_init(BerFileOutput *pThis, FILE *pFile)
{
   ASSERT(pThis != NULL);

   // init methods
   pThis->base.writeByte = berFileOutput_writeByte;
   pThis->base.writeBytes = berFileOutput_writeBytes;

   // init data
   pThis->pFile = pFile;
}

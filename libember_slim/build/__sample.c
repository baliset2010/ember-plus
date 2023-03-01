/*
   libember_slim sample

    Copyright (C) 2012-2016 Lawo GmbH (http://www.lawo.com).
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "emberplus.h"

#ifdef linux
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

#ifndef SECURE_CRT
#define printf_s printf
#endif

#define VERSION (0x0104)

#ifdef linux
#include <sys/select.h>
#include <unistd.h>

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    // 標準入力のファイルディスクリプタを非同期モードに設定する
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // 標準入力から文字を読み込み、エコーバックを無効にする
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    // 設定を元に戻す
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    // キーが押されたかどうかをチェックする
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void strrev(char *str) {
	if (str == NULL) {
		return;
	}

	size_t len = strlen(str);
	for (size_t i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

char *_itoa(int value, char *str, int base) {
    // 変数宣言
    int i = 0, sign = 0;

    // 値が0の場合は、文字列"0"を返す
    if (value == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // 基数が10の場合は、符号をチェックする
    if (base == 10 && value < 0) {
        sign = 1;
        value = -value;
    }

    // 数値を文字列に変換する
    while (value != 0) {
        int rem = value % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        value /= base;
    }

    // 符号を追加する
    if (sign) {
        str[i++] = '-';
    }

    // 文字列を反転する
    strrev(str);

    // 文字列を終端する
    str[i] = '\0';

    // 文字列を返す
    return str;
}

int __itoa_s(int value, char* buffer, size_t size, int radix) {
    int result = 0;
    int index = 0;

    // バッファがNULLの場合やサイズが0の場合はエラー
    if (buffer == NULL || size == 0) {
        return -1;
    }

    // 基数が2から36の範囲内でない場合はエラー
    if (radix < 2 || radix > 36) {
        return -1;
    }

    // 負の値の場合は符号をバッファにセットして値を正にする
    if (value < 0) {
        buffer[0] = '-';
        index++;
        value = -value;
    }

    // 数値を文字列に変換する
    do {
        if (index == size - 1) {
            // バッファが不足している場合はエラー
            return -1;
        }
        buffer[index++] = "0123456789abcdefghijklmnopqrstuvwxyz"[value % radix];
        value /= radix;
    } while (value);

    // 文字列を反転する
    int i = 0, j = index - 1;
    while (i < j) {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
        i++;
        j--;
    }

    // 終端文字をセットする
    buffer[index] = '\0';

    // 成功を示す0を返す
    return 0;
}

char *itoa(int n, char *buf, int radix) {
	if (radix == 10) {
		sprintf(buf, "%d", n);
	} else if (radix == 16) {
		sprintf(buf, "%X", n);
	} else {
		return _itoa(n, buf, radix);
	}
	return buf;
}

int _itoa_s(int n, char *buf, int size, int radix) {
	if (radix == 10) {
		snprintf(buf, size, "%d", n);
	} else if (radix == 16) {
		snprintf(buf, size, "%X", n);
	} else {
		return __itoa_s(n, buf, size, radix);
	}
	return 0;
}
#endif

void runConsumer(int argc, char **argv);
void runProvider(int argc, char **argv);

// ====================================================================
//
// entry point
//
// ====================================================================

static void displayHelp()
{
   printf_s("USAGE:\n"
            "emberplus.exe <remoteAddress> <remotePort>\n"
            "emberplus.exe -provider <listenPort>\n");
}

int main(int argc, char **argv)
{
   printf_s("emberplus v%d.%d (EmBER Encoding %d.%d GlowDTD %d.%d)\n",
            VERSION >> 8,
            VERSION & 0xFF,
            EMBER_ENCODING_VERSION >> 8,
            EMBER_ENCODING_VERSION & 0xFF,
            GLOW_SCHEMA_VERSION >> 8,
            GLOW_SCHEMA_VERSION & 0xFF);

#ifdef _DEBUG
   printf_s("GlowReader: %d\nNonFramingGlowReader: %d\nEmberAsyncReader: %d\nGlowParameter: %d\nGlowNode: %d\nGlowMatrix: %d\nGlowConnection: %d\n",
            sizeof(GlowReader),
            sizeof(NonFramingGlowReader),
            sizeof(EmberAsyncReader),
            sizeof(GlowParameter),
            sizeof(GlowNode),
            sizeof(GlowMatrix),
            sizeof(GlowConnection));
#endif

   if(argc >= 2)
   {
      if(strcmp(argv[1], "-provider") == 0)
      {
         if(argc >= 3)
         {
            runProvider(argc - 1, argv + 1);
            return 0;
         }
      }
      else
      {
         if(argc >= 3)
         {
            runConsumer(argc, argv);
            return 0;
         }
      }
   }

   displayHelp();
   return 0;
}

BER
===

Utilities
---------
LIBEMBER_API int ber_getTagLength(const BerTag *pTag);
LIBEMBER_API int ber_getIntegerLength(berint value);
LIBEMBER_API int ber_getLongLength(berlong value);
LIBEMBER_API int ber_getHeaderLength(const BerTag *pTag, int length);
LIBEMBER_API int ber_getMultiByteIntegerLength(dword value);
LIBEMBER_API int ber_getStringLength(pcstr pValue);
LIBEMBER_API int ber_getRelativeOidLength(const berint *pValue, int count);
LIBEMBER_API void ber_getTypeName(pstr pBuffer, int bufferLength, bertype type);
LIBEMBER_API pcstr ber_getShortClassName(BerClass berClass);

Encode functions
----------------
LIBEMBER_API int ber_encodeTag(BerOutput *pOut, const BerTag *pTag);
LIBEMBER_API int ber_encodeLength(BerOutput *pOut, int value);
LIBEMBER_API int ber_encodeMultiByteInteger(BerOutput *pOut, dword value);
LIBEMBER_API int ber_encodeBoolean(BerOutput *pOut, bool value);
LIBEMBER_API int ber_encodeInteger(BerOutput *pOut, berint value, int lengt
LIBEMBER_API int ber_encodeLong(BerOutput *pOut, berlong value, int length);
LIBEMBER_API int ber_encodeReal(BerOutput *pOut, double value);
LIBEMBER_API int ber_encodeString(BerOutput *pOut, pcstr pValue);
LIBEMBER_API int ber_encodeOctetString(BerOutput *pOut, const byte *pValue, int length);
LIBEMBER_API int ber_encodeRelativeOid(BerOutput *pOut, const berint *pValue, int count);
LIBEMBER_API int ber_encodeNull(BerOutput *pOut);

Decode functions
----------------
LIBEMBER_API BerTag ber_decodeTag(BerInput *pIn);
LIBEMBER_API int ber_decodeLength(BerInput *pIn);
LIBEMBER_API dword ber_decodeMultiByteInteger(BerInput *pIn, int *pConsumedBytesCount);
LIBEMBER_API bool ber_decodeBoolean(BerInput *pIn);
LIBEMBER_API berint ber_decodeInteger(BerInput *pIn, int length);
LIBEMBER_API berlong ber_decodeLong(BerInput *pIn, int length);
LIBEMBER_API double ber_decodeReal(BerInput *pIn, int length);
LIBEMBER_API void ber_decodeString(BerInput *pIn, pstr pDest, int length);
LIBEMBER_API void ber_decodeOctetString(BerInput *pIn, byte *pDest, int length);
LIBEMBER_API int ber_decodeRelativeOid(BerInput *pIn, berint *pDest, int destSize, int length);
LIBEMBER_API void ber_decodeNull(BerInput *pIn);

BERIO
=====

BerMemoryInput
--------------
LIBEMBER_API void berMemoryInput_init(BerMemoryInput *pThis, const byte *pMemory, unsigned int size);
LIBEMBER_API bool berMemoryInput_isEof(const struct SBerMemoryInput *pThis);

BerFileInput
------------
LIBEMBER_API void berFileInput_init(BerFileInput *pThis, FILE *pFile);

BerOutput
---------
LIBEMBER_API void berMemoryOutput_init(BerMemoryOutput *pThis, byte *pMemory, unsigned int size);
LIBEMBER_API void berMemoryOutput_reset(BerMemoryOutput *pThis);
LIBEMBER_API void berFileOutput_init(BerFileOutput *pThis, FILE *pFile);


BER Reader
==========

LIBEMBER_API void berReader_init(BerReader *pThis);
LIBEMBER_API void berReader_free(BerReader *pThis);
LIBEMBER_API void berReader_reset(BerReader *pThis);
LIBEMBER_API bool berReader_getBoolean(const BerReader *pThis);
LIBEMBER_API berint berReader_getInteger(const BerReader *pThis);
LIBEMBER_API berlong berReader_getLong(const BerReader *pThis);
LIBEMBER_API double berReader_getReal(const BerReader *pThis);
LIBEMBER_API void berReader_getString(const BerReader *pThis, pstr pDest, int size);
LIBEMBER_API int berReader_getOctetString(const BerReader *pThis, byte *pDest, int size);
LIBEMBER_API int berReader_getRelativeOid(const BerReader *pThis, berint *pDest, int destSize);
LIBEMBER_API void berReader_getNull(const BerReader *pThis);

BER TAG
=======

LIBEMBER_API void berTag_init(BerTag *pThis, BerClass berClass, tagnumber number);
LIBEMBER_API bool berTag_isContainer(const BerTag *pThis);
LIBEMBER_API void berTag_setContainer(BerTag *pThis, bool value);
LIBEMBER_API BerClass berTag_getClass(const BerTag *pThis);
LIBEMBER_API void berTag_setClass(BerTag *pThis, BerClass value);
LIBEMBER_API bool berTag_isZero(const BerTag *pThis);
LIBEMBER_API BerTag berTag_toContainer(const BerTag *pThis);
LIBEMBER_API bertype berTag_numberAsType(const BerTag *pThis);
LIBEMBER_API void berTag_toString(const BerTag *pThis, pstr pBuffer, int bufferSize);
LIBEMBER_API bool berTag_equals(const BerTag *pThis, const BerTag *pThat);


BER Buffer
=========

LIBEMBER_API void byteBuffer_init(ByteBuffer *pThis, byte *pMemory, unsigned int size);
LIBEMBER_API void byteBuffer_initDynamic(ByteBuffer *pThis, unsigned int size);
LIBEMBER_API void byteBuffer_add(ByteBuffer *pThis, byte b);
LIBEMBER_API void byteBuffer_reset(ByteBuffer *pThis);
LIBEMBER_API void byteBuffer_resize(ByteBuffer *pThis, unsigned int size);
LIBEMBER_API bool byteBuffer_isEmpty(const ByteBuffer *pThis);
LIBEMBER_API void byteBuffer_free(ByteBuffer *pThis);


EMBER
=====

Write Function
--------------

LIBEMBER_API void ember_writeContainerBegin(BerOutput *pOut, const BerTag *pTag, bertype type);
LIBEMBER_API void ember_writeSequenceBegin(BerOutput *pOut, const BerTag *pTag);
LIBEMBER_API void ember_writeSetBegin(BerOutput *pOut, const BerTag *pTag);
LIBEMBER_API void ember_writeContainerEnd(BerOutput *pOut);
LIBEMBER_API void ember_writeBoolean(BerOutput *pOut, const BerTag *pTag, bool value);
LIBEMBER_API void ember_writeInteger(BerOutput *pOut, const BerTag *pTag, berint value);
LIBEMBER_API void ember_writeLong(BerOutput *pOut, const BerTag *pTag, berlong value);
LIBEMBER_API void ember_writeReal(BerOutput *pOut, const BerTag *pTag, double value);
LIBEMBER_API void ember_writeString(BerOutput *pOut, const BerTag *pTag, pcstr pValue);
LIBEMBER_API void ember_writeOctetString(BerOutput *pOut, const BerTag *pTag, const byte *pValue, int valueLength);
LIBEMBER_API void ember_writeRelativeOid(BerOutput *pOut, const BerTag *pTag, const berint *pValue, int count);
LIBEMBER_API void ember_writeNull(BerOutput *pOut, const BerTag *pTag);

Reader Function
---------------

LIBEMBER_API void emberAsyncReader_init(EmberAsyncReader *pThis);
LIBEMBER_API void emberAsyncReader_free(EmberAsyncReader *pThis);
LIBEMBER_API void emberAsyncReader_readByte(EmberAsyncReader *pThis, byte b);
LIBEMBER_API void emberAsyncReader_readBytes(EmberAsyncReader *pThis, const byte *pBytes, int count);
LIBEMBER_API void emberAsyncReader_reset(EmberAsyncReader *pThis);


Ember Framing
=============

LIBEMBER_API void berFramingOutput_init(BerFramingOutput *pThis, byte *pMemory, unsigned int size, byte slotId, byte dtd, const byte *pAppBytes, byte appBytesCount);
LIBEMBER_API void berFramingOutput_initWithoutEscaping(BerFramingOutput *pThis, byte *pMemory, unsigned int size, byte slotId, byte dtd, const byte *pAppBytes, byte appBytesCount);
LIBEMBER_API void berFramingOutput_writeHeader(BerFramingOutput *pThis, EmberFramingFlags flags);
LIBEMBER_API unsigned int berFramingOutput_finish(BerFramingOutput *pThis);

Framing Utilities
-----------------

LIBEMBER_API unsigned int emberFraming_writeKeepAliveRequest(byte *pBuffer, unsigned int size, byte slotId);
LIBEMBER_API unsigned int emberFraming_writeKeepAliveResponse(byte *pBuffer, unsigned int size, byte slotId);
LIBEMBER_API unsigned int emberFraming_writeKeepAliveRequestWithoutEscaping(byte *pBuffer, unsigned int size, byte slotId);
LIBEMBER_API unsigned int emberFraming_writeKeepAliveResponseWithoutEscaping(byte *pBuffer, unsigned int size, byte slotId);

Framing Reader
--------------
LIBEMBER_API void emberFramingReader_init(EmberFramingReader *pThis, byte *pMemory, unsigned int size, onPackageReceived_t onPackageReceived, voidptr state);
LIBEMBER_API void emberFramingReader_reset(EmberFramingReader *pThis);
LIBEMBER_API void emberFramingReader_readBytes(EmberFramingReader *pThis, const byte *pBytes, int count);


Glow
====

LIBEMBER_API void glowTemplate_free(GlowTemplate *pThis);
LIBEMBER_API void glowNode_free(GlowNode *pThis);
LIBEMBER_API void glowValue_copyFrom(GlowValue *pThis, const GlowValue *pSource);
LIBEMBER_API void glowValue_free(GlowValue *pThis);
LIBEMBER_API void glowParameter_free(GlowParameter *pThis);
LIBEMBER_API void glowInvocation_free(GlowInvocation *pThis);
LIBEMBER_API void glowCommand_free(GlowCommand *pThis);
LIBEMBER_API bool glowParametersLocation_isValid(const GlowParametersLocation *pThis);
LIBEMBER_API void glowMatrix_free(GlowMatrix *pThis);
LIBEMBER_API void glowConnection_free(GlowConnection *pThis);
LIBEMBER_API void glowTupleItemDescription_free(GlowTupleItemDescription *pThis);
LIBEMBER_API void glowFunction_free(GlowFunction *pThis);
LIBEMBER_API void glowInvocationResult_free(GlowInvocationResult *pThis);


Glow RX
=======

LIBEMBER_API void nonFramingGlowReader_init(NonFramingGlowReader *pThis, onNode_t onNode, onParameter_t onParameter, onCommand_t onCommand, onStreamEntry_t onStreamEntry, voidptr state);
LIBEMBER_API void nonFramingGlowReader_initEx(NonFramingGlowReader *pThis, onNode_t onNode, onParameter_t onParameter, onCommand_t onCommand, onStreamEntry_t onStreamEntry, onFunction_t onFunction, onTemplate_t onTemplate, voidptr state);
LIBEMBER_API void nonFramingGlowReader_free(NonFramingGlowReader *pThis);
LIBEMBER_API void nonFramingGlowReader_reset(NonFramingGlowReader *pThis);

Glow Reader
-----------
LIBEMBER_API void glowReader_init(GlowReader *pThis, onNode_t onNode, onParameter_t onParameter, onCommand_t onCommand, onStreamEntry_t onStreamEntry, voidptr state, byte *pRxBuffer, unsigned int rxBufferSize);
LIBEMBER_API void glowReader_initEx(GlowReader *pThis, onNode_t onNode, onParameter_t onParameter, onCommand_t onCommand, onStreamEntry_t onStreamEntry, onFunction_t onFunction, onTemplate_t onTemplate, voidptr state, byte *pRxBuffer, unsigned int rxBufferSize);
LIBEMBER_API void glowReader_free(GlowReader *pThis);
LIBEMBER_API void glowReader_readBytes(GlowReader *pThis, const byte *pBytes, int count);
LIBEMBER_API void glowReader_reset(GlowReader *pThis);

Glow Writer
-----------
LIBEMBER_API void glowOutput_init(GlowOutput *pThis, byte *pMemory, unsigned int size, byte slotId); 
LIBEMBER_API void glowOutput_initWithoutEscaping(GlowOutput *pThis, byte *pMemory, unsigned int size, byte slotId);LIBEMBER_API void glowOutput_beginPackage(GlowOutput *pThis, bool isLastPackage);
LIBEMBER_API void glowOutput_beginStreamPackage(GlowOutput *pThis, bool isLastPackage);
LIBEMBER_API unsigned int glowOutput_finishPackage(GlowOutput *pThis);

Writer
------
LIBEMBER_API void glow_writeQualifiedNode(GlowOutput *pOut, const GlowNode *pNode, GlowFieldFlags fields, const berint *pPath, int pathLength);
LIBEMBER_API void glow_writeQualifiedTemplate(GlowOutput *pOut, const GlowTemplate *pTemplate, GlowFieldFlags fields, void (*writeElement)(GlowOutput *pOut, const GlowTemplate *pTemplate, const BerTag * elementTag), const berint *pPath, int pathLength);
LIBEMBER_API void glow_writeTemplateElementNodeBegin(GlowOutput *pOut, const BerTag *tag, const GlowNode *pNode, GlowFieldFlags fields, berint number);
LIBEMBER_API void glow_writeTemplateElementNodeEnd(GlowOutput *pOut);
LIBEMBER_API void glow_writeTemplateElementNodeChildrenBegin(GlowOutput *pOut);
LIBEMBER_API void glow_writeTemplateElementNodeChildrenEnd(GlowOutput *pOut);
LIBEMBER_API void glow_writeTemplateElementNode(GlowOutput *pOut, const BerTag *tag, const GlowNode *pNode, GlowFieldFlags fields, berint number);
LIBEMBER_API void glow_writeTemplateElementParameter(GlowOutput *pOut, const BerTag *tag, const GlowParameter *pParameter, GlowFieldFlags fields, berint number);
LIBEMBER_API void glow_writeTemplateElementFunction(GlowOutput *pOut, const BerTag *tag, const GlowFunction *pFunction, GlowFieldFlags fields, berint number);
LIBEMBER_API void glow_writeQualifiedParameter(GlowOutput *pOut, const GlowParameter *pParameter, GlowFieldFlags fields, const berint *pPath, int pathLength);
LIBEMBER_API void glow_writeQualifiedCommand(GlowOutput *pOut, const GlowCommand *pCommand, const berint *pPath, int pathLength, GlowElementType parentType);
LIBEMBER_API void glow_writeStreamEntry(GlowOutput *pOut, const GlowStreamEntry *pEntry);
LIBEMBER_API void glow_writeQualifiedMatrix(GlowOutput *pOut, const GlowMatrix *pMatrix, GlowFieldFlags fields, const berint *pPath, int pathLength);
LIBEMBER_API void glow_writeTargetsPrefix(GlowOutput *pOut, const berint *pMatrixPath, int matrixPathLength); 
LIBEMBER_API void glow_writeTarget(GlowOutput *pOut, const GlowSignal *pTarget);
LIBEMBER_API void glow_writeTargetsSuffix(GlowOutput *pOut);
LIBEMBER_API void glow_writeSourcesPrefix(GlowOutput *pOut, const berint *pMatrixPath, int matrixPathLength);
LIBEMBER_API void glow_writeSource(GlowOutput *pOut, const GlowSignal *pSource);
LIBEMBER_API void glow_writeSourcesSuffix(GlowOutput *pOut);
LIBEMBER_API void glow_writeConnectionsPrefix(GlowOutput *pOut, const berint *pMatrixPath, int matrixPathLength);
LIBEMBER_API void glow_writeConnection(GlowOutput *pOut, const GlowConnection *pConnection);
LIBEMBER_API void glow_writeConnectionsSuffix(GlowOutput *pOut);
LIBEMBER_API void glow_writeQualifiedFunction(GlowOutput *pOut, const GlowFunction *pFunction, GlowFieldFlags fields, const berint *pPath, int pathLength);
LIBEMBER_API unsigned int glow_writeInvocationResultPackage(GlowOutput *pOut, const GlowInvocationResult *pRoot)



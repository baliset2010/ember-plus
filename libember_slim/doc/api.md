Consumer API
============

emberplus.h
```
typedef void (*throwError_t)(int error, pcstr pMessage);
typedef void (*failAssertion_t)(pcstr pFileName, int lineNumber);
typedef void *(*allocMemory_t)(size_t size);
typedef void (*freeMemory_t)(void *pMemory);

// ember のライブラリの初期化
LIBEMBER_API void ember_init(
	throwError_t throwError,
	failAssertion_t failAssertion,
	allocMemory_t allocMemory,
	freeMemory_t freeMemory
);
```

emberinternal.h (デフォルトのサンプル)
```
void throwError(int error, pcstr pMessage);
void failAssertion(pcstr pFileName, int lineNumber);
void *allocMemory(size_t size); 
void freeMemory(void *pMemory);
```


sample provider
---------------
* ember_init()
* initializePpmStreams() - ストリームの設定
	* GlowStreamEntry の値を設定
		* streamIdentifier
		* GlowValue
			* GlowParameterType (type - None/Integer/Real/String/Boolean/Trigger/Enum/Octets)
			* (union of above-typed data)  choice
* buildTree() - ツリーの作成
	* createNode
	* createGain
	* createVolume
	* createFormat
	* createStreamX
* socket server
	* handleClient(socket)




* glowParameter_free
* glowNode_free
* glowOutput_init
* glowOutput_beginPackage
* glow_writeQualifiedParameter
* glow_writeQualifiedNode
* glow_writeQualifiedParameter
* emberFraming_writeKeepAliveResponse
* glow_writeStreamEntry
* glowReader_init
* glowReader_readBytes
* glowReader_free
* ember_init
* sampleNode_free


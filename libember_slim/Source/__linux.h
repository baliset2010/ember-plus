#ifndef __linux_h
#define	__linux_h

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define	_stricmp	strcasecmp
#define	_strdup		strdup
#define	_getch		getchar
#define	_putch		putchar
#define	_kbhit		kbhit
#define	closesocket	close
#define	SOCKET		int
#define	SOCKET_ERROR	-1

extern int kbhit(void);
extern int itoa(int, char *, int);
extern int _itoa_s(int, char *, int, int);
#endif	//__linux_h


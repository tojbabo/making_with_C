#ifndef _FTP
#define _FTP

#include <WinSock2.h>
#include <io.h>
#include "Header.h"
#include "StringFunc.h"
#include "Paint.h"

#define PACKSZ 1000

typedef struct _filedata {
	int index;
	char* name;
	int size;
	struct _filedata* link;
}filedata;

void FTP_RUN();

// ��ƿ�κ�
SOCKET Ready(SOCKET sock, SOCKADDR_IN adr);
struct sockaddr_in AdrInit(char* ip, int port);
filedata* GetDirectory(char* path);
filedata GetFile(filedata* files_,int index_);
void ShowDirectory(filedata* files);
void FileData_Input(filedata** files, int index, char* name, int size);
char* File2String(filedata file);
char* FileExtension(filedata file_);

// �۽źκ�
void Sender();
SOCKET Sender_Connector();
void Sender_Data(SOCKET sock, char* path, char* filename);
void Sender_Directory(SOCKET sock, filedata* files);

// ���źκ�
void Receiver();
SOCKET Receiver_Connector();
void Receiver_Data(SOCKET sock, char* path, char* filename);
filedata* Receiver_Directory(SOCKET sock);

#endif // !1


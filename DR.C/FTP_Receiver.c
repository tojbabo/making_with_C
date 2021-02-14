#include "FTP.h"
#include"Paint.h"

void Receiver_Directory_Request(SOCKET sock_, char* path_, char* target_) {
	if (StringCompare(target_, "..") == COMPARE_SAME) {
		char* _temp = StringAdd1("!",path_);
		int* _index = StringFinder(_temp, "\\");
		
		
		if (_temp[StringLength(_temp)-1] == '\\') _index[0]--;

		_temp[_index[_index[0]]+1] = 0;

		send(sock_, _temp, StringLength(_temp), 0);
	
		autofree(_temp);
		autofree(_index);
	}
	else {
		char* _file = StringAdd1(path_, target_);
		char* _dir = StringAdd1(_file, "\\");
		char* _temp = StringAdd1("!", _dir);

		send(sock_, _temp, StringLength(_temp), 0);

		autofree(_dir);
		autofree(_temp);
		autofree(_file);
	}
}

void _Convert_FileToLine(filedata* files, Painter** core) {

	for (filedata* ptr = files; ptr != NULL; ptr = ptr->link) {
		char* a = File2String(*ptr);
		Painter_Input(*core, a);
	}
}

// 수신자(클라이언트) 몸체
void Receiver() {
	SOCKET sock = Receiver_Connector();
	char msg[PACKSZ];
	char* _mypath = StringCopy("C:\\Users\\OJJJ\\Desktop\\copy\\");
	char* _urpath=NULL;
	int len;

	int flag = access(_mypath, 0);
	//if (flag == -1) puts("경로없음");
	//else puts("its good");

	filedata* _files = NULL;
	send(sock, "!", 1, 0);

	while (1) {
		len = recv(sock, msg, PACKSZ, 0);
		msg[len] = 0;
		printf("msg is : %s[%d]\n", msg, len);
		if (msg[0] == '!') {
			autofree(_urpath);
			_urpath = StringCopy(msg + 1);
			_files = Receiver_Directory(sock);
		}

		Painter* _core = (Painter*)malloc(sizeof(Painter));
		_core->line = NULL;

		_Convert_FileToLine(_files, &_core);

		int select;
		while (1) {
			select = Curser_Run(*_core,_urpath);
			filedata target = GetFile(_files, select);


			if (target.size == 0) {
				// 디렉토리 선택한 경우
				Receiver_Directory_Request(sock, _urpath, target.name);
				break;
			}

			sprintf(msg, "@%d\n", select);

			send(sock, msg, StringLength(msg), 0);

			Receiver_Data(sock, _mypath, target.name);
		}
	}

	
}

// 수신자(클라이언트) 연결함수
SOCKET Receiver_Connector() {

	WSADATA wsa;
	WSAStartup(0x0202, &wsa);

	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN serv = AdrInit("127.0.0.1", 9001);

	if (connect(sock, (SOCKADDR*)&serv, sizeof(serv)) != 0) puts("Connect error!");

	return sock;
}

// 실제 데이터를 받는 함수
void Receiver_Data(SOCKET sock_, char* path_, char* filename_) {
	FILE* stream = NULL;

	char* _target = StringAdd1(path_, filename_);

	fopen_s(&stream, _target, "wb");

	int bufsz = PACKSZ;
	char* _buf = (char*)malloc(sizeof(char) * bufsz);

	int sz, filesz, cur;

	recv(sock_, _buf, PACKSZ, 0);
	sscanf(_buf, "%d", &filesz);
	//printf("file size is : %d\n", filesz);

	cur = 0;
	while (1) {
		sz = recv(sock_, _buf, PACKSZ, 0);
		//printf("receive data : %d ..... ", sz);

		if (sz == -1) {
			//printf("err, fin.\n");
			break;
		}
		else if (sz != bufsz) {
			if (sz + cur < filesz) {
				send(sock_, "no", StringLength("no"), 0);
				//printf("err retry (%d)\n", sz);
				continue;
			}
		}

		send(sock_, "go", StringLength("go"), 0);
		fwrite(_buf, 1, sz, stream);

		cur += sz;
		//printf("[%d/%d]\n", cur, filesz);

		if (cur > filesz) {
			//printf("▒▒▒▒data over▒▒▒▒\n");
			break;
		}
		else if (filesz == cur) {
			printf("recv complete ------> ");
			printf("%s%s\n", path_, filename_);
			break;
		}
	}
	free(_buf);
	free(_target);
	fclose(stream);
}

// 디렉토리 목록 받는 함수
filedata* Receiver_Directory(SOCKET sock_) {
	char msg[PACKSZ];
	int msgsz;
	filedata* _hptr = NULL;

	while (1) {
		msgsz = recv(sock_, msg, PACKSZ, 0);

		if (msgsz == -1)break;
		msg[msgsz] = 0;
		if (StringCompare(msg, "fin") == COMPARE_SAME) {
			puts("end msg recv");
			send(sock_, "bye", 3, 0);
			break;
		}

		char** _files = StringParser(msg, ",");

		// 0 : index
		// 1 : name
		// 2 : size
		int index = atoi(_files[0]);
		int size = atoi(_files[2]);
		FileData_Input(&_hptr, index, _files[1], size);

		msgsz = send(sock_, "go", 2, 0);

		if (msgsz == -1)break;

		matfree(_files);
	}
	return _hptr;
}

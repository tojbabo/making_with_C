#include "FTP.h"

// 송신자(서버) 몸체
void Sender() {
	SOCKET sock = Sender_Connector();
	char msg[PACKSZ];
	char* _path = StringCopy("C:\\Users\\"/*\\OJJJ\\Desktop\\"*/);
	int len;
	filedata* files_ = NULL;
	while (1) {
		len = recv(sock, msg, PACKSZ, 0);
		msg[len] = 0;
		printf("recv msg is : %s[%d]", msg,len);
		if (msg[0] == '!') {
			printf(" - directory send process start \n");
			if (len > 2) {
				autofree(_path);
				_path = StringCopy(msg + 1);
			}

			sprintf(msg, "!%s", _path);
			send(sock, msg, StringLength(msg), 0);
			printf("path is : %s\n", msg);

			files_ = GetDirectory(_path);
			Sender_Directory(sock, files_);
			
		}
		else if (msg[0] == '@') {
			int index;
			sscanf(msg, "@%d", &index);
			filedata* ptr = files_;
			for (int i = 1; i <= index; i++) {
				ptr = ptr->link;
			}
			printf(".... is %s", ptr->name);
			Sender_Data(sock, _path, ptr->name);;
		}
	}
}

// 송신자(서버) 연결함수
SOCKET Sender_Connector() {
	WSADATA wsa;
	WSAStartup(0x0202, &wsa);
	
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	SOCKADDR_IN adr = AdrInit("0.0.0.0", 9001);
	
	SOCKET clnt_sock = Ready(sock, adr);

	return clnt_sock;
}

// 실제 데이터 전송 하는 함수
void Sender_Data(SOCKET _sock, char* _path, char* _filename) {
	FILE* stream;
	printf("%s ", _filename);
	char* target_ = StringAdd1(_path, _filename);

	fopen_s(&stream, target_, "rb");

	int bufsz = PACKSZ;
	char* buf_ = (char*)malloc(sizeof(char) * bufsz);

	fseek(stream, 0, SEEK_END);
	int filesz = ftell(stream);

	printf("/ %d Byte", filesz);
	sprintf(buf_, "%d\0", filesz);
	send(_sock, buf_, StringLength(buf_), 0);

	fseek(stream, 0, SEEK_SET);

	int writebuf = 0;
	int readsz, msglen;

	char flag[PACKSZ];

	while (!feof(stream)) {
		int cur = ftell(stream);

		if (cur == filesz) break;
		else if (cur + bufsz > filesz) readsz = filesz - cur;
		else readsz = bufsz;

		fread(buf_, 1, readsz, stream);

		//printf("sending .... %d[%d/%d]", readsz, cur, filesz);
		while (1) {
			if ((msglen = send(_sock, buf_, readsz, 0)) == -1) {
				//puts("disconnected!! fin");
				break;
			}
			if ((msglen = recv(_sock, flag, PACKSZ, 0)) == -1) {
				//puts("disconnected!! fin");
				break;
			}
			flag[msglen] = 0;
			if (StringCompare(flag, "go") == COMPARE_SAME) {
				//puts("send success");
				break;
			}
			else if (StringCompare(flag, "no") == COMPARE_SAME) {
				//puts("send fail... retry");
				continue;
			}
			else {
				//puts("packet err - resending");
			}
		}

		if (msglen == -1) {
			break;
		}
		writebuf += readsz;
	}

	printf(" - send complete\n");
	free(buf_);
	free(target_);
	fclose(stream);
}

// 디렉토리 목록 전달하는 함수
void Sender_Directory(SOCKET _sock, filedata* _files){
	filedata* ptr = _files;
	int len;
	char msg[PACKSZ];
	char ans[PACKSZ];

	if (_files == NULL) {
		send(_sock, "*dir is null", strlen("*dir is null"), 0);
		return;
	}

	while (1)
	{
		if (ptr == NULL) {
			send(_sock, "fin", 3, 0);
			recv(_sock, msg, PACKSZ, 0);
			break;
		}

		sprintf(msg, "%d,%s,%d", ptr->index, ptr->name, ptr->size);

		while (1) {
			if (send(_sock, msg, StringLength(msg), 0) == -1) break;
			len = recv(_sock, ans, PACKSZ, 0);
			if (len == -1) break;

			ans[len] = 0;
			if (StringCompare(ans, "go") == COMPARE_SAME) break;
		}
		
		ptr = ptr->link;
	}
}

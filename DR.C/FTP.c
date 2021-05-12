#include "FTP.h"


void FTP_RUN() {
	/*int flag;
	puts("1. Receiver / 2. Sender");
	printf("Enter >> ");
	scanf("%d", &flag);*/
	//if (flag == 1) {
		Receiver();
	/*}
	else {
		Sender();
	}*/
}


SOCKET Ready(SOCKET sock_, SOCKADDR_IN adr_) {
	int adr_sz = sizeof(adr_);
	if (bind(sock_, (SOCKADDR*)&adr_, adr_sz) != 0) {
		printf("binding error\n");
		return -1;
	}

	if (listen(sock_, 10) != 0) {
		printf("listen error\n");
		return -1;
	}

	SOCKADDR_IN clnt;
	memset(&clnt, 0, sizeof(clnt));

	int clnt_sz = sizeof(clnt);
	SOCKET clnt_sock = accept(sock_, (SOCKADDR*)&clnt, &clnt_sz);

	return clnt_sock;
}

struct sockaddr_in AdrInit(char* ip_, int port_) {
	SOCKADDR_IN adr;

	memset(&adr, 0, sizeof(adr));

	adr.sin_addr.S_un.S_addr = inet_addr(ip_);
	adr.sin_family = AF_INET;
	adr.sin_port = htons(port_);

	return adr;
}

filedata* GetDirectory(char* path_) {
	struct _finddata_t target;
	intptr_t handle;
	char* _file;
	if (path_[StringLength(path_) - 1] != '\\') {
		_file = StringAdd1(path_, "\\*.*");
	}
	else {
		_file = StringAdd1(path_, "*.*");

	}
	handle = _findfirst(_file, &target);
	if (handle == -1)
	{
		printf("empty\n");
		return NULL;
	}

	int idx = 0;
	filedata* _hptr = NULL;

	while (1)
	{
		if (StringCompare(target.name, ".") != COMPARE_SAME) { 
			FileData_Input(&_hptr, idx++, target.name, target.size);
		}

		
		if (_findnext(handle, &target) == -1) break;
	}

	_findclose(handle);
	free(_file);
	return _hptr;
}

filedata GetFile(filedata* files_,int index_) {
	for (filedata* ptr = files_; ptr != NULL; ptr = ptr->link) {
		if (ptr->index == index_) {
			return *ptr;
		}
	}
}

int GetFileCount(filedata* files_) {
	filedata* ptr = files_;
	int count = 0;
	
	while (1) {
		if (ptr == NULL) return count;

		ptr = ptr->link;
		count++;
	}
}

void ShowDirectory(filedata* files_) {
	filedata* ptr = files_;
	while (1) {
		if (ptr == NULL) break;
		printf("%d / %s / %d\n", ptr->index, ptr->name, ptr->size);
		ptr = ptr->link;
	}
}

void FileData_Input(filedata** files_, int index_, char* name_, int size_) {
	filedata* ptr = *files_;

	while (1) {
		if (ptr == NULL) {
			ptr = (filedata*)malloc(sizeof(filedata));
			ptr->index = index_;
			ptr->size = size_;
			ptr->name = StringCopy(name_);
			ptr->link = NULL;

			*files_ = ptr;
			break;
		}
		else if (ptr->link == NULL) {
			ptr->link = (filedata*)malloc(sizeof(filedata));
			ptr = ptr->link;
			ptr->index = index_;
			ptr->size = size_;
			ptr->name = StringCopy(name_);
			ptr->link = NULL;
			break;
		}

		ptr = ptr->link;

	}
}

char* File2String(filedata file_) {
	// [  ] [1] filename | extension | size 
	char temp[100];
	char* _extension = FileExtension(file_);
	sprintf(temp, "%2d: | %16.16s | %6s | %-d",
		file_.index, file_.name, _extension, file_.size);
	
	char* _result = StringCopy(temp);

	autofree(_extension);
	return _result;
}

char* FileExtension(filedata file_) {
	int* _extensionidx = StringFinder(file_.name, ".");
	char* extension = "dir";

	if (file_.size != 0) {
		extension = file_.name + _extensionidx[_extensionidx[0]];
	}
	char* _result = StringCopy(extension);
	free(_extensionidx);

	return _result;
}



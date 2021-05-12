#include "Statics.h"
#include <stdio.h>
#include <stdlib.h>
#include "StringFunc.h"

char* GetValue(char* source, char* key) {
	char** ptr = StringParser(source, ":");
	if (StringCompare(ptr[0], key) == COMPARE_SAME) {
		return ptr[1];
	}
	return NULL;
}
void FileWrite(char* filename, char* data) {

	FILE* stream = NULL;

	fopen_s(&stream, filename, "a+");

	int len = fprintf(stream, "%s\n", data);

	printf("write data : %s/%d\n", data, len);

	fclose(stream);
}
void FileRead(char* filename, char* key) {

	FILE* stream = NULL;

	char data[100];

	fopen_s(&stream, filename, "r");

	int num;
	char* value;

	while (fgets(data, 100, stream)) {

		value = GetValue(data,key);

		if (value == NULL) continue;

		printf("value is :[%s]%s\n", key, value);
		break;
	}

	fclose(stream);
}


void Statics_Read(Statics* Statics, char* path) {
	FileWrite("test2.txt","key:good");
	FileRead("test2.txt","key");
	/*FILE* stream=NULL;
	
	char data[100];

	printf("file read : %s\n", path);

	fopen_s(&stream, path, "r");

	if (stream == NULL) {
		printf("error");
		return;
	}
	
	int num;
	while (!feof(stream)) {
		num = fread(data, 1, 100, stream);
		printf("%s , %d\n", data,num);
	}

	fclose(stream);*/
}
void Statics_Write(Statics* Statics, char* path) {

}
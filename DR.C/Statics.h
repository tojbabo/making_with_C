#ifndef _Statics
#define _Statics

typedef struct _Statics {
	int num;
}Statics;

void Statics_Read(Statics* Statics, char* path);
void Statics_Write(Statics* Statics, char* path);


#endif
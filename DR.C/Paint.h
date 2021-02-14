#ifndef _Paint
#define _Paint

#include"Header.h"
#include"StringFunc.h"
#include <windows.h>
#include <io.h>

typedef struct _Painter {
	struct _Line* line;
}Painter;

typedef struct _Line {
	char* data;
	struct _Line* next;
}Line;

void Painting(Painter Paint_, char* head_);

void Painter_Input(Painter* Paint_, char* data_);

Line* Line_Get(Painter Paint_, int index);

int Curser_Run(Painter Paint_,char* title_);

#endif
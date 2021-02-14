#include"Paint.h"

int _LineCount(Painter p) {
	Line* ptr = p.line;
	if (ptr == NULL) return 0;

	int count = 0;
	while (1) {
		if (ptr == NULL) return count;

		ptr = ptr->next;
		count++;
	}
}

void _Moving(int x_, int y_) {
	static x = 1;
	static y = 1;

	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("  ");

	pos.X = x_;
	pos.Y = y_;

	x = x_;
	y = y_;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("●");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void _RemoveCursur() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void PaintLine(Painter Paint_, int index) {
	COORD pos = { 0,2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	Line* line = Paint_.line;
	for (int i = 0; i < index; i++) {
		line = line->next;
	}

	for (int i = 0; i < 10; i++) {
		if (line == NULL)puts("");
		else {
			printf("[  ] %-75s\n", line->data);
			line = line->next;
		}
	}
}

void Painting(Painter Paint_, char* head_) {
	system("cls");
	printf("<<%s>>\n", head_);
	printf("파일 및 폴더 선택==============================\n");

	
	PaintLine(Paint_, 0);

	printf("\n↑,↓ : 이동/ Enter: 선택--------------------\n");
	//printf("123456789123456789123456789123456789123456789");
}


void Painter_Input(Painter* Paint_, char* data_) {
	Line* target = Paint_->line;
	Line* pre = NULL;

	while (1) {
		if (target == NULL) {
			target = (Line*)malloc(sizeof(Line));
			target->data = StringCopy(data_);
			target->next = NULL;

			if (pre == NULL) {
				Paint_->line = target;
			}
			else {
				pre->next = target;
			}
			break;
		}

		pre = target;
		target = target->next;
	}
}

Line* Line_Get(Painter Paint_, int index) {
	Line* ptr = Paint_.line;
	for (int i = 0; i < index; i++) {
		ptr = ptr->next;
	}
	return ptr;
}

int Curser_Run(Painter Paint_,char* title_) {
	int key;
	int x = 1, y = 2;
	int selected = 0;

	Painting(Paint_,title_);
	int linenum = _LineCount(Paint_);
	_RemoveCursur();
	_Moving(x, y);

	while (1) {
		key = getch();
		// 방향키 & 특수키
		if (key == 224)
		{
			key = getch();
			switch (key) {
			case 72:        // 상
				if (y > 2) {
					y--;
					selected--;
					_Moving(x, y);
				}
				else if (selected > 0) {
					selected--;
					PaintLine(Paint_, selected);

					_Moving(x, y);
				}
				break;
			case 75:        // 좌
				// Cursur_Mover(x, y);
				break;
			case 77:        // 우
				// Cursur_Mover(x, y);
				break;
			case 80:        // 하
				if (y<=10) {
					y++;
					selected++;
					_Moving(x, y);
				}
				else if (selected < linenum + 1) {
					selected++;
					PaintLine(Paint_, selected - 9);


					_Moving(x, y);
				}
				break;
			default:
				//puts("그 외");
				break;
			}
		}

		// 엔터
		else if (key == 13) {
			Line* target = Line_Get(Paint_, selected);
			
			int result;
			sscanf(target->data, "%d", &result);

			COORD pos = { 0,linenum + 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

			return result;
		}
	}
}


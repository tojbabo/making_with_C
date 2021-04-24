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

	// 이전 좌표에 내용 지움
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("  ");

	// 좌표 새로 지정
	pos.X = x_;
	pos.Y = y_;

	// 현 좌표 저장
	x = x_;
	y = y_;

	// 현 좌표에 내용 그리기
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("●");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void _RemoveCursur() {
	// 껌뻑껌뻑 커서 지움
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void PaintLine(Painter Paint_, int index) {
	// 커서 좌표 이동
	COORD pos = { 0,2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	Line* line = Paint_.line;

	// 출력될 라인의 시작 인덱스로 포인터 이동
	for (int i = 0; i < index; i++) {
		line = line->next;
	}

	// 시작 인덱스부터 10개 출력
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

	printf("\n↑,↓ : 이동/ Space: 선택--------------------\n");
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
				// y가 이동할 수 있는 범위
				// 2 <= y <= 11
				
				if (selected > 0) {
					selected--;
					if (y > 2)
						y--;
					else
						PaintLine(Paint_, selected);

					_Moving(x, y);
				}
				break;
			case 75:		// 좌
				// Cursur_Mover(x, y);
				break;
			case 77:        // 우
				// Cursur_Mover(x, y);
				break;
			case 80:        // 하
				// linenum : 실제 수 [1부터 시작]
				// selected : index [0부터 시작]
				if (selected < linenum - 1) {
					selected++;

					if (y < 11)
						y++;
					else
						PaintLine(Paint_, selected - 9);

					_Moving(x, y);
				}
				break;
			case 40:		// space
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
			printf("%s", target->data);
			COORD pos = { 0,linenum + 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

			return result;
		}
	}
}


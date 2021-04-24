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

	// ���� ��ǥ�� ���� ����
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("  ");

	// ��ǥ ���� ����
	pos.X = x_;
	pos.Y = y_;

	// �� ��ǥ ����
	x = x_;
	y = y_;

	// �� ��ǥ�� ���� �׸���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void _RemoveCursur() {
	// �������� Ŀ�� ����
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void PaintLine(Painter Paint_, int index) {
	// Ŀ�� ��ǥ �̵�
	COORD pos = { 0,2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	Line* line = Paint_.line;

	// ��µ� ������ ���� �ε����� ������ �̵�
	for (int i = 0; i < index; i++) {
		line = line->next;
	}

	// ���� �ε������� 10�� ���
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
	printf("���� �� ���� ����==============================\n");

	
	PaintLine(Paint_, 0);

	printf("\n��,�� : �̵�/ Space: ����--------------------\n");
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
		// ����Ű & Ư��Ű
		if (key == 224)
		{
			key = getch();
			switch (key) {
			case 72:        // ��
				// y�� �̵��� �� �ִ� ����
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
			case 75:		// ��
				// Cursur_Mover(x, y);
				break;
			case 77:        // ��
				// Cursur_Mover(x, y);
				break;
			case 80:        // ��
				// linenum : ���� �� [1���� ����]
				// selected : index [0���� ����]
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
				//puts("�� ��");
				break;
			}
		}

		// ����
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


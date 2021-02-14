#ifndef _List
#define _List

#include"Header.h"
#include"Utility.h"

typedef struct NODE {
    char* data;
    struct NODE* link;
}node;
typedef struct LIST {
    int count;
    struct NODE* head;
}list;

// �ʱ�ȭ �Լ�
void LIST_Init(list* head);

// ����Ʈ �����ֱ� �Լ�
void LIST_Show(list head);

// ����Ʈ ������ �߰� �Լ� (�� �ڿ� �߰�)
int LIST_Add(list* head, char* data);

// ����Ʈ ��ü ������ ���� �Լ�
int LIST_Release(list* head);

// ����Ʈ Ư�� ��ġ�� ������ �߰� �Լ� (index - ���ο� �������� �ε���)
int LIST_Insert(list* head, char* data, int index);

// ����Ʈ�� Ư�� ��ġ�� ������ ���� �Լ� (�ε��� ���� �����ʹ� �ϳ��� �����)
int LIST_Delete(list* head, int index);

#endif // !1

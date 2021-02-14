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

// 초기화 함수
void LIST_Init(list* head);

// 리스트 보여주기 함수
void LIST_Show(list head);

// 리스트 데이터 추가 함수 (맨 뒤에 추가)
int LIST_Add(list* head, char* data);

// 리스트 전체 데이터 삭제 함수
int LIST_Release(list* head);

// 리스트 특정 위치에 데이터 추가 함수 (index - 새로운 데이터의 인덱스)
int LIST_Insert(list* head, char* data, int index);

// 리스트의 특정 위치의 데이터 삭제 함수 (인덱스 이후 데이터는 하나씩 당겨짐)
int LIST_Delete(list* head, int index);

#endif // !1

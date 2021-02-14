#ifndef _Dictionary
#define _Dictionary

#include"Header.h"
#include"Utility.h"
#include"StringFunc.h"


typedef struct _DICTIONARY {
    char* key;
    void* value;
    struct _DICTIONARY* link;

}_dictionary;

typedef struct DICTIONARY {
    int count;
    struct _DICTIONARY* head;
}dictionary;

// 초기화 함수
void DICTIONARY_Init(dictionary* dic);

// 출력 함수
void DICTIONARY_Show(dictionary dic);

// 데이터 추가 함수
int DICTIONARY_Add(dictionary* head, char* key, void* value);

// 데이터 삭제 함수
int DICTIONARY_Delete(dictionary* head, char* key);

// 데이터 탐색 함수
void* DICTIONARY_Search(dictionary head, char* key);

#endif // !_Dictionary
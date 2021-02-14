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

// �ʱ�ȭ �Լ�
void DICTIONARY_Init(dictionary* dic);

// ��� �Լ�
void DICTIONARY_Show(dictionary dic);

// ������ �߰� �Լ�
int DICTIONARY_Add(dictionary* head, char* key, void* value);

// ������ ���� �Լ�
int DICTIONARY_Delete(dictionary* head, char* key);

// ������ Ž�� �Լ�
void* DICTIONARY_Search(dictionary head, char* key);

#endif // !_Dictionary
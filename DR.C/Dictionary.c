#include"Dictionary.h"

#define COMPARE_ERR -2
#define COMPARE_SRC -1   // source가 더 작음
#define COMPARE_SAME 0   // 두 문자열이 같음
#define COMPARE_DST 1    // destination가 더 작음

// 초기화 함수
void DICTIONARY_Init(dictionary* dic) {
    dic->count = 0;
    dic->head = NULL;
}

// 출력 함수
void DICTIONARY_Show(dictionary dic) {
    _dictionary* temp = dic.head;
    int i = 0;

    printf("--- total count : %d\n", dic.count);
    while (temp != NULL) {
        printf("[%d] %s\n", i, temp->key);
        i++; temp = temp->link;
    }
}

// 데이터 추가 함수
int DICTIONARY_Add(dictionary* head, char* key, void* value) {
    _dictionary* temp = head->head;
    while (1) {
        // 헤더가 비었을 때
        if (/*head->count == 0*/temp == NULL) {
            temp = (_dictionary*)malloc(sizeof(_dictionary));
            temp->key = key;
            temp->value = value;
            temp->link = NULL;
            head->head = temp;
            break;
        }

        // 현재 노드의 키가 새로 추가하려는 키와 같을 때
        else if (StringCompare(temp->key, key) == COMPARE_SAME) {
            return false;
        }

        // 헤더(현재 노드)가 마지막 일때
        else if (temp->link == NULL) {

            temp->link = (_dictionary*)malloc(sizeof(_dictionary));
            temp->link->key = key;
            temp->link->value = value;
            temp->link->link = NULL;
            break;
        }

        // 다음 노드가 존재할 때
        else {
            temp = temp->link;
        }
    }
    head->count++;
    return true;
}

// 데이터 삭제 함수
int DICTIONARY_Delete(dictionary* head, char* key) {

    _dictionary* ptr = head->head;
    _dictionary* pre = NULL;


    while (true) {
        if (ptr == NULL) return false;
        else if (StringCompare(ptr->key, key) == COMPARE_SAME) break;

        pre = ptr;
        ptr = ptr->link;
    }

    if (pre == NULL) {
        autofree(ptr);
        head->head = NULL;
    }
    else {
        pre->link = ptr->link;
        autofree(ptr);
    }
    head->count--;
    return true;
}

// 데이터 탐색 함수
void* DICTIONARY_Search(dictionary head, char* key) {
    _dictionary* temp = head.head;
    while (1) {
        if (temp == NULL) return NULL;

        if (StringCompare(temp->key, key) == COMPARE_SAME) return temp->value;

        temp = temp->link;

    }
}


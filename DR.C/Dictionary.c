#include"Dictionary.h"

#define COMPARE_ERR -2
#define COMPARE_SRC -1   // source�� �� ����
#define COMPARE_SAME 0   // �� ���ڿ��� ����
#define COMPARE_DST 1    // destination�� �� ����

// �ʱ�ȭ �Լ�
void DICTIONARY_Init(dictionary* dic) {
    dic->count = 0;
    dic->head = NULL;
}

// ��� �Լ�
void DICTIONARY_Show(dictionary dic) {
    _dictionary* temp = dic.head;
    int i = 0;

    printf("--- total count : %d\n", dic.count);
    while (temp != NULL) {
        printf("[%d] %s\n", i, temp->key);
        i++; temp = temp->link;
    }
}

// ������ �߰� �Լ�
int DICTIONARY_Add(dictionary* head, char* key, void* value) {
    _dictionary* temp = head->head;
    while (1) {
        // ����� ����� ��
        if (/*head->count == 0*/temp == NULL) {
            temp = (_dictionary*)malloc(sizeof(_dictionary));
            temp->key = key;
            temp->value = value;
            temp->link = NULL;
            head->head = temp;
            break;
        }

        // ���� ����� Ű�� ���� �߰��Ϸ��� Ű�� ���� ��
        else if (StringCompare(temp->key, key) == COMPARE_SAME) {
            return false;
        }

        // ���(���� ���)�� ������ �϶�
        else if (temp->link == NULL) {

            temp->link = (_dictionary*)malloc(sizeof(_dictionary));
            temp->link->key = key;
            temp->link->value = value;
            temp->link->link = NULL;
            break;
        }

        // ���� ��尡 ������ ��
        else {
            temp = temp->link;
        }
    }
    head->count++;
    return true;
}

// ������ ���� �Լ�
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

// ������ Ž�� �Լ�
void* DICTIONARY_Search(dictionary head, char* key) {
    _dictionary* temp = head.head;
    while (1) {
        if (temp == NULL) return NULL;

        if (StringCompare(temp->key, key) == COMPARE_SAME) return temp->value;

        temp = temp->link;

    }
}


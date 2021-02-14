#include"List.h"

void LIST_Init(list* head) {
    head->count = 0;
    head->head = NULL;
}

void LIST_Show(list head) {
    node* temp = head.head;
    int i = 0;

    printf("--- total count : %d\n", head.count);
    while (temp != NULL) {
        printf("%d - %s\n", i, temp->data);
        i++; temp = temp->link;
    }
}

int LIST_Add(list* head, char* data) {
    node* temp = head->head;

    while (1) {
        // 헤더가 비었을 때
        if (head->count == 0/*temp == NULL*/) {
            temp = (node*)malloc(sizeof(node));
            temp->data = data;
            temp->link = NULL;
            head->head = temp;
            break;
        }

        // 헤더(현재 노드)가 마지막 일때
        else if (temp->link == NULL) {
            temp->link = (node*)malloc(sizeof(node));
            temp->link->data = data;
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

int LIST_Release(list* head) {
    if (head->count == 0 /*head->body ==NULL*/) return true;
    node* ptr = head->head;
    node* next = ptr->link;

    while (1) {
        printf("release %s\n", ptr->data);

        autofree(ptr);

        if (next == NULL) break;

        ptr = next;
        next = ptr->link;
    }
    head->count = 0;
    head->head = NULL;
    return true;
}

int LIST_Insert(list* head, char* data, int index) {

    if (index > head->count) return false;

    node* ptr = head->head;
    node* pre = NULL;
    for (int i = 0; i < index; i++) {
        pre = ptr;
        ptr = ptr->link;
    }

    if (pre == NULL) {
        pre = (node*)malloc(sizeof(node));
        pre->data = data;
        pre->link = ptr;
        head->head = pre;
    }
    else {
        pre->link = (node*)malloc(sizeof(node));
        pre->link->data = data;
        pre->link->link = ptr;
    }

    head->count++;
    return true;
}

int LIST_Delete(list* head, int index) {
    node* ptr = head->head;
    node* pre = NULL;

    if (index > head->count) return false;
    else if (ptr == NULL) return false;

    for (int i = 0; i < index; i++) {
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

    head->count++;
    return true;
}
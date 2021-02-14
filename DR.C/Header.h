#ifndef _Header
#define _Header

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

#endif // !1


//void f() {
//    static FILE* stream = NULL;
//    if (stream == NULL) {
//        printf("������ ���ڽ��ϴ�.\n");
//        fopen_s(&stream, "test.log", "wt");
//    }
//    fwrite("asdfg\n", 1, StringLength("asdfg\n"), stream);
//}

//typedef struct DIC {
//    char* key;
//    char* val;
//    struct DIC* next;
//}DIC;
//int DIC_add(DIC** head, char* key, char* val) {
//    DIC* temp = *head;
//    if (temp == NULL) {
//        temp = (DIC*)malloc(sizeof(DIC));
//        temp->key = StringAdd1("", key);
//        temp->val = StringAdd1("", val); 
//        temp->next = NULL;
//        *head = temp;
//    }
//    else if (temp->next == NULL) {
//        temp->next = (DIC*)malloc(sizeof(DIC));
//        temp->next->key = StringAdd1("", key); 
//        temp->next->val = StringAdd1("", val); 
//        temp->next->next = NULL;
//    }
//    else {
//        DIC_add(&(temp->next), key, val);
//    }
//}
//char* DIC_find(DIC* list, char *key) {
//    while (1) {
//        if (list == NULL) return NULL;
//
//        if (StringCompare(list->key, key) == COMPARE_SAME) return  list->val;
//
//        list = list->next;
//    }
//}
//void DIC_show(DIC* list) {
//    DIC* ptr = list;
//    printf("show strat\n");
//    for(int i =0 ;;i++){
//        if (ptr == NULL) break;
//        
//        printf("[%d] %s : %s\n", i, ptr->key, ptr->val);
//        ptr = ptr->next;
//    }
//    
//}
//
//typedef struct Station {
//    char* name;
//    int flag;
//    struct Station* next;
//}Station;
//void Station_add(Station** head, char* data) {
//    Station* ptr = *head;
//    if (ptr == NULL) {
//        *head = (Station*)malloc(sizeof(Station));
//        (*head)->name = StringAdd1("",data);
//        (*head)->flag = 0;
//        (*head)->next = NULL;
//    }
//    else if (StringCompare(ptr->name, data) == COMPARE_SAME) {
//    }
//    else if (ptr->next == NULL) {
//        ptr->next = (Station*)malloc(sizeof(Station));
//        ptr->next->name = StringAdd1("", data);
//        ptr->next->flag = 0;
//        ptr->next->next= NULL;
//    }
//    else {
//        Station_add(&(ptr->next), data);
//    }
//}
//void Station_show(Station* list) {
//    int i=1;
//    printf("station show start\n");
//    while (1) {
//        if (list == NULL) break;
//        printf("[%d/%d] %s\n", i++, list->flag, list->name);
//        list = list->next;
//    }
//}
//int Station_find(Station* list,char* target) {
//    int i =0;
//    while (1) {
//        if (list == NULL) break;
//        
//        if (StringCompare(list->name, target) == COMPARE_SAME) return i;
//        
//        list = list->next;
//        i++;
//    }
//    return -1;
//}
//#define READSIZE 4000
//
//int main() {
//    int RUN = 1;
//
//    char FILENAME[100];
//
//    // ������ �о �����ϴ� �κ�
//
//    Station* stationList = NULL;
//    if (RUN) {
//        FILE* stream;
//        char line[READSIZE];
//        printf("Station info  .....");
//        fopen_s(&stream, "info.csv", "rt");
//
//
//        fgets(line, READSIZE, stream);
//        char** column = StringParser(line, ",");
//        int idx_name;
//        for (int i = 0; column[i] != NULL; i++) {
//            if (StringCompare(column[i], "STATION_NAME") == 0) idx_name = i;
//            free(column[i]);
//        }
//        free(column);
//        while (fgets(line, READSIZE, stream) != NULL) {
//            char** data = StringParser(line, ",");
//
//            Station_add(&stationList, data[idx_name]);
//
//            _free(data);
//        }
//        fclose(stream);
//        printf("OK\n");
//    }
//    
//    // �ڵ� ��ȯ�� ����� �κ�  
//    DIC* CodeList = NULL;
//    if (RUN) {
//        FILE* stream;
//        printf("Code info     .....");
//        char line[READSIZE];
//
//        fopen_s(&stream, "transform.csv", "rt");
//        while (fgets(line, READSIZE, stream) != NULL) {
//            char** data = StringParser(line, ",");
//            if(StringCompare("-",data[0])!=COMPARE_SAME)
//                DIC_add(&CodeList, data[0], data[1]);
//
//            _free(data);
//        }
//        fclose(stream);
//        printf("OK\n");
//    }
//    
//
//    // �ٲ� ���� �о ��ȯ�ϴ� �κ�
//    DIC* list = NULL;
//    DIC_add(&list, "����", "����");
//    DIC_add(&list, "�ø��Ȱ���(�ѱ�ü��)", "�ø��Ȱ���");
//    DIC_add(&list, "�̾ƻ�Ÿ�", "�̾ƻ�Ÿ�");
//    DIC_add(&list, "��õ", "��ǻ���");
//    DIC_add(&list, "����(����)", "����");
//    DIC_add(&list, "����S", "����");
//    DIC_add(&list, "����E", "����1");
//    if (RUN) {
//        FILE* stream = NULL;
//        FILE* newstream = NULL;
//
//        printf("input file >> ");
//        while (1) {
//            gets_s(FILENAME, 100);
//            //scanf_s("%s", FILENAME, 100);
//            if (fopen_s(&stream, FILENAME, "rt") == 0) {
//                printf("File load     .....OK\n");
//                break;
//            }
//            printf("error!! again >> ");
//        }
//
//        char line[READSIZE];
//
//        fgets(line, READSIZE, stream);
//        char** column = StringParser(line, ",");
//        int idx_startNum, idx_start, idx_direct, idx_type, idx_end, idx_endNum, idx_link, idx_linkNum;
//        idx_startNum = idx_start = idx_direct = idx_type = idx_end = idx_endNum = idx_link = idx_linkNum = -1;
//
//        for (int i = 0; column[i] != NULL; i++) {
//            if (StringCompare(column[i], "����") == COMPARE_SAME || StringCompare(column[i], "��߿���") == COMPARE_SAME) idx_start = i;
//            else if (StringCompare(column[i], "����ȣ") == COMPARE_SAME || StringCompare(column[i], "��߿�") == COMPARE_SAME) idx_startNum = i;
//            else if (StringCompare(column[i], "���ϱ���") == COMPARE_SAME) idx_direct = i;
//            else if (StringCompare(column[i], "����") == COMPARE_SAME) idx_type = i;
//            else if (StringCompare(column[i], "��������") == COMPARE_SAME) idx_end = i;
//            else if (StringCompare(column[i], "������") == COMPARE_SAME) idx_endNum = i;
//            else if (StringCompare(column[i], "Link") == COMPARE_SAME) idx_link = i;
//            else if (StringCompare(column[i], "Link����") == COMPARE_SAME) idx_linkNum = i;
//
//            // ȯ�������� �����ؾ��ϴ��� Ȯ��
//            free(column[i]);
//        }
//        free(column);
//        char* fname = StringAdd1("_", FILENAME);
//
//        fopen_s(&newstream, fname, "wt");
//        fprintf(newstream, "%s", line);
//
//        int i = 2;
//        char* garbage;
//        while (fgets(line, READSIZE, stream) != NULL) {
//            char** data = StringParser(line, ",");
//            char* val;
//
//            // �о�� ���뿡�� ��ųʸ��� �ִ´�� ���� ���� ���� ����
//            if (idx_start != -1) {
//                val = DIC_find(list, data[idx_start]);
//                if (val != NULL) {
//                    garbage = data[idx_start];
//                    printf("[%d] ����: %s�� -> %s�� [��/��߿�]\n", i, data[idx_start], val);
//                    data[idx_start] = StringSwitcher(data[idx_start], data[idx_start], val);
//                    free(garbage);
//                }
//
//                // ����(INF0)�� ���� ������ ���� �Ѱܹ�����
//                if (Station_find(stationList, data[idx_start]) == -1) {
//                    printf("[%d] ����: %s�� - �� ���� ����[��/��߿�]\n", i, data[idx_start]);
//                    _free(data);
//                    i++;
//                    continue;
//                }
//            }
//            // �� �ڵ� ����
//            if (idx_startNum != -1) {
//                val = DIC_find(CodeList, data[idx_startNum]);
//                if (val != NULL) {
//                    garbage = data[idx_startNum];
//                    //printf("[%d] ����: %s -> %s\n", i, data[idx_code], val);
//                    data[idx_startNum] = StringSwitcher(data[idx_startNum], data[idx_startNum], val);
//                    free(garbage);
//                }
//                else {
//                    printf("[%d] üũ: %s[%s] �ڵ� ���� ���� -> ����[��/��߿�]\n", i, data[idx_start], data[idx_startNum]);
//                    _free(data);
//                    i++;
//                    continue;
//                }
//            }
//
//            if (idx_end != -1) {
//                val = DIC_find(list, data[idx_end]);
//                if (val != NULL) {
//                    garbage = data[idx_end];
//                    printf("[%d] ����: %s�� -> %s�� [������]\n", i, data[idx_end], val);
//                    data[idx_end] = StringSwitcher(data[idx_end], data[idx_end], val);
//                    free(garbage);
//                }
//
//                // ����(INF0)�� ���� ������ ���� �Ѱܹ�����
//                if (Station_find(stationList, data[idx_end]) == -1) {
//                    printf("[%d] ����: %s�� - �� ���� ���� [������]\n", i, data[idx_end]);
//                    _free(data);
//                    i++;
//                    continue;
//                }
//
//            }
//            // �� �ڵ� ����
//            if (idx_endNum != -1) {
//                val = DIC_find(CodeList, data[idx_endNum]);
//                if (val != NULL) {
//                    garbage = data[idx_endNum];
//                    //printf("[%d] ����: %s -> %s\n", i, data[idx_code], val);
//                    data[idx_endNum] = StringSwitcher(data[idx_endNum], data[idx_endNum], val);
//                    free(garbage);
//                }
//                else {
//                    printf("[%d] üũ: %s[%s] �ڵ� ���� ���� -> ���� [������]\n", i, data[idx_end], data[idx_endNum]);
//                    _free(data);
//                    i++;
//                    continue;
//                }
//
//            }
//            // ��/��(��/��)�� ����
//            if (idx_direct != -1) {
//                val = data[idx_direct];
//                if (StringCompare(val, "��") == COMPARE_SAME || StringCompare(val, "����") == COMPARE_SAME) {
//                    //printf("[%d] ����: %s -> %s\n", i, val, "1");
//                    data[idx_direct] = StringSwitcher(data[idx_direct], data[idx_direct], "1");
//                    free(val);
//                }
//                else if (StringCompare(val, "�ϼ�") == COMPARE_SAME || StringCompare(val, "�ܼ�") == COMPARE_SAME) {
//                    //printf("[%d] ����: %s -> %s\n", i, val, "2");
//                    data[idx_direct] = StringSwitcher(data[idx_direct], data[idx_direct], "2");
//                    free(val);
//                }
//
//            }
//            // ��/��/�� �� ����
//            if (idx_type != -1) {
//                val = data[idx_type];
//                if (StringCompare(val, "��") == COMPARE_SAME || StringCompare(val, "����") == COMPARE_SAME) {
//                    //printf("[%d] ����: %s -> %s\n", i, val, "1");
//                    data[idx_type] = StringSwitcher(data[idx_type], data[idx_type], "1");
//                    free(val);
//                }
//                else if (StringCompare(val, "�ϼ�") == COMPARE_SAME || StringCompare(val, "�ܼ�") == COMPARE_SAME) {
//                    //printf("[%d] ����: %s -> %s\n", i, val, "2");
//                    data[idx_type] = StringSwitcher(data[idx_type], data[idx_type], "2");
//                    free(val);
//                }
//                else if (StringCompare(val, "����") == COMPARE_SAME || StringCompare(val, "�����ο�") == COMPARE_SAME) {
//                    //printf("[%d] ����: %s -> %s\n", i, val, "2");
//                    data[idx_type] = StringSwitcher(data[idx_type], data[idx_type], "1");
//                    free(val);
//                }
//                else if (StringCompare(val, "����") == COMPARE_SAME || StringCompare(val, "�����ο�") == COMPARE_SAME) {
//                    //printf("[%d] ����: %s -> %s\n", i, val, "2");
//                    data[idx_type] = StringSwitcher(data[idx_type], data[idx_type], "2");
//                    free(val);
//                }
//                else if (StringCompare(val, "����") == COMPARE_SAME || StringCompare(val, "�����ο�") == COMPARE_SAME) {
//                    //printf("[%d] ����: %s -> %s\n", i, val, "2");
//                    data[idx_type] = StringSwitcher(data[idx_type], data[idx_type], "3");
//                    free(val);
//                }
//
//            }
//
//            if (idx_link != 1 && idx_linkNum != -1) {
//                char** linkdata = StringParser(data[idx_link], "_");
//                char** linkname = StringParser(data[idx_linkNum], "_");
//
//                val = DIC_find(CodeList, linkdata[0]);
//                if (val != NULL) {
//                    garbage = linkdata[0];
//                    linkdata[0] = StringSwitcher(linkdata[0], linkdata[0], val);
//                    free(garbage);
//                }
//                val = DIC_find(CodeList, linkdata[1]);
//                if (val != NULL) {
//                    garbage = linkdata[1];
//                    linkdata[1] = StringSwitcher(linkdata[1], linkdata[1], val);
//                    free(garbage);
//                }
//                val = DIC_find(list, linkname[0]);
//                if (val != NULL) {
//                    garbage = linkname[0];
//                    linkname[0] = StringSwitcher(linkname[0], linkname[0], val);
//                    free(garbage);
//                }
//                val = DIC_find(list, linkname[1]);
//                if (val != NULL) {
//                    garbage = linkname[1];
//                    linkname[1] = StringSwitcher(linkname[1], linkname[1], val);
//                    free(garbage);
//                }
//
//
//                char* datatemp = StringAdd(linkdata, "_");
//
//                garbage = data[idx_link];
//                printf("[%d] ����: (Link) %s -> %s\n", i, data[idx_link], datatemp);
//                data[idx_link] = StringSwitcher(data[idx_link], data[idx_link], datatemp);
//                free(garbage);
//
//                if (StringCompare(linkdata[0], "440") == COMPARE_SAME) {
//                    garbage = linkname[0];
//                    //printf("[%d] ����: %s�� -> %s��[��/��߿�]\n", i, data[idx_start], "����2");
//                    linkname[0] = StringSwitcher(linkname[0], linkname[0], "����2");
//                    free(garbage);
//                }
//                if (StringCompare(linkdata[1], "440") == COMPARE_SAME) {
//                    garbage = linkname[1];
//                    //printf("[%d] ����: %s�� -> %s��[��/��߿�]\n", i, data[idx_start], "����2");
//                    linkname[1] = StringSwitcher(linkname[1], linkname[1], "����2");
//                    free(garbage);
//                }
//
//
//                datatemp = StringAdd(linkname, "_");
//
//                garbage = data[idx_linkNum];
//                printf("[%d] ����: (Link) %s -> %s\n", i, data[idx_linkNum], datatemp);
//                data[idx_linkNum] = StringSwitcher(data[idx_linkNum], data[idx_linkNum], datatemp);
//                free(garbage);
//
//            }
//
//
//            if (idx_startNum != -1 && StringCompare(data[idx_startNum], "440") == COMPARE_SAME) {
//                garbage = data[idx_start];
//                printf("[%d] ����: %s�� -> %s��[��/��߿�]\n", i, data[idx_start], "����2");
//                data[idx_start] = StringSwitcher(data[idx_start], data[idx_start], "����2");
//                free(garbage);
//            }
//            if (idx_endNum != -1 && StringCompare(data[idx_endNum], "440") == COMPARE_SAME) {
//                garbage = data[idx_end];
//                printf("[%d] ����: %s�� -> %s��[������]\n", i, data[idx_end], "����2");
//                data[idx_end] = StringSwitcher(data[idx_end], data[idx_end], "����2");
//                free(garbage);
//            }
//
//
//
//            // ��� ������ �Ϸ�� �����ʹ� �ٷ� ���� �������
//            char* result = StringAdd(data, ",");
//            //printf("[%d]%s --> %s\n ", i, line, result);
//            fprintf(newstream, "%s", result);
//
//            _free(data);
//            i++;
//        }
//        fclose(stream);
//        fclose(newstream);
//    }
//
//    system("pause");
//    return 95;
//}

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct tagParent {

    char(*func)();

}Parent;


static char a_func()
{
    return 'A';
}
static char b_func()
{
    return 'B';
}

static Parent* create(char(*func)())
{
    Parent* ret = (Parent*)malloc(sizeof(*ret));

    ret->func = func;

    return ret;

}

int main(){

    Parent* ob1 = create(a_func);

    Parent* ob2 = create(b_func);

    printf("%c %c\n", ob1->func(), ob2->func());

    free(ob1);

    free(ob2);

    return 0;

}*/
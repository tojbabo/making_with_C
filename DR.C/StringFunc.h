#ifndef _StringFunc
#define _StringFunc

#include"Header.h"
#include"Utility.h"



// ���ڿ��� ���̸� �˾Ƴ��� �Լ�
int StringLength(char* string);

char* StringAdd1(char* HeadString, char* TailString);

char* StringAdd2(char* HeadString, int CopyPoint, char* TailString);

char* StringAdd3(char* HeadString, char* TailString, int CopyLength);

char* StringAdd4(char* HeadString, int CopyPoint, char* TailString, int CopyLength);

#define COMPARE_ERR -2
#define COMPARE_SRC -1   // source�� �� ����
#define COMPARE_SAME 0   // �� ���ڿ��� ����
#define COMPARE_DST 1    // destination�� �� ����

// ���ڿ� �迭 �޸� ��ȯ�ϴ� �Լ�
void matfree(char** data);

// ���ڿ� ���� ���Լ�
int StringCompare(char* Src, char* Dst);

// ���ڿ� �˻��Լ�
int* StringFinder(char* Src, char* Target);

// ���ڿ��� ������ �Լ�
char** StringParser(char* Src, char* Sep);

// ���ڿ��� �ٲٴ� �Լ�
char* StringSwitcher(char* Src, char* From, char* To);

// ���ڿ��� �����ϴ� �Լ�
char* StringCopy(char* Src);

#endif // !_StringFunc
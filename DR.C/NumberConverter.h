#ifndef _NumberConverter
#define _NumberConverter
#include"Header.h"
#include"StringFunc.h"


// n������ 10������ ��ȯ�ϴ� �Լ�
int NumberConverter_N2Dec(char* Source_Number, int FromBit);

// 10������ n������ ��ȯ�ϴ� �Լ�
char* NumberConverter_Dec2N(int Source_Number, int ToBit);

// n������ m������ ��ȯ�ϴ� �Լ�
char* NumberConverter(char* Source_Number, int FromBit, int ToBit);

#endif // !1


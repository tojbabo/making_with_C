#ifndef _NumberConverter
#define _NumberConverter
#include"Header.h"
#include"StringFunc.h"


// n진수를 10진수로 변환하는 함수
int NumberConverter_N2Dec(char* Source_Number, int FromBit);

// 10진수를 n진수로 변환하는 함수
char* NumberConverter_Dec2N(int Source_Number, int ToBit);

// n진수를 m진수로 변환하는 함수
char* NumberConverter(char* Source_Number, int FromBit, int ToBit);

#endif // !1


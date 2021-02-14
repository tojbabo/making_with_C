#ifndef _StringFunc
#define _StringFunc

#include"Header.h"
#include"Utility.h"



// 문자열의 길이를 알아내는 함수
int StringLength(char* string);

char* StringAdd1(char* HeadString, char* TailString);

char* StringAdd2(char* HeadString, int CopyPoint, char* TailString);

char* StringAdd3(char* HeadString, char* TailString, int CopyLength);

char* StringAdd4(char* HeadString, int CopyPoint, char* TailString, int CopyLength);

#define COMPARE_ERR -2
#define COMPARE_SRC -1   // source가 더 작음
#define COMPARE_SAME 0   // 두 문자열이 같음
#define COMPARE_DST 1    // destination가 더 작음

// 문자열 배열 메모리 반환하는 함수
void matfree(char** data);

// 문자열 길이 비교함수
int StringCompare(char* Src, char* Dst);

// 문자열 검색함수
int* StringFinder(char* Src, char* Target);

// 문자열을 나누는 함수
char** StringParser(char* Src, char* Sep);

// 문자열을 바꾸는 함수
char* StringSwitcher(char* Src, char* From, char* To);

// 문자열을 복사하는 함수
char* StringCopy(char* Src);

#endif // !_StringFunc
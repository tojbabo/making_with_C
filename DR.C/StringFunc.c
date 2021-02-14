#include"StringFunc.h"

void matfree(char** data) {
    for (int i = 0; data[i] != NULL; i++) {
        autofree(data[i]);
    }
    autofree(data);
}

// 문자열의 길이를 알아내는 함수
int StringLength(char* str) {
    for (int i = 0;; i++) {
        if (str[i] == 0) return i;
    }
}

// 문자열을 더하는 함수
char* StringAdd1(char* HeadString, char* TailString) {

    int HeadLen = StringLength(HeadString);
    int TailLen = StringLength(TailString);

    char* result = (char*)malloc(sizeof(char) * (HeadLen + TailLen + 1));

    for (int i = 0; i < HeadLen; i++) {
        result[i] = HeadString[i];
    }
    for (int i = 0; i < TailLen; i++) {
        result[HeadLen + i] = TailString[i];
    }
    result[HeadLen + TailLen] = 0;

    return result;
}

char* StringAdd2(char* HeadString, int CopyPoint, char* TailString) {

    int HeadLen = StringLength(HeadString);
    int TailLen = StringLength(TailString);

    if (CopyPoint >= HeadLen) {
        printf("wrong point\n");
        return NULL;
    }
    HeadLen = CopyPoint;

    char* result = (char*)malloc(sizeof(char) * (HeadLen + TailLen + 1));

    for (int i = 0; i < HeadLen; i++) {
        result[i] = HeadString[i];
    }
    for (int i = 0; i < TailLen; i++) {
        result[HeadLen + i] = TailString[i];
    }
    result[HeadLen + TailLen] = 0;

    return result;
}

char* StringAdd3(char* HeadString, char* TailString, int CopyLength) {

    int HeadLen = StringLength(HeadString);
    int TailLen = StringLength(TailString);

    if (CopyLength > TailLen) {
        printf("wrong length\n");
        return NULL;
    }
    TailLen = CopyLength;

    char* result = (char*)malloc(sizeof(char) * (HeadLen + TailLen + 1));

    for (int i = 0; i < HeadLen; i++) {
        result[i] = HeadString[i];
    }
    for (int i = 0; i < TailLen; i++) {
        result[HeadLen + i] = TailString[i];
    }
    result[HeadLen + TailLen] = 0;

    return result;
}

char* StringAdd4(char* HeadString, int CopyPoint, char* TailString, int CopyLength)  {

    int HeadLen = StringLength(HeadString);
    int TailLen = StringLength(TailString);

    if (CopyPoint >= HeadLen) {
        printf("wrong point\n");
        return NULL;
    }
    HeadLen = CopyPoint;

    if (CopyLength >= TailLen) {
        printf("wrong length\n");
        return NULL;
    }
    TailLen = CopyLength;

    char* result = (char*)malloc(sizeof(char) * (HeadLen + TailLen + 1));

    for (int i = 0; i < HeadLen; i++) {
        result[i] = HeadString[i];
    }
    for (int i = 0; i < TailLen; i++) {
        result[HeadLen + i] = TailString[i];
    }
    result[HeadLen + TailLen] = 0;

    return result;
}

int StringCompare(char* Src, char* Dst) {
    int LengthA = StringLength(Src);
    int LengthB = StringLength(Dst);
    if (LengthA == 0) {
        if (LengthB == 0) return COMPARE_SAME;
        return COMPARE_SRC;
    }
    else if (LengthB == 0) return COMPARE_DST;

    int i = 0;
    while (1) {
        if (Src[i] < Dst[i]) return COMPARE_SRC;
        else if (Src[i] > Dst[i]) return COMPARE_DST;
        else if (Src[i] == Dst[i] && Src[i] == 0) return COMPARE_SAME;

        if (i == LengthA || i == LengthB) break;
        i++;
    }
    return COMPARE_ERR;
}

int* StringFinder(char* Src, char* Target) {
    int arySize = 1;

    int* result = (int*)malloc(sizeof(int) * arySize);

    int idx = 0;

    int srcSize = StringLength(Src);
    int trgSize = StringLength(Target);


    for (int i = 0; i + trgSize <= srcSize;) {

        // 문자열의 일치 확인
        for (int j = 0; ; j++) {

            // 문자열이 끝까지 일치한 경우
            if (Target[j] == 0) {
                result = (int*)realloc(result, sizeof(int) * (++arySize));
                result[++idx] = i;

                i += trgSize;
                break;
            }

            // 문자열이 일치하지 않은 경우
            if (Src[i + j] != Target[j]) {
                if (j == 0) i++;
                else i += j;
                break;
            }

        }
    }
    result[0] = arySize - 1;

    return result;
}

char** StringParser(char* Src, char* Sep) {

    int SrcLength = StringLength(Src);
    int SepLegnth = StringLength(Sep);
    int* Finder = StringFinder(Src, Sep);

    int ResultSize = 0;
    int StringLength = 0;
    char** result = (char**)malloc(sizeof(char*) * ResultSize);

    int StartIdx = 0;
    int EndIdx = 0;

    for (int i = 1; i <= Finder[0]; i++) {
        EndIdx = Finder[i];

        StringLength = EndIdx - StartIdx;

        if (StringLength == 0) {
            result = (char**)realloc(result, sizeof(char*) * ++ResultSize);
            result[ResultSize - 1] = StringAdd1("", "");

        }

        // 시작점이 다음점과 일치하는 경우
        if (StringLength > 0) {
            result = (char**)realloc(result, sizeof(char*) * ++ResultSize);
            result[ResultSize - 1] = StringAdd3("", Src + StartIdx, StringLength);
        }

        StartIdx = EndIdx + SepLegnth;
    }

    if (StartIdx == SrcLength) {
        result = (char**)realloc(result, sizeof(char*) * ++ResultSize);
        result[ResultSize - 1] = StringAdd1("", "");
    }
    else if (StartIdx < SrcLength) {
        result = (char**)realloc(result, sizeof(char*) * ++ResultSize);
        result[ResultSize - 1] = StringAdd1("", Src + StartIdx);
    }


    result = (char**)realloc(result, sizeof(char*) * ++ResultSize);
    result[ResultSize - 1] = NULL;

    autofree(Finder);
    return result;
}

char* StringSwitcher(char* Src, char* From, char* To) {
    char** TokenS = StringParser(Src, From);

    char* pre;
    char* result = StringAdd1("", TokenS[0]);

    for (int i = 1; TokenS[i] != NULL; i++) {

        pre = result;
        result = StringAdd1(pre, To);
        autofree(pre);

        pre = result;
        result = StringAdd1(pre, TokenS[i]);
        autofree(pre);
    }

    for (int i = 0; TokenS[i] != NULL; i++) {
        autofree(TokenS[i]);
    }
    autofree(TokenS);


    return result;
}

char* StringCopy(char* Src) {
    int len = StringLength(Src);

    if (Src == NULL) return NULL;

    char* data = (char*)malloc((sizeof(char) * len) + 1);
    for (int i = 0; i < len; i++) {
        data[i] = Src[i];
    }
    data[len] = 0;
    return data;
}
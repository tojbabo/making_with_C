#include "NumberConverter.h"

// n진수를 10진수로 변환하는 함수
int NumberConverter_N2Dec(char* Number, int FromBit) {

	if (FromBit > 36 || FromBit < 2) {
		printf("Convert Error\n");
		return -1;
	}

	int NumberLength = StringLength(Number);
	int result = 0;

	int weight = 1;
	for (int i = NumberLength - 1; i >= 0; i--) {

		int tempNumber = Number[i];

		if (Number[i] >= 'a') tempNumber -= 'a';
		else tempNumber -= '0';

		result += tempNumber * weight;
		weight *= FromBit;
	}
	return result;
}

// 10진수를 n진수로 변환하는 함수
char* NumberConverter_Dec2N(int Number, int ToBit) {

	if (ToBit > 36 || ToBit < 2) {
		printf("Convert Error\n");
		return "Convert Error";
	}

	int MSB = 1;
	int temp = ToBit;

	while (1) {
		if (temp > Number) break;
		else {
			temp *= ToBit;
			MSB++;
		}
	}

	char* result = (char*)malloc(sizeof(char) * (MSB + 1));
	result[MSB] = 0;

	int Temp_Number = Number;

	while (1) {
		if (Temp_Number == 0) break;

		int remainder = Temp_Number % ToBit;

		if (remainder > 9) result[--MSB] = remainder + 'a' - 10;
		else result[--MSB] = remainder + '0';

		Temp_Number = Temp_Number / ToBit;
	}

	return result;
}

// n진수를 m진수로 변환하는 함수
char* NumberConverter(char* Number, int FromBit, int ToBit) {

	if (ToBit > 36 || ToBit < 2 || FromBit > 36 || FromBit < 2) {
		printf("Convert Error\n");
		return "Convert Error";
	}

	int temp = NumberConverter_N2Dec(Number, FromBit);
	return NumberConverter_Dec2N(temp, ToBit);
}
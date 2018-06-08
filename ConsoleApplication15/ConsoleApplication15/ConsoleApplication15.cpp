// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
int mxdiflg(
	const char **firstArray, size_t firstArrayLength,
	const char **secondArray, size_t secondArrayLength)
{
	int result = 0, maxLength = 0, isEmpty = 0, item;

	for (int i = 0; i < firstArrayLength; i++)
	{
		for (int j = 0; j < secondArrayLength; j++)
		{
			item = fabs(sizeof(firstArray[i]) - sizeof(secondArray[j]));
			if (sizeof(firstArray[i]) > 0 || sizeof(secondArray[j]) > 0) isEmpty = 1;
			if (abs(item) > result) result = item;
		}
	}
	return isEmpty == 0 ? -1 : result;
}

int main()
{
	const char *firstArray[] = { "hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz" };
	const char *secondArray[] = { "cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww" };

	const size_t firstArrayLength = sizeof(firstArray) / sizeof(firstArray[0]);
	const size_t secondArrayLength = sizeof(secondArray) / sizeof(secondArray[0]);
	std::cout << mxdiflg(firstArray, firstArrayLength, secondArray, secondArrayLength);
	system("pause");
    return 0;
}


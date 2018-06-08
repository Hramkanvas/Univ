// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
int mxdiflg(
	const char **firstArray, size_t firstArrayLength,
	const char **secondArray, size_t secondArrayLength)
{
	int xMax = 0, yMax = 0, xMin = 0, yMin = 0;
	while (*firstArray != '\0' || *secondArray != '\0')
	{
		if (*firstArray != '\0')
		{
			if (xMax < sizeof(*firstArray)) xMax = *firstArray;
			if (xMin > sizeof(*firstArray)) xMin = *firstArray
				++firstArray;
		}
		if (*secondArray != '\0')
		{
			if (yMax < sizeof(*secondArray)) yMax = *secondArray;
			if (yMin > sizeof(*secondArray)) yMin = *secondArray
				++secondArray;
		}
	}
	if (xMax == 0 && yMax == 0) return -1;
	return abs(xMax - yMin) >= abs(yMax - xMin) ? abs(xMax - yMin) : abs(yMax - xMin);
}

int main()
{
	
    return 0;
}


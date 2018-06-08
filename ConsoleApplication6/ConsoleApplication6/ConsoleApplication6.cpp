// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;
double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
int main()
{	
	srand(time(NULL));
	for (int i = 0, end = 10000; i < end; i++) {
		std::cout << left << fRand(1., 100.) << endl;
	}
	system("pause");
    return 0;
}
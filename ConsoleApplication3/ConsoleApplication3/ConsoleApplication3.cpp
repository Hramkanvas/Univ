// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void func(int *mass) {
	mass[3] = 5;
}

int main()
{
	int n = 5;
	int *mass = new int[n];
	for (int i = 0; i < n; i++) {
		mass[i] = i;
	}
	func(mass);
	printf("%d", mass[3]);
	system("pause");
    return 0;
}
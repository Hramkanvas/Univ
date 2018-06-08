// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int main()
{
	int p = 3;
	int *mass = new int[5];
	for (int i = 0; i < 5; i++) {
		mass[i] = i;
	}
	cout << mass[p++];
	p = 3;
	cout << *(mass + p + 1);
	char f = 'd';
	cout << f % 2;
	int k = 4;
	while (k)
	{
		cout << k << " ";
		if (k-- % 2)continue;
		cout << k << " ";

	}
	system("pause");
    return 0;
}


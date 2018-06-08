// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double progt = 10, progs = 2, progf = 7;
	cout << "\n****************\n";
	cout << setprecision(8)<< progf << endl;
	for (int i = 0; i < 43; i++) {
		cout << setprecision(8) << (progf = progf * 2 / 3) << endl;
	}
	cout << "\n****************\n";
	cout << setprecision(8) << progs << endl;
	for (int i = 0; i < 12; i++) {
		cout << setprecision(8) << (progs = progs * 1 / 20) << endl;
	}
	cout << "\n****************\n";
	cout << setprecision(8) << progt << endl;
	for (int i = 0; i < 104; i++) {
		cout << setprecision(8) << (progt = progt * 3 / 4) << endl;
	}
	system("pause");
    return 0;
}


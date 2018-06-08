// testproject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
int main()
{
	int size = 1000;
	vector<int> vec(size);
	int *arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i;
		vec[i] = i;
	}
	double startA, startV, endA, endV, v, a;
	startA = clock();
	for (int i = 0; i < size; i++) {
		arr[i];
	}
	endA = clock();
	startV = clock();
	for (int i = 0; i < size; i++) {
		vec[i];
	}
	endV = clock();
	printf("arr %f, vec %f", endA - startA, endV - startV);
	system("pause");
    return 0;
}
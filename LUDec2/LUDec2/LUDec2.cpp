// LUDec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <iterator>
#include <random>
#include <ctime>
#include <iomanip>



using namespace std;

default_random_engine rng;

int my_random(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

void gauss(vector<vector<double>> &matrix) {
	
	double start = clock();
	double dim = matrix.size();
	double sum = 0;
	vector<double> row;
	vector<vector<double>> U;
	vector<vector<double>> L;
	cout << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << setw(10) << left << setprecision(5) << matrix[i][j];
		}
		cout << endl << endl;
	}
	for (int i = 0; i < dim; i++) row.push_back(0);
	for (int i = 0; i < dim; i++) {
		L.push_back(row);
		U.push_back(row);
	}
	
	int nrow;
	int ncol;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			
			U[0][i] = matrix[0][i];
			L[i][0] = matrix[i][0] / U[0][0];
			sum = 0;

			for (int k = 0; k < i; k++) sum += L[i][k] * U[k][j];

			U[i][j] = matrix[i][j] - sum;
			if (i <= j) {
				sum = 0;
				for (int k = 0; k < i; k++) sum += L[j][k] * U[k][i];
				L[j][i] = (matrix[j][i] - sum) / U[i][i];
			}
		}
	}
	double end = clock();
	cout << endl << "Time: " << 1000 * (end - start) << " s";
	
	cout << endl << "____L______" << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << setw(6) << left << setprecision(5) << L[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "__________" << endl;

	cout << endl << "____U______" << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << setw(6) << left << setprecision(5) << U[i][j] << " ";
		}
		cout << endl;
	}
}

void wrMatr(vector<vector<double>> &matrix) {
	vector<double> row;
	int eq = 0;
	double el;
	cout << "Enter the quantity of equations: ";
	cin >> eq;
	for (int i = 0; i < eq; i++) {
		for (int j = 0; j < eq; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> el;
			row.push_back(el);
		}
		matrix.push_back(row);
		row.clear();
	}
}

void randomMatr(vector<vector<double>> &matrix) {
	srand(time(NULL));
	vector<double> row;
	int eq = 0;
	double disp = 0;
	cout << "Enter the quantity of equations: ";
	cin >> eq;
	for (int i = 0; i < eq; i++) {
		for (int j = 0; j < eq; j++) {
			row.push_back(my_random(-5, 5));
		}
		matrix.push_back(row);
		row.clear();
	}
}

int main()
{

	vector<vector<double>> matrixA;
	randomMatr(matrixA);
	gauss(matrixA);
	system("pause");
	return 0;
}
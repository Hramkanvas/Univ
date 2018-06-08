// LUDec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <iterator>
#include <random>
#include <iostream>
#include <ctime>



using namespace std;

default_random_engine rng;

int my_random(int a, int b)
{
    std::uniform_int_distribution<int> dist_a_b(a, b);
    return dist_a_b(rng);
}

void gauss(vector<vector<double>> &matrix) {
	double dim = matrix.size();
	vector<vector<double>> matrixA = matrix;
	vector<double> row;
	double sum = 0;
	double eps = 1e-6;
	double max = 1e-6;
	int rowIndex = 0;
	bool rg = false;
	//for (int i = 0; i < dim; i++) row.push_back(0);
	//for (int i = 0; i < dim; i++) matrixA.push_back(row);
	for (int j = 0; j < dim; j++) {
		for (int i = 0; i < dim; i++) {
			if (i <= j) {
				for (int k = 0; k < i - 1; k++) sum += matrixA[i][k] * matrixA[k][j];
				matrixA[i][j] = matrixA[i][j] - sum;
				sum = 0;
			}
			else {
				rg = true;
				for (int k = 0; k < j - 1; k++) sum += matrixA[i][k] * matrixA[k][j];
				matrixA[i][j] = matrixA[i][j] - sum;
				sum = 0;
			}
		}
		if (rg) {
			max = matrixA[j][j];
			rowIndex = j;
			for (int i = j + 1; i < dim; i++) {
				if (abs(matrixA[i][j]) > abs(max)) {
					max = matrixA[i][j];
					rowIndex = i;
				}
			}
			if (abs(max) < eps) {
				cerr << "No decisions";
				return;
			}
			else swap(matrixA[j], matrixA[rowIndex]);
			for (int i = j + 1; i < dim; i++) matrixA[i][j] /= matrixA[j][j];
			/*cout << endl << "__________" << endl;
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					cout << matrixA[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << "__________" << endl;*/
		}
		rg = false;
	}
	cout << endl << "__________" << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "__________" << endl;
	cout << endl << "__________" << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << matrixA[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "__________" << endl;
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
	//cout << "Enter the amount of variation: ";
	//cin >> disp;
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
	/*vector<vector<double>> matrixB;
	wrMatr(matrixA);
	vector<vector<double>> matrixC;
	randomMatr(matrixA);
	vector<vector<double>> matrixD;
	randomMatr(matrixA);
	vector<vector<double>> matrixE;
	randomMatr(matrixA);*/
	gauss(matrixA);
	/*gauss(matrixB);
	gauss(matrixC);
	gauss(matrixE);*/
	system("pause");
	return 0;
}
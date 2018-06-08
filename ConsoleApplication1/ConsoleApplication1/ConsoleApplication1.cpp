#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void print_system(const vector<vector<double>>& matrix) {
	bool zero = false;
	for (int i = 0; i < matrix.size(); i++) {
		zero = false;
		for (int j = 0; j < matrix[i].size(); j++) {
			if (j > 0 && matrix[i][j - 1] != 0) zero = true;
			if (matrix[i][j] < 0 && zero && j != matrix[i].size() - 1) cout << " - ";
			else if (matrix[i][j] < 0) cout << "-";
			else if (matrix[i][j] > 0 && zero && j != matrix[i].size() - 1) cout << " + ";
			if (fabs(matrix[i][j]) == 0 && j == matrix[i].size() - 2) cout << " = ";
			if (fabs(matrix[i][j]) == 0 && j != matrix[i].size() - 1) continue;
			if (fabs(matrix[i][j]) == 1 && j != matrix[i].size() - 1 && j != matrix[i].size() - 2) cout << "x" << j + 1;
			else if (fabs(matrix[i][j]) == 1 && j == matrix[i].size() - 2) cout << "x" << j + 1 << " = ";
			else if (j < matrix[i].size() - 2) cout << fabs(matrix[i][j]) << "x" << j + 1;
			else if (j == matrix[i].size() - 2) cout << fabs(matrix[i][j]) << "x" << j + 1 << " = ";
			else if (i < matrix.size() - 1) cout << fabs(matrix[i][j]) << ",";
			else cout << fabs(matrix[i][j]) << ";";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	vector<vector<double>> matrix;
	string fname;
	cout << "sdcsdc";
	cin >> fname;
	ifstream fin(fname);
	while (!fin.is_open()) {
		cout << "sdcs";
		cin >> fname;
		ifstream fin(fname);
	}

	vector<double> vec;
	string str, s;
	while (getline(fin, str)) {
		int i = 0;
		while (i < str.size()) {
			if (str[i] == ' ') {
				i++;
				continue;
			}
			while (i < str.size() && str[i] != ' ') {
				s += str[i];
				i++;
			}
			vec.push_back(atof(s.c_str()));
			s.clear();
		}
		matrix.push_back(vec);
		vec.clear();
	}
	fin.close();

	cout << "Система " << matrix.size() << " линейных неоднородных уравнений с " << matrix[0].size() - 1 << " уравнениями: " << endl << endl;
	print_system(matrix);

	//






	//

	system("pause");
	return 0;
}
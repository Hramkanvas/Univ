// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<cmath>
#include<cstdlib>
#include <ctime>

using namespace std;

void findBG(double* f, double*& B, double* g, int n)
{
	B[0] = 0;
	g[0] = f[0] / n;
	for (int i = 1; i < n; i++)
	{
		B[i] = B[i] / n;
		cout << B[i] << " ";
		g[i] = f[i] / n;
	}
	cout << endl;
}

void vectSol(double* f, int n)
{
	f[0] = 2 * n - 1;
	for (int i = 1; i < n; i++)
	{
		f[i] = n + 1;
	}
}
void vectSol(double** A, double* x, double* f, int n)
{
	for (int i = 0; i < n; i++)
	{
		f[i] = 0;
		x[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f[i] += A[i][j] * x[j];
		}
	}
	cout << "Vector f:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << f[i] << " ";
	}
	cout << endl;
}

void print(double** mtr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mtr[i][j] << "  ";
		}
		cout << "\n";
	}
}

void solution(double* x, int n)
{
	cout << "Solution: ";
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << endl;
	double max = 0;
	for (int i = 0; i < n; i++)
		if ((fabs(x[i]) - 1) > max)
			max = fabs(x[i]) - 1;
	cout << "Pogreshnost: " << max << endl;
}

bool stopIteration(double* x, double* xnew, int num, double eps)
{
	for (int i = 0; i < num; ++i)
		if (abs(x[i] - xnew[i]) > eps)
			return false;
	return true;
}

void Jacobi(double* B, double* g, int n, double eps)
{
	double* x = new double[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
	}
	int numIter = 0;
	double sum = 0;
	double error = 0;
	double* xnew = new double[n];
	while (true)
	{
		for (int i = 0; i < n; ++i)
		{
			sum = 0;
			if (i == 0)
			{
				for (int j = 0; j < n; ++j)
					sum += B[j] * x[j];
			}
			else
			{
				sum = B[n - 1] * x[0];
			}
			xnew[i] = g[i] + sum;
			if (error < abs(xnew[i] - x[i]))
				error = abs(xnew[i] - x[i]);
		}
		++numIter;
		if (stopIteration(x, xnew, n, eps))
			break;
		cout << "Iteration - " << numIter << " : " << error << endl;
		error = 0;
		for (int i = 0; i < n; ++i)
			x[i] = xnew[i];
	}
	for (int i = 0; i < n; ++i)
		x[i] = xnew[i];
	cout << "Solution:" << endl;
	if (n == 1000)
	{
		for (int i = 0; i < 20; ++i)
		{
			cout << x[i] << " ";
		}
		cout << "... ";
		for (int i = n - 1; i > n - 21; i--)
		{
			cout << x[i] << " ";
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			cout << x[i] << " ";
		}
	}
	cout << endl;
}

void relaxation()
{
	int n = 3;
	int k = 0;
	double error = 0;
	double accuracy;
	double norma;
	double w;
	double a[3][3];
	double f[3];
	double x[3];
	double xCopy[3];
	accuracy = 0.001;
	cout << "Enter parameter w: ";
	cin >> w;
	a[0][0] = -4;
	a[0][1] = 0;
	a[0][2] = 2;
	a[1][0] = 1;
	a[1][1] = -8;
	a[1][2] = 5;
	a[2][0] = 1;
	a[2][1] = 3;
	a[2][2] = -5;
	f[0] = -2;
	f[1] = -2;
	f[2] = -3;
	for (int i = 0; i < 3; i++)
	{
		xCopy[i] = 0;
		x[i] = xCopy[i];
	}
	do
	{
		k++;
		error = 0;

		for (int i = 0; i < n; i++)
		{
			x[i] = f[i];
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					x[i] = x[i] - a[i][j] * x[j];
				}
			}
			x[i] /= a[i][i];

			x[i] = w*x[i] + (1 - w) * xCopy[i];

			if (fabs(x[i] - xCopy[i]) > error)
			{
				error = fabs(x[i] - xCopy[i]);
			}

			xCopy[i] = x[i];
		}
		cout << "Iteration - " << k << " : " << error << endl;

	} while (error > accuracy);
	cout << "Number of iterations: ";
	cout << k << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "x [" << i + 1 << "] = " << x[i] << endl;
	}
	cout << "Solution w = 1.2 - 6  iter " << endl;
	cout << "Zeidel w = 1 - 12 iter" << endl;
}
int main()
{
	int n = 0;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	double eps = 0.00000000001;
	double* x = new double[n];
	double* B = new double[n];
	double* g = new double[n];
	double* f = new double[n];
	double* fCopy = new double[n];
	for (int i = 0; i < n; i++)
	{
		fCopy[i] = 0;
		f[i] = 0;
		g[i] = 0;
		x[i] = 1;
		B[i] = -1;
	}
	vectSol(f, n);
	findBG(f, B, g, n);
	cout << "Vector g:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << g[i] << " " << endl;
	}
	//Jacobi(B, g, n, eps);
	relaxation(); // n = 3
	system("pause");
	return 0;
}
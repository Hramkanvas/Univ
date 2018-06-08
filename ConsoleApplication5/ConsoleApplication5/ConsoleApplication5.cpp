

#include "stdafx.h"
#include <iostream>
#include <math.h>
const double eps = 0.001;

void Jacobi(int N, double** A, double* F, double* X)
{
	double* TempX = new double[N];
	double norm; 

	do {
		for (int i = 0; i < N; i++) {
			TempX[i] = F[i];
			for (int g = 0; g < N; g++) {
				if (i != g)
					TempX[i] -= A[i][g] * X[g];
			}
			TempX[i] /= A[i][i];
		}
		norm = fabs(X[0] - TempX[0]);
		for (int h = 0; h < N; h++) {
			if (fabs(X[h] - TempX[h]) > norm)
				norm = fabs(X[h] - TempX[h]);
			X[h] = TempX[h];
		}
	} while (norm > eps);
	delete[] TempX;
}
int main()
{
	double d[] = {-5, 5, -5, -2, -5, 0, -3, -1, 5};
	double **A = new double*[3];
	for (int i = 0; i < 3; i++) {
		A[i ]= new double[3];
		for (int j = 0; j < 3; j++) {
			A[i][j] = d[j + i * 3];
		}
	}
	double *F = new double[3];
	F[0] = 3;
	F[1] = 2;
	F[2] = 4;
	double *X = new double[3];
	X[0] = 3;
	X[1] = 2;
	X[2] = 4;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%f", X[j]);
		}
		printf("\n");
	}
	Jacobi(3, A, F, X);
	printf("%f, %f, %f,", X[0], X[1], X[2]);
	system("pause");
    return 0;
}


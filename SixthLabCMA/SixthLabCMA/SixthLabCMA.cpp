#include "stdafx.h"
#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;

class Matrix {
public:
	vector<vector<double>> Mat;
	vector<vector<double>> IMat;
	vector<double> VSol;
	vector<double> VSolN;
	vector<double> Roots;
	vector<double> errorsVector;
	vector<int> rowPivoting;
	vector<vector<double>> LU;
	vector<int> pivotingVector;
	vector<double> minEigenVec;
	vector<double> residualVector;
	vector<double> frobeniusVector;
	void LUSolver();
	void Danilevski();
	void eigenvalueTest();
	void showResidualVector();
	void fixResidualVector();
	void InvertIteration();
	void showMinEigenVal();
	void showMinEigVec();
	void getIterationInf();
	void readMat();
	void writeMat();
	virtual void genMat();
	void genVSol();
	void rotation();
	void showLUDecomposition();
	double getNorm(vector<double> &v1, vector <double> &v2);
	void residual();
	void Jacobi();
	void rootVSol();
	virtual void showMat();
	void showRoots();
	void showVSol();
	double scalarProduct(vector<double> &v1, vector<double> &v2);
	void showRowPivoting();
	void createMatrix();
	void createVSol();
	void gaussianElemPiv();
	void LUDecomposotion();
	void getLUDeterminant();
	void invertLU();
	void showInvertMatrix();
	int getOrder() {
		return order;
	}
protected:
	int order = 0;
	int pivotingNumber = 0;
	double maxEigevalue;
	double minEigenvalue;
	string FName;
};
class SymMatrix : public Matrix {
public:
	void genMat();
	vector<vector<double>> S;
	vector<double> D;
	void chol();
	void showChol();
	void SDSDec();
	vector<vector<double>> ST1;
	vector<vector<double>> S1;
	vector<vector<double>> S1D;
};
class ThridiagMatrix : public Matrix {
public:
	void genMat();
	vector<double> Rootsy;
	vector<double> Rootsz;
	vector<double> abc;
	vector<double> alpha;
	vector<double> beta;
	vector<double> gamma;
	void Thomas();
	void createMat();
	void showMat();
protected:
	int bStart;
	int aStart;
	int aEnd;
	int bEnd;
};
class XMatrix : public Matrix {
public:
	vector<double> Mat;
	void gmres();
	void getInfIteration();
	void genMat();
	void showMat();
	void showBackMat();
	void getBackNorm();
	double getTau(vector<double> &v1, vector<double> &v2);
	double getResidual(vector<double> &v1, vector<double> &v2);
private:
	double x, y;
};
int my_random(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

struct myclass {
	bool operator() (int i, int j) { return abs(i) < abs(j); }
} myobj;

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

ostream& operator << (ostream &s, const vector<vector<double>> &Mat)
{
	s << endl << "___________________________________________" << endl << endl;
	for (int i = 0, e = Mat.size(); i < e; i++) {
		for (int j = 0; j < e; j++) {
			s << fixed;
			s << setw(10) << right << setprecision(4) << Mat[i][j];
		}
		s << endl << endl;
	}
	s << "___________________________________________" << endl;
	return s;
}

ostream& operator << (ostream &s, const vector<double> &Vec)
{
	s << endl << "____________" << endl << endl;
	int dopLength = to_string((int)Vec[0]).length();
	for (int i = 0, e = Vec.size(); i < e; i++) {
		s << fixed;
		s << setw(6 + dopLength) << right << setprecision(8) << Vec[i] << endl;
	}
	s << "____________" << endl;
	return s;
}

ostream& operator << (ostream &s, const vector<int> &Vec)
{
	s << "____________" << endl << endl;
	int dopLength = to_string(Vec[0]).length();
	for (int i = 0, e = Vec.size(); i < e; i++) {
		s << setw(2 + dopLength) << right << Vec[i] << endl;
	}
	s << "____________" << endl;
	return s;
}

int sgn(double var) {
	if (var < 0) return -1;
	else if (var > 0) return 1;
	else return 0;
}
void Matrix::genMat() {
	srand(time(NULL));
	cout << "Enter the matrix order: ";
	cin >> order;
	vector<double> row;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
				row.push_back(my_random(-5, 5));
		}
		Mat.push_back(row);
		row.clear();
	}
}
void SymMatrix::genMat() {
	srand(time(NULL));
	cout << "Enter the matrix order: ";
	cin >> order;
	vector<double> row;
	double out = 0;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			if (j < i) {
				row.push_back(Mat[j][i]);
			}
			else {
				row.push_back(fRand(-5.0, 5.0));
			}
		}
		Mat.push_back(row);
		row.clear();
	}
}

void Matrix::showMat() {
	cout << Mat;
}

void Matrix::genVSol() {
	srand(time(NULL));
	for (int i = 0; i < order; i++) {
		VSol.push_back(fRand(-5, 5));
	}
}

void SymMatrix::chol() {
	double start = clock();
	vector<double> row;
	double sum = 0;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			if (j < i) {
				row.push_back(0);
			}
			else if (j == i) {
				sum = 0;
				for (int k = 0; k < i; k++) sum += pow(S[k][i], 2) * D[k];
				row.push_back(sqrt(abs(Mat[i][i] - sum)));
				D.push_back(sgn(Mat[i][i] - sum));
			}
			else if (j > i) {
				sum = 0;
				for (int k = 0; k < i; k++) sum += S[k][i] * D[k] * S[k][j];
				row.push_back((Mat[i][j] - sum) / (D[i] * row[i]));

			}
		}
		S.push_back(row);
		row.clear();
	}
	double end = clock();
	start = end - start;
	printf("It took me %d clicks (%f seconds).\n", start, ((float)start) / CLOCKS_PER_SEC);
}

void Matrix::rootVSol() {
	double element = 0;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			element += Mat[i][j];
		}
		VSol.push_back(element);
		element = 0;
	}
}

void Matrix::residual() {
	vector<double> dt(order, 0);
	for (int i = 0; i < order; i++) {
		dt[i] = (1. - Roots[i]);
	}
	cout << endl << "residual = " << abs(*max_element(dt.begin(), dt.end(), myobj)) << endl;
}

void SymMatrix::showChol() {
	cout << "S matrix: " << endl;
	cout << S;
	cout << "D matrix: " << endl;
	cout << D;
}

void Matrix::showRoots() {
	cout << "Roots: " << endl;
	cout << Roots;
};

void Matrix::showVSol() {
	cout << "Function dec: " << endl;
	cout << VSol;
}
double Matrix::scalarProduct(vector<double>& v1, vector<double>& v2)
{
	double product = 0;
	for (int i = 0; i < order; i++) {
		product += v1[i] * v2[i];
	}
	return product;
}
;

void Matrix::createVSol() {
	double element = 0;
	cout << "Enter Dec vector" << endl;
	for (int i = 0; i < order; i++) {
		cout << "Dec[" << i << "] = ";
		cin >> element;
		VSol.push_back(element);
	}
}

void Matrix::createMatrix() {
	double element = 0;
	vector<double> row;
	cout << "Enter the order of your matrix: ";
	cin >> order;
	cout << "Enter yout matrix: " << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << "Mat[" << i << "][" << j << "] = ";
			cin >> element;
			row.push_back(element);
		}
		Mat.push_back(row);
		row.clear();
	}
}

void SymMatrix::SDSDec() {
	vector<vector<double>> ST = S;
	vector<double> y;
	double tmp = 0;
	double sum = 0;
	for (int i = 0; i < order; i++) {
		for (int j = i + 1; j < order; j++) {
			tmp = ST[i][j];
			ST[i][j] = ST[j][i];
			ST[j][i] = tmp;
		}
	}
	for (int i = 0; i < order; i++) {
		for (int k = 0; k < i; k++) sum += y[k] * ST[i][k];
		y.push_back((VSol[i] - sum) / ST[i][i]);
		sum = 0;
	}
	Roots.clear();
	Roots = y;
	for (int i = order - 1; i > -1; i--) {
		Roots[i] = D[i] * y[i];
		for (int k = i + 1; k < order; k++) Roots[i] -= Roots[k] * S[i][k];
		Roots[i] /= S[i][i];
		sum = 0;
	}
}

void ThridiagMatrix::genMat() {
	srand(time(NULL));
	cout << "Enter the matrix order: ";
	cin >> order;
	bStart = order;
	aStart = 2 * order;
	aEnd = 3 * order - 1;
	bEnd = bStart + order - 1;
	for (int i = 0; i < aEnd + 1; i++) {
		abc.push_back(fRand(-5, 5));
	}
}

void ThridiagMatrix::createMat() {
	srand(time(NULL));
	cout << "Enter the matrix order: ";
	cin >> order;
	double el = 0;
	bStart = order;
	aStart = 2 * order;
	aEnd = 3 * order - 1;
	bEnd = bStart + order - 1;
	for (int i = 0; i < aEnd + 1; i++) {
		if (i < bStart) {
			cout << endl << "c[" << i << "]";
			cin >> el;
			abc.push_back(el);
		}
		else if (i >= bStart && i < aStart) {
			cout << endl << "b[" << i - bStart << "]";
			cin >> el;
			abc.push_back(el);
		}
		else {
			cout << endl << "a[" << i - aStart << "]";
			cin >> el;
			abc.push_back(el);
		}
	}
}

void ThridiagMatrix::showMat() {
	cout << endl << "Your thridiagonal matrix:" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			if (i == j) {
				cout << setw(10) << left << setprecision(4) << abc[i];
			}
			else if (i == j - 1) {
				cout << setw(10) << left << setprecision(4) << abc[bStart + i];
			}
			else if (i == j + 1) {
				cout << setw(10) << left << setprecision(4) << abc[aStart + i];
			}
			else if (i == order - 1 && j == 0) {
				cout << setw(10) << left << setprecision(4) << abc[bStart + order - 1];
			}
			else if (i == 0 && j == order - 1) {
				cout << setw(10) << left << setprecision(4) << abc[aStart];
			}
			else {
				cout << setw(10) << left << setprecision(4) << 0;
			}
		}
		cout << endl;
	}

}

void ThridiagMatrix::Thomas() {
	clock_t start = clock();
	alpha.push_back(0);
	beta.push_back(0);
	gamma.push_back(1);
	double eltm = 0;
	for (int i = 1; i < order + 1; i++) {
		if (i == order) {
			eltm = (abc[0] + alpha[i - 1] * abc[aStart]);
			alpha.push_back(-abc[bStart] / eltm);
			beta.push_back((VSol[0] - beta[i - 1] * abc[aStart]) / eltm);
			gamma.push_back(-gamma[i - 1] * abc[aStart] / eltm);
		}
		else {
			eltm = (abc[i] + alpha[i - 1] * abc[aStart + i]);
			alpha.push_back(-abc[bStart + i] / eltm);
			beta.push_back((VSol[i] - beta[i - 1] * abc[aStart + i]) / eltm);
			gamma.push_back(-gamma[i - 1] * abc[aStart + i] / eltm);
		}
	}
	Rootsy.push_back(0);
	Rootsz.push_back(1);
	int root = 0;
	for (int i = order - 1; i > 0; i--) {
		Rootsy.push_back(alpha[i] * Rootsy[root] + beta[i]);
		Rootsz.push_back(alpha[i] * Rootsz[root] + gamma[i]);
		root++;
	}
	Rootsy.push_back(0);
	Rootsz.push_back(1);
	reverse(Rootsz.begin(), Rootsz.end());
	reverse(Rootsy.begin(), Rootsy.end());
	Roots.push_back((beta[order] + alpha[order] * Rootsy[1]) / (1 - gamma[order] - alpha[order] * Rootsz[1]));
	for (int i = 1; i < order; i++) {
		Roots.push_back(Rootsy[i] + Roots[0] * Rootsz[i]);
	}
	start = clock() - start;
	printf("It took me %f seconds.\n", start / CLOCKS_PER_SEC);
}

class GilbertMatrix : public SymMatrix {
public:
	void genMat();
};

void GilbertMatrix::genMat() {
	vector<double> row;
	cout << "Enter the order of your gilbert matrix: " << endl;
	cin >> order;
	for (int i = 1; i <= order; i++) {
		for (int j = 1; j <= order; j++) {
			row.push_back(1. / (j + i - 1));
		}
		Mat.push_back(row);
		row.clear();
	}
}
void Matrix::LUSolver()
{
	Roots = vector<double>(order, 0);
	for (int i = 0; i < order; i++) {
		Roots[i] = VSol[pivotingVector[i]];
		for (int j = 0; j < i; j++) {
			Roots[i] -= LU[i][j] * Roots[j];
		}
	}

	for (int i = order - 1; i >= 0; i--) {
		for (int j = i + 1; j < order; j++) {
			Roots[i] -= LU[i][j] * Roots[j];
		}
		Roots[i] /= LU[i][i];
	}
}
void ImprDanilStability(vector<vector<double>> &matrix, vector<int> &pivot, int stepNumber) {
	double maxElement = matrix[stepNumber][stepNumber + 1], element, nrow = stepNumber;
	for (int i = stepNumber + 2; i < matrix.size(); i++) {
		if (fabs(element = matrix[stepNumber][i]) > fabs(maxElement)) {
			nrow = i;
			cout << "max" << maxElement;
			cout << "el" << element;
			maxElement = element;
		}
	}
	if (nrow != stepNumber) {
		swap(matrix[stepNumber + 1], matrix[nrow]);
		swap(pivot[stepNumber + 1], pivot[nrow]);
		for_each(matrix.begin(), matrix.end(), [&](vector<double> &item) {swap(item[stepNumber + 1], item[nrow]) ; });
	}
}
void Matrix::Danilevski()
{
	double sum = 0;
	vector<vector<double>> A = Mat;
	vector<vector<double>> B = Mat;
	frobeniusVector = vector<double>(order, 0);
	pivotingVector = vector<int>(order);
	for (int i = 0; i < order; i++) {
		pivotingVector[i] = i;
	}
		for (int k = 0; k < order - 1; k++) {
			if (k != order - 2)ImprDanilStability(A, pivotingVector, k);
			for (int i = 0; i < order; i++) {
				B[i][k + 1] = A[i][k + 1] / A[k][k + 1];
			}
			for (int i = 0; i < order; i++) {
				for (int j = 0; j < order; j++) {
					if (j != k + 1) {
						B[i][j] = A[i][j] - A[k][j] * B[i][k + 1];
					}
				}
			}
			for (int j = 0; j < order; j++) {
				sum = 0;
				for (int i = 0; i < order; i++) {
					sum += A[k][i] * B[i][j];
				}
				A[k + 1][j] = sum;
			}
			for (int i = 0; i < order; i++) {
				if (i != k + 1) {
					for (int j = 0; j < order; j++) {
						A[i][j] = B[i][j];
					}
				}
			}
		}
		for (int i = 0; i < order; i++) {
			frobeniusVector[i] = A[order - 1][i];
	}
		cout << "\nFrobenius matrix :\n" << A;
		cout << "\ncoefficients vector\n" << frobeniusVector;
}

void Matrix::eigenvalueTest() {
	double result = 0;
	result = pow(minEigenvalue, order);
	for (int i = order -1; i >= 0; i--) {
		result -= frobeniusVector[i] * pow(minEigenvalue, i);
	}
	cout << "\n result of P(v(min)) = \n" << result << endl;
}
void Matrix::showResidualVector()
{
	cout << "\n A*x - lambda*x vector:\n" << residualVector;
}
void Normalization(vector<double> &vect) {
	double firstNorm = *max_element(vect.begin(), vect.end());
	for_each(vect.begin(), vect.end(), [&](double &item) {item /= firstNorm; });
}
void TwoVecDivision(vector<double> &vect1, vector<double> &vect2, double &error, double &eigenvalue) {
	int dimension = vect1.size();
	vector<double> result(dimension, 0);
	for (int i = 0; i < dimension; i++) {
		result[i] = vect1[i] / vect2[i];
	}
	eigenvalue = *max_element(result.begin(), result.end());
	error = fabs(eigenvalue - *min_element(result.begin(), result.end()));
}
void Matrix::fixResidualVector() {
	residualVector = vector<double>(order);
	for (int i = 0; i < order; i++) {
		residualVector[i] = Roots[i] - VSol[i]*minEigenvalue;
	}
}
void Matrix::InvertIteration()
{
	double tol, error, iterationNumber = 0;
	cout << "Enter a tolerance: ";
	cin >> tol;
	VSol = vector<double>(order, 1);
	minEigenvalue = 1;
	this->LUDecomposotion();
	cout << "Error on k'th step:\n";
	while(true){
		iterationNumber++;
		this->LUSolver();
		TwoVecDivision(Roots, VSol, error, minEigenvalue);
		cout << error << endl;
		if (error <= tol) break;
		VSol = Roots;
		Normalization(VSol);
	}
	fixResidualVector();
	minEigenvalue = 1 / minEigenvalue;
	minEigenVec = VSol;
}
void Matrix::showMinEigenVal() {
	cout << "\n Minimal eigenvalue of your matrix = " << minEigenvalue << endl;
}
void Matrix::showMinEigVec() {
	cout << "\n Eigenvector of min eigenvalue:";
	cout << minEigenVec;
}
void Matrix::getIterationInf()
{
	cout << "\n~`!@#$%^&*()_+/*-+?][{}!@#$%^&*()_!@#$%^&*()!@#$%^&*(\nNumber of iterations = "
		<< errorsVector.size() << endl << "errors table: {\n";
	for (int i = 0; i < errorsVector.size(); i++) {
		cout << "\t" << setprecision(17) << errorsVector[i] << endl;
	}
	cout << "}\n";
	cout << "\n~`!@#$%^&*()_ +/*-+?][{}!@#$%^&*()_!@#$%^&*()!@#$%^&*(\n";
}
void Matrix::readMat() {
	cout << "Type the name of the matrix-file you want to open:\n";
	cin >> FName;//***********
	FName += ".txt";
	ifstream MFile(FName);
	while (!MFile.is_open()) {
		cout << endl << "There're some problems with your file, try again, type the name:\n";
		cin >> FName;
		FName += ".txt";
		ifstream MFile(FName);
	}
	vector <double> Row;
	string TStr;
	string TTT;
	while (getline(MFile, TStr)) {
		order++;
		string::iterator it = TStr.begin();
		string::iterator itt = TStr.begin() + TStr.find(' ');
		string::iterator end = TStr.end();
		while (it != end) {
			for (itt = TStr.begin() + TStr.find(' '); it != itt; ++it) {
				TTT.push_back(*it);
			}
			Row.push_back(stod(TTT));
			TStr.erase(TStr.begin(), TStr.begin() + TStr.find(' ') + 1);
			TTT.clear();
			it = TStr.begin();
			end = TStr.end();
		}
		Mat.push_back(Row);
		Row.clear();
	}
	MFile.close();
}
void Matrix::writeMat()
{
	string FName1;
	cout << "Your matrix will be saved in file, please type the name of the new file: ";
	cin >> FName1;
	FName1 + ".txt";
	ofstream MFile1(FName1);
	for (vector<vector<double>>::iterator it = Mat.begin(); it != Mat.end(); ++it) {
		for (vector<double>::iterator jt = (*it).begin(); jt != (*it).end(); ++jt) {
			MFile1 << *jt << " ";
		}
		MFile1 << endl;
	}
	MFile1.close();
}
void Matrix::rotation() {
	double start = clock();
	double cos = 0;
	double sin = 0;
	double zn = 0;
	double ch = 0;
	double a, b;
	double apast;
	double fpast;
	for (int i = 0; i < order - 1; i++) {
		for (int k = i + 1; k < order; k++) {
			b = Mat[k][i];
			a = Mat[i][i];
			zn = sqrt(a * a + b * b);
			cos = a / zn;
			sin = -b / zn;
			for (int j = i; j < order; j++) {
				apast = Mat[i][j];
				Mat[i][j] = cos * apast - sin * Mat[k][j];
				Mat[k][j] = sin * apast + cos * Mat[k][j];
			}
			fpast = VSol[i];
			VSol[i] = cos * fpast - sin * VSol[k];
			VSol[k] = sin * fpast + cos * VSol[k];
		}
	}
	Roots = VSol;
	for (int i = order - 1; i >= 0; i--) {
		Roots[i] = VSol[i];
		for (int j = i + 1; j < order; j++) {
			Roots[i] -= Mat[i][j] * Roots[j];
		}
		Roots[i] /= Mat[i][i];
	}
	start = clock() - start;
	printf("\nIt took me %f seconds.\n", start / 1000);
}

void Matrix::showLUDecomposition()
{
	cout << "\nLU Decomposition; LU-matrix\n" << LU;
	cout << "Pivoting vector:\n" << pivotingVector;
}

double Matrix::getNorm(vector<double> &v1, vector<double> &v2)
{
	double result = abs(v1[0] - v2[0]);
	double element;
	for (int i = 1; i < order; i++) {
		element = abs(v1[i] - v2[i]);
		if (element > result) {
			result = element;
		}
	}
	return result;
}

void Matrix::gaussianElemPiv() {
	double start = clock();
	double max = 0;
	double newRow = 0;
	double newCol = 0;
	double element = 0;
	const double SGL = 1e-6;
	//pivoting vector initialization
	for (int i = 0; i < order; i++) {
		rowPivoting.push_back(i);
	}
	//gauss upward
	for (unsigned int i = 0; i < order; i++) {
		max = Mat[i][i];
		newRow = i;
		newCol = i;
		//looking for max element
		for (unsigned int it = i; it < order; it++) {
			for (unsigned int jt = i; jt < order; jt++) {
				if (abs(max) < abs(Mat[it][jt])) {
					max = Mat[it][jt];
					newRow = it;
					newCol = jt;
				}
			}
		}
		if (abs(max) <= SGL) {
			cerr << "Matrix is singular";
			exit(1);
		}
		if (newRow != i) {
			swap(Mat[i], Mat[newRow]);
			swap(VSol[i], VSol[newRow]);
		}
		if (newCol != i) {
			for (int it = 0; it < order; it++) {
				swap(Mat[it][i], Mat[it][newCol]);
			}
		}
		for (int it = i + 1; it < order; it++) {
			element = Mat[it][i] / Mat[i][i];
			for (int j = i + 1; j < order; j++) {
				Mat[it][j] -= Mat[i][j] * element;
			}
			VSol[it] -= VSol[i] * element;
			Mat[it][i] = 0;
		}
	}
	int n = 9;
	int *arr = new int[n];
	int *arr2 = new int[n];
	arr = arr2;
	//backward
	Roots = VSol;
	for (int i = order - 1; i >= 0; i--) {
		Roots[i] = VSol[i];
		for (int j = i + 1; j < order; j++) {
			Roots[i] -= Mat[i][j] * Roots[j];
		}
		Roots[i] /= Mat[i][i];
	}
	start = clock() - start;
	printf("\nIt took me %f seconds.\n", start / 1000);
}
void Matrix::LUDecomposotion()
{
	double start = clock();
	int nrow;
	double maxColEl;
	pivotingVector = vector<int>(order, 0);
	LU = Mat;
	for (int i = 0; i < order; i++) {
		pivotingVector[i] = i;
	}
	for (int i = 0; i < order - 1; i++) {
		nrow = i;
		maxColEl = LU[i][i];
		for (int t = i + 1; t < order; t++) {
			if (fabs(maxColEl) < fabs(LU[t][i])) {
				nrow = t;
			}
		}
		if (fabs(LU[nrow][i]) < 1e-15) {
			cerr << "singular matrix";
			exit(1);
		}
		if (nrow != i) {
			pivotingNumber++;
			swap(LU[i], LU[nrow]);
			swap(pivotingVector[i], pivotingVector[nrow]);
		}
		for (int j = i + 1; j < order; j++) {
			LU[j][i] /= LU[i][i];
			for (int k = i + 1; k < order; k++) {
				LU[j][k] -= LU[j][i] * LU[i][k];
			}
		}
	}
	start = clock() - start;
	printf("\nIt took me %f seconds.\n", start / 1000);
	/*double sum = 0;
	vector<double> row(order,0);
	U = vector<vector<double>>(order, row);
	L = vector<vector<double>>(order, row);
	double maxInColomn;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {

			U[0][i] = Mat[0][i];
			L[i][0] = Mat[i][0] / U[0][0];
			sum = 0;

			for (int k = 0; k < i; k++) sum += L[i][k] * U[k][j];

			U[i][j] = Mat[i][j] - sum;
			if (i <= j) {
				sum = 0;
				for (int k = 0; k < i; k++) sum += L[j][k] * U[k][i];
				L[j][i] = (Mat[j][i] - sum) / U[i][i];
			}
		}
		cout << endl << L << endl << U;
	}*/
}
void Matrix::getLUDeterminant() {
	double result = 1;
	for (int i = 0; i < order; i++) {
				result *= LU[i][i];
	}
	if (pivotingNumber & 1) result *= -1;
	cout << "\n Determinant of your matrix = " << setprecision(8) <<  result << endl;
}
void Matrix::invertLU() {
	IMat = vector < vector < double>>(order, vector<double>(order, 0));
	for (int j = 0; j < order; j++) {
		for (int i = 0; i < order; i++) {
			if (pivotingVector[i] == j) {
				IMat[i][j] = 1;
			}
			else {
				IMat[i][j] = 0;
			}
			for (int k = 0; k < i; k++) {
				IMat[i][j] -= LU[i][k] * IMat[k][j];
			}
		}

		for (int i = order - 1; i >= 0; i--) {
			for (int k = i + 1; k < order; k++) {
				IMat[i][j] -= LU[i][k] * IMat[k][j];
			}
			IMat[i][j] = IMat[i][j] / LU[i][i];
		}
	}
}
void Matrix::showInvertMatrix() {
	cout << "\nInvert Matrix:\n";
	cout << IMat;
}
void Matrix::showRowPivoting() {
	cout << "\n roots pivoting";
	cout << rowPivoting;
}
void Matrix::Jacobi(){
	vector<double> PRoots(order, 0);
	Roots = PRoots;
	double error, eps, elem;
	cout << "Please, enter precision: ";
	cin >> eps;
	vector<vector<double>> B = Mat;
	VSol[0] += VSol[1];
	for (int i = 0; i < order; i++) {
		elem = B[i][i];
		B[i][i] = 0;
		VSol[i] /= elem;
		for (int j = 0; j < order; j++) {
			if (i != j) {
				B[i][j] /= -elem;
			}
		}
	}
	PRoots = VSol;
	do {
		for (int i = 0; i < order; i++) {
			Roots[i] = VSol[i];
			for (int j = 0; j < order; j++) {
				if (j != i) {
					Roots[i] += PRoots[j] * B[i][j];
				}
			}
		}
		error = getNorm(Roots, PRoots);
		errorsVector.push_back(error);
		PRoots = Roots;
	}
	while (error > eps);
}
void XMatrix::genMat() {
	cout << "\nPlease, enter the order of yout matrix: ";
	cin >> order;
	cout << "\nEnter the main diagonal element: ";
	cin >> x;
	cout << "\nEnter the secondary diagonal element: ";
	cin >> y;
}
void XMatrix::showMat()
{
		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {
				if (i == j)cout << left << setw(4) << setprecision(5) << x;
				else if(i == order - j - 1) cout << left << setw(4) << setprecision(5) << y;
				else cout << left << setw(4) << 0;
			}
			cout << endl;
		}
}
void XMatrix::showBackMat()
{
	if (order % 2 == 0) {
		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {
				if (i == j)cout << left << setw(9) << setprecision(5) << Roots[0];
				else if (i == order - j - 1) cout << left << setw(9) << setprecision(5) << Roots[1];
				else cout << left << setw(9) << 0;
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {
				if(i == (order) / 2 && i == j)cout << left << setw(9) << setprecision(5) << 1/x;
				else if (i == j)cout << left << setw(9) << setprecision(5) << Roots[0];
				else if (i == order - j - 1) cout << left << setw(9) << setprecision(5) << Roots[1];
				else cout << left << setw(9) << 0;
			}
			cout << endl;
		}
	}
}
void XMatrix::getBackNorm()
{
	cout << "\n Our norm ||A*A^(-1) - I|| = " << abs(x*Roots[0] + y*Roots[1] - 1) + abs(x*Roots[1] + y*Roots[0]) << endl;
}
double XMatrix::getTau(vector<double>& v1, vector<double>& v2)
{
	double tau1 = 0, tau2 = 0, el1, el2;
	for (int i = 0; i < 2; i++) {
		el1 = v1[i];
		el2 = v2[i];
		tau1 += el1 * el2;
		tau2 += el1 * el1;
	}
	return tau1/tau2;
}
double XMatrix::getResidual(vector<double> &v1, vector<double> &v2) {
	double residual = abs(v1[0] - v2[0]), element;
	for (int i = 1; i < 2; i++) {
		element = abs(v1[i] - v2[i]);
		if (element > residual) residual = element;
	}
	return residual;
}



void XMatrix::gmres() {
	double eps = 0.1;
	cout << "Please, enter precision: ";
	cin >> eps;
	double tau = 0;
	double residual = 0;
	vector<double> rv(2, 1);
	Roots = rv;
	VSol = rv;
	VSol[1] = 0;
	Roots[0] = 1;
	vector<double> PRoots = Roots;
	vector<double> Arv(2, 0);
	vector<double> Ax(2, 0);
		do {
			//getting rv
			for (int i = 0; i < 2; i++) {
				Ax[i] = x*PRoots[i] + y*PRoots[2 - i - 1];
				rv[i] = Ax[i] - VSol[i];
			}
			//getting Arv
			for (int i = 0; i < 2; i++) {
				Arv[i] = x*rv[i] + y*rv[2 - i - 1];
			}
			//getting tau
			tau = getTau(Arv, rv);
			for (int i = 0; i < 2; i++) {
				Roots[i] = PRoots[i] - tau*rv[i];
			}
			residual = getResidual(Ax, VSol);
			PRoots = Roots;
			errorsVector.push_back(residual);
		} while (residual > eps);
}

void XMatrix::getInfIteration()
{
		cout << "\n~`!@#$%^&*()_+/*-+?][{}!@#$%^&*()_!@#$%^&*()!@#$%^&*(\nNumber of iterations = "
			<< errorsVector.size() << endl << "errors table: {\n";
		for (int i = 0; i < errorsVector.size(); i++) {
			cout << "\t" << setprecision(17) << errorsVector[i] << endl;
		}
		cout << "}\n";
		cout << "\n~`!@#$%^&*()_ +/*-+?][{}!@#$%^&*()_!@#$%^&*()!@#$%^&*(\n";
	
}

int main()
{
	ThridiagMatrix matrix;
	matrix.genMat();
	matrix.showMat();
	matrix.genVSol();
	matrix.Thomas();
	system("pause");
	return 0;
}
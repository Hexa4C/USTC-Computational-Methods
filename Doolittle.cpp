#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

int main(){
	string inpath = "inputs/Doolittle.txt", outpath = "outputs/Doolittle.txt";
	int N;
	ifstream fin;
	ofstream fout;
	fin.open(inpath);
	fout.open(outpath);
	fin >> N;
	vector<vector<double>> A(N, vector<double>(N, 0));
	vector<vector<double>> U(N, vector<double>(N, 0));
	vector<vector<double>> L(N, vector<double>(N, 0));
	vector<double> b(N, 0);
	vector<double> y(N, 0);
	vector<double> x(N, 0);
	for (int i = 0; i < N; i ++) {
		L[i][i] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fin >> A[i][j];
		}
		fin >> b[i];
	}
	for (int k = 0; k < N; k ++) {
		for (int j = k; j < N; j ++) {
			U[k][j] = A[k][j];
			for (int r = 0; r < k; r ++) {
				U[k][j] -= L[k][r] * U[r][j];
			}
		}
		for (int i = k + 1; i < N; i ++) {
			L[i][k] = A[i][k];
			for (int r = 0; r < k; r ++) {
				L[i][k] -= L[i][r] * U[r][k];
			}
			L[i][k] = L[i][k] / U[k][k];
		}
	}
	for (int i = 0; i < N; i++)
	{
		y[i] = b[i];
		for (int j = 0; j < i; j++)
		{
			y[i] -= L[i][j] * y[j];
		}
	}
	for (int i = N - 1; i >= 0; i --) {
		x[i] = y[i];
		for (int j = i + 1; j < N; j ++) {
			x[i] -= U[i][j] * x[j];
		}
		x[i] = x[i] / U[i][i];
	}
	
	for (int i = 0; i < N; i ++) {
		fout << x[i] << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
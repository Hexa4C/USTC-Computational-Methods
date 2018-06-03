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
	string inpath = "inputs/MSimpson.txt", outpath = "outputs/MSimpson.txt";
	int N;
	ifstream fin;
	ofstream fout;
	fin.open(inpath);
	fout.open(outpath);
	fin >> N;
	int M = N / 2;
	vector<double> x(N + 1, 0);
	vector<double> y(N + 1, 0);
	double S;
	for (int i = 0; i < N + 1; i ++) {
		fin >> x[i] >> y[i];
	}
	fin.close();
	double h = (x[N] - x[0]) / N;
	double sum = 0;
	sum += y[0];
	sum += y[N];
	for (int i = 0; i < M; i ++) {
		sum += 4 * y[2 * i + 1];
	}
	for (int i = 1; i < M; i ++) {
		sum += 2 * y[2 * i];
	}
	S = sum * h / 3;
	fout << S;
	fout.close();
	return 0;
}
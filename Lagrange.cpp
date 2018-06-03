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
	string inpath = "inputs/Lagrange.txt", outpath = "outputs/Lagrange.txt";
	int N;
	ifstream fin;
	ofstream fout;
	fin.open(inpath);
	fout.open(outpath);
	fin >> N;
	vector<double> x(N + 1, 0);
	vector<double> y(N + 1, 0);
	double ax, fx;
	for (int i = 0; i < N + 1; i ++) {
		fin >> x[i] >> y[i];
	}
	fin >> ax;
	fin.close();
	fx = 0;
	for (int i = 0; i < N + 1; i ++) {
		double tmp = 1;
		for (int j = 0; j < i; j ++) {
			tmp = tmp * (ax - x[j]) / (x[i] - x[j]);
		}
		for (int j = i + 1; j <  N + 1; j ++) {
			tmp = tmp * (ax - x[j]) / (x[i] - x[j]);
		}
		fx = fx + tmp * y[i];
	}
	fout << fx << endl;
	fout.close();
	return 0;
}
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main() {
	ifstream fin("stairs.inp");
	ofstream fout("stairs.out");
	int layer;
	int cnt = 0;
	fin >> layer;

	while (cnt < layer) {
		double total, start, stairs;
		fin >> total >> start >> stairs;
		fout << (int)ceil(stairs / (total - 1)) << endl;
		cnt++;
	}
	fin.close();
	fout.close();
}

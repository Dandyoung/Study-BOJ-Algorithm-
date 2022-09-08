#include <iostream>
#include <fstream>
using namespace std;


int main() {
	ifstream fin("C:/Users/이영우/Desktop/sampleData3/1.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData3/test.out");
	int layer;
	int total, start, stairs;
	int cnt = 0;
	fin >> layer;
	while (cnt < layer) {
		fin >> total >> start >> stairs;
		int result = 0;
		result = (stairs / (total - 1)) + 1;
		cout << result << endl;
		cnt++;
	}


}

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int array[1000001];

int main() {
	ifstream fin("C:/Users/이영우/Desktop/sampleData11/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData11/test.out");
	
	int layer;
	fin >> layer;
	int cnt = 0;

	while (cnt < layer) {
		int p, k, s;
		fin >> p >> k >> s;
		cout << p << " " << k << " " << s << endl;


		// ex ) 4 6 37일떄 37을 4로 나누면 9이고, 37 - 9 = 28이되어 4의 배수니까 무조건 -1
		// 2 5 35가 예외
		// ee


		cnt++;
	}

	fin.close();
	fout.close();
}
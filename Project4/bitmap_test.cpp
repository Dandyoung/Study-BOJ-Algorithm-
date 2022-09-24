#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>


#DEFINE B 200
#DEFIND D 200
using namespace std;

int main() {

	ifstream fin("C:/Users/이영우/Desktop/sampleData8/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData8/test.out");
	
	vector <int> v;
	string str;


	while (true) {
		char c;
		fin >> c;
		if (c == '#') {
			cout << "disable";
			break;
		}
		cout << c << " ";

		if (c == 'B') {

		}
		else if (c == 'D') {

		}
		
	}


	fin.close();
	fout.close();
}
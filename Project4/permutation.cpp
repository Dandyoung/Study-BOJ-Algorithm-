#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;
map<int, int> m;

int main(void){
	ifstream fin("C:/Users/이영우/Desktop/sampleData7/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData7/test.out");

	int layer;
	fin >> layer;
	int cnt = 0;

	while (cnt < layer) {
		int size;
		fin >> size;
		vector <int> v;
		vector <int> v2;
		for (int i = 0; i < size; i++) {
			int a;
			fin >> a;
			v.push_back(a);
			v2.push_back(-1);
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		int cvmax = 0;
		int cvmax_index = 0;
		for (int i = 0; i < v.size(); i++) {
			if (cvmax <= v[i]) {
				cvmax = v[i];
				cvmax_index = i;
			}
		}
		cout << endl;
		cout << " 최대값 : " << cvmax << endl;
		cout << " 최대값 인덱스 : " << cvmax_index << endl;
		v2[cvmax_index] = 0;
		int start = 0;
		int end = size;
		
		cout << cvmax_index - start << " " << end - cvmax_index << endl;
		
		for (int i = 0; i < v.size(); i++) {
			if (v2[1] != -1) {
				v2[0] = v2[1];
			}
			if (v2[size - 1] != -1) {
				v2[size - 1] = v2[size];
			}
		}
		


		cout << endl;
		cnt++;

	}

	fin.close();
	fout.close();

}
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void){
	ifstream fin("permutation.inp");
	ofstream fout("permutation.out");

	int layer;
	fin >> layer;
	int cnt = 0;
	while (cnt < layer) {
		vector <int> v;
		vector <int> qqq;
		vector <int> qqq2;
		int size;
		fin >> size;
		for (int i = 0; i < size; i++) {
			int a;
			fin >> a;
			v.push_back(a);
			qqq.push_back(0);
			qqq2.push_back(0);
		}

		int start = 0;
		for (int i = 0; i < v.size(); i++) {		

			int start = v[i];
			for (int j = i; j < size; j++) {
				if (start < v[j]) {
					break;
				}
				else if (start > v[j]) {
					qqq[j] += 1;
				}
			}
		}

		reverse(v.begin(), v.end());


		int start2 = 0;
		for (int i = 0; i < v.size(); i++) {
			int start2 = v[i];
			for (int j = i; j < size; j++) {
				if (start2 < v[j]) {
					break;
				}
				else if(start2 > v[j]) {
					qqq2[j] += 1;
				}
			}
		}
		reverse(qqq2.begin(), qqq2.end());

		for (int i = 0; i < qqq.size(); i++) {
			qqq[i] += qqq2[i];
		}
		for (int i = 0; i < qqq.size(); i++) {
			fout << qqq[i] << " ";
		}
		fout << '\n';
		cnt++;
	}
	

	fin.close();
	fout.close();

}
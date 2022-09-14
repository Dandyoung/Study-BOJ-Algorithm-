#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ifstream fin("gain.inp");
	ofstream fout("gain.out");
	int layer;
	fin >> layer;
	int cnt = 0;

	while (cnt < layer) {
		int size;
		fin >> size;
		vector <int> v;
		int a;
		for (int i = 0; i < size; i++) {
			fin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());

		int max1 = v.back();
		v.pop_back();
		int max2 = v.back();
		fout << max1 + max2 - (v[0] + v[1]) << endl;
		cnt++;
		v.clear();
	}
	fin.close();
	fout.close();
}
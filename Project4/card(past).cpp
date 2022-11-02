#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("card.inp");
	ofstream fout("card.out");
	int layer;
	fin >> layer;
	
	while (layer--) {
		int size;
		fin >> size;
		vector<int> v;
		for (int i = 0; i < size; i++) {
			int a;
			fin >> a;
			v.push_back(a);
		}
		//cout << " 받아온 벡터 : " << endl;
		//for (int i = 0; i < size; i++) {
		//	cout << v[i] << " ";
		//}
		//cout << endl;

		vector<int> max2(size, 0);
		vector<int> index_check(size, -1);

		for (int i = 0; i < v.size(); i ++) {
			if (i == 0) {
				max2[i] = v[i];
				index_check[i] = 1;
			}
			if (i == 1) {
				max2[i] = v[i];
				index_check[i] = 1;
			}

			if (i == 2) {
				max2[i] = v[i];
			}

			if (i == 3) {
				if (v[i] + v[i - 2] >= v[i] + v[i - 3]) {
					max2[i] = v[i] + v[i - 2];
				}
				else {
					max2[i] = v[i] + v[i - 3];
				}

			}
			if(i == 4){
				int maxmax = 0;
				if (v[i] + max2[i - 2] >= v[i] + max2[i - 3]) {
					maxmax = v[i] + max2[i - 2];
				}
				else {
					maxmax = v[i] + max2[i - 3];
				}

				if (maxmax <= v[i] + max2[i - 4]) {
					maxmax = v[i] + max2[i - 4];
				}
				max2[i] = maxmax;
			}
			if (i == 5) {
				int maxmax = 0;
				if (v[i] + v[i-2] + max2[i-5] >= v[i] + max2[i - 3]) {
					maxmax = v[i] + v[i - 2] + max2[i - 5];
				}
				else {
					maxmax = v[i] + max2[i - 3];
				}

				if (maxmax <= v[i] + max2[i - 4]) {
					maxmax = v[i] + max2[i - 4];
				}

				max2[i] = maxmax;
				//cout << "max 값 : " << maxmax << endl;

			}
			if (i >= 6) {
				int maxmax = 0;
				if (v[i] + max(v[i - 2] + max2[i - 6], v[i-2] + max2[i - 5]) >= v[i] + max2[i - 3]) {
					maxmax = v[i] + max(v[i - 2] + max2[i - 6], v[i - 2] + max2[i - 5]);
				}
				else {
					maxmax = v[i] + max2[i - 3];
				}

				if (maxmax <= v[i] + max2[i - 4]) {
					maxmax = v[i] + max2[i - 4];
				}

				max2[i] = maxmax;
				//cout << "max 값 : " << maxmax << endl;

			}

		}
		//cout << "최대값 배열 : " << endl;
		//for (int i = 0; i < size; i++) {
		//	cout << max2[i] << " ";
		//}
		int a = max2.back();
		fout << a << endl;

	}

	fin.close();
	fout.close();

}
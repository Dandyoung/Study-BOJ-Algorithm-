#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("C:/Users/이영우/Desktop/sampleData13/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData13/test.out");
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
		cout << " 받아온 벡터 : " << endl;
		for (int i = 0; i < size; i++) {
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int> max(size, 0);
		vector<int> index_check(size, -1);

		for (int i = 0; i < v.size(); i ++) {
			if (i == 0) {
				max[i] = v[i];
				index_check[i] = 1;
			}
			if (i == 1) {
				max[i] = v[i];
				index_check[i] = 1;
			}

			if (i == 2) {
				max[i] = v[i];
			}

			if (i == 3) {
				if (v[i] + v[i - 2] >= v[i] + v[i - 3]) {
					max[i] = v[i] + v[i - 2];
				}
				else {
					max[i] = v[i] + v[i - 3];
				}

			}

			if (i > 3) {
				//cout << i+1 << " 개 일때"<< endl;
				int index = i;
				int time = i / 2;

				int maxmax = v[i] + v[i-2];
				//cout << "들어오기 전 max 값 : " << maxmax << endl;
				int cnt = 0;
				for (int j = i-2; j >= 0; j--) {
					if (cnt == 3) {
						break;
					}
					if (v[i] + max[j] >= maxmax) {
						maxmax = v[i] + max[j];
					}
					cnt++;
				}

				max[i] = maxmax;

			}
		}
		cout << "최대값 배열 : " << endl;
		for (int i = 0; i < size; i++) {
			cout << max[i] << " ";
		}
		cout << endl;



	}



	fin.close();
	fout.close();

}
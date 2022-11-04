#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int m = 5;
int layer;
int run_size;
vector <int> val_v;
vector <int> buf_v;
vector <int> frz_v(5, 0);
vector <int> run_v;
vector <int> real_v;
vector <int> size_check;


int main() {
	ifstream fin("C:/Users/이영우/Desktop/과제1_설명자료/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/과제1_설명자료/test.out");

	fin >> layer;

	while (layer--) {
		int run = 0;
		int space;
		fin >> space;
		for (int i = 0; i < space; i++) {
			int a;
			fin >> a;
			val_v.push_back(a);
		}

		for (int i = 0; i < m; i++) {
			buf_v.push_back(val_v[i]);
		}

		for (int i = 0; i < m; i++) {
			val_v.erase(val_v.begin());
		}

		reverse(val_v.begin(), val_v.end());

		int check = 1;
		while (!val_v.empty()) {
			vector <int> cc;
			int idx = 0;
			for (int i = 0; i < frz_v.size(); i++) {
				if (frz_v[i] == 0) {
					cc.push_back(buf_v[i]);
				}
			}

			int min = *min_element(cc.begin(), cc.end());
			cc.clear();
			for (int i = 0; i < buf_v.size(); i++) {
				if (buf_v[i] == min) {
					idx = i;
				}
			}

			run_v.push_back(min);
			buf_v[idx] = val_v.back();
			val_v.pop_back();

			if (min > buf_v[idx]) {
				frz_v[idx] = 1;
				int cnt = 0;
				for (int i = 0; i < frz_v.size(); i++) {
					if (frz_v[i] == 1) {
						cnt++;
					}
				}
				if (cnt == 5) {
					for (int i = 0; i < frz_v.size(); i++) {
						frz_v[i] = 0;
					}
					// 나가기 전 정렬
					sort(run_v.begin(), run_v.end());
					run_size = run_v.size();
					size_check.push_back(run_size);
					for (int i = 0; i < run_v.size(); i++) {
						real_v.push_back(run_v[i]);
					}
					check++;
					run_v.clear();
					continue;
				}
			}
			else {
				continue;
			}
		}

		// 더이상 받아올 값이 없는 상황 처리.
		vector <int> last;
		for (int i = 0; i < buf_v.size(); i++) {
			if (frz_v[i] == 0) {
				run_v.push_back(buf_v[i]);
			}
			else {
				last.push_back(buf_v[i]);
			}
		}
		// 나가기 전 정렬
		sort(run_v.begin(), run_v.end());

		run_size = run_v.size();
		size_check.push_back(run_size);
		for (int i = 0; i < run_v.size(); i++) {
			real_v.push_back(run_v[i]);
		}
		run_v.clear();
		for (int i = 0; i < last.size(); i++) {
			run_v.push_back(last[i]);
		}
		// 나가기 전 정렬
		sort(run_v.begin(), run_v.end());
		run_size = run_v.size();
		size_check.push_back(run_size);
		for (int i = 0; i < run_v.size(); i++) {
			real_v.push_back(run_v[i]);
		}
		cout << size_check.size() << endl;
		//size_check 벡터는 초기화 안해줘도됨
		reverse(real_v.begin(), real_v.end());

		for (int i = 0; i < size_check.size(); i++) {
			int qq = size_check[i];
			for (int i = 0; i < qq; i++) {
				int a = real_v.back();
				cout << a << " ";
				real_v.pop_back();
			}
			cout << endl;
		}
		val_v.clear();
		buf_v.clear();
		run_v.clear();
		real_v.clear();
		size_check.clear();
		for (int i = 0; i < frz_v.size(); i++) {
			frz_v[i] = 0;
		}
	}

	fin.close();
	fout.close();
}
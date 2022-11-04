#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int m = 5;
int layer;

vector <int> val_v;
vector <int> buf_v;
vector <int> frz_v(5, 0);
vector <int> written_v;
vector <int> run_v;


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

		cout << "현재 val 상태 : ";
		for (int i = 0; i < val_v.size(); i++) {
			cout << val_v[i] << " ";
		}
		cout << endl;

		cout << "현재  buf 상태 : ";
		for (int i = 0; i < buf_v.size(); i++) {
			cout << buf_v[i] << " ";
		}

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
					if(frz_v[i] == 1) {
						cnt++;
					}
				}
				if (cnt == 5) {
					break;
				}
			}
			else {
				continue;
			}
		}



	}



	fin.close();
	fout.close();
}
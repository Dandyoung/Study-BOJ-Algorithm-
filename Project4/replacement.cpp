#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int m = 5;
int layer; // 총 testcase 갯수
int run_size; // 각 run 길이를 저장하여 출력을 위한 변수
vector <int> val_v;  //값을 받아오는 vector 
vector <int> buf_v;  // 버퍼 vector
vector <int> frz_v(5, 0); // 동결여부 검사
vector <int> run_v; // 나가기 전 run vector 그냥 전역에서 사용하는 걸로 
vector <int> real_v; // 실제 모든 값들이 저장되는 1D vector  
vector <int> size_check; // 각 run 길이들이 저장되는 vector


int main() {
	ifstream fin("C:/Users/이영우/Desktop/과제1_설명자료/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/과제1_설명자료/test.out");

	fin >> layer;

	while (layer--) {
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
					// 나가기 전 혹시 모르니 sort
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
		// frozen, not frozen을 판단하기 위해 사용하는 임시 vectors
		for (int i = 0; i < buf_v.size(); i++) {
			if (frz_v[i] == 0) {
				run_v.push_back(buf_v[i]);
			}
			else {
				last.push_back(buf_v[i]);
			}
		}
		// 나가기 전 정렬, 여기는 sort를 꼭 해줘야함
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
		// 나가기 전 정렬, 여기도 sort를 꼭 해줘야함
		sort(run_v.begin(), run_v.end());
		run_size = run_v.size();
		size_check.push_back(run_size);
		for (int i = 0; i < run_v.size(); i++) {
			real_v.push_back(run_v[i]);
		}
		// 런 갯수 출력
		cout << size_check.size() << endl;
		//size_check 벡터는 초기화 안해줘도됨
		reverse(real_v.begin(), real_v.end());

		// 각 런 상태 출력
		for (int i = 0; i < size_check.size(); i++) {
			int qq = size_check[i];
			for (int i = 0; i < qq; i++) {
				int a = real_v.back();
				cout << a << " ";
				real_v.pop_back();
			}
			cout << endl;
		}

		// 초기화
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
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int m = 5;
int layer;

vector <int> val_v;
vector <int> buf_v;
vector <int> frz_v(5,0);

vector <int> run_v;


int main() {
	ifstream fin("C:/Users/�̿���/Desktop/����1_�����ڷ�/test.inp");
	ofstream fout("C:/Users/�̿���/Desktop/����1_�����ڷ�/test.out");

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

		cout << "���� val ���� : ";
		for (int i = 0; i < val_v.size(); i++) {
			cout << val_v[i] << " ";
		}
		cout << endl;

		cout << "����  buf ���� : ";

		for (int i = 0; i < m; i++) {
			cout << buf_v[i] << " ";
		}
		cout << endl;

		cout << "����  frz ���� : ";

		for (int i = 0; i < m; i++) {
			cout << frz_v[i] << " ";
		}
		cout << endl;
		
		while (true) {
			int cnt = 0;
			for (int i = 0; i < frz_v.size(); i++) {
				if (frz_v[i] == 1) {
					cnt++;
				}
			}
			if (cnt == 5) {
				break;
			}
			vector <int> cc;
			for (int i = 0; i < frz_v.size(); i++) {
				if (frz_v[i] != 1) {
					cc.push_back(buf_v[i]);
				}
			}

			int min = *min_element(cc.begin(), cc.end());
			int min_idx = min_element(cc.begin(), cc.end()) - cc.begin();
			cc.clear();
			cout << "�ּҰ� : " << min << " �ּҰ� �ε��� : " << min_idx << endl;

			run_v.push_back(buf_v[min_idx]);
			buf_v[min_idx] = val_v.back();  // ���� ���ڵ� ����
			val_v.pop_back();
			cout << endl;

			if (buf_v[min_idx] < min) {
				frz_v[min_idx] = 1;
			}
		}

	}



	fin.close();
	fout.close();
}
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int m = 5;
int layer; // �� testcase ����
int run_size; // �� run ���̸� �����Ͽ� ����� ���� ����
vector <int> val_v;  //���� �޾ƿ��� vector 
vector <int> buf_v;  // ���� vector
vector <int> frz_v(5, 0); // ���Ῡ�� �˻�
vector <int> run_v; // ������ �� run vector �׳� �������� ����ϴ� �ɷ� 
vector <int> real_v; // ���� ��� ������ ����Ǵ� 1D vector  
vector <int> size_check; // �� run ���̵��� ����Ǵ� vector


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
					// ������ �� Ȥ�� �𸣴� sort
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

		// ���̻� �޾ƿ� ���� ���� ��Ȳ ó��.
		vector <int> last;
		// frozen, not frozen�� �Ǵ��ϱ� ���� ����ϴ� �ӽ� vectors
		for (int i = 0; i < buf_v.size(); i++) {
			if (frz_v[i] == 0) {
				run_v.push_back(buf_v[i]);
			}
			else {
				last.push_back(buf_v[i]);
			}
		}
		// ������ �� ����, ����� sort�� �� �������
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
		// ������ �� ����, ���⵵ sort�� �� �������
		sort(run_v.begin(), run_v.end());
		run_size = run_v.size();
		size_check.push_back(run_size);
		for (int i = 0; i < run_v.size(); i++) {
			real_v.push_back(run_v[i]);
		}
		// �� ���� ���
		cout << size_check.size() << endl;
		//size_check ���ʹ� �ʱ�ȭ �����൵��
		reverse(real_v.begin(), real_v.end());

		// �� �� ���� ���
		for (int i = 0; i < size_check.size(); i++) {
			int qq = size_check[i];
			for (int i = 0; i < qq; i++) {
				int a = real_v.back();
				cout << a << " ";
				real_v.pop_back();
			}
			cout << endl;
		}

		// �ʱ�ȭ
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
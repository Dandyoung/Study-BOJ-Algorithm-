#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int array[1000001];

int main() {
	ifstream fin("C:/Users/�̿���/Desktop/sampleData11/2.inp");
	ofstream fout("C:/Users/�̿���/Desktop/sampleData11/test.out");

	int layer;
	fin >> layer;
	int cnt = 0;

	while (cnt < layer) {
		int p, k, s;
		fin >> p >> k >> s;
		//cout << p << " " << k << " " << s << endl;


		// ex ) 4 6 37�ϋ� 37�� 4�� ������ 9�̰�, 37 - 9 = 28�̵Ǿ� 4�� ����ϱ� ������ -1
		// 2 5 35�� ����
		// ee

		int a = k + 1;
		int qwe = s % a;
		if (qwe == 0) {
			cout << "���� ���̱�" << endl;

		}
		else if (qwe != 0) {
			if (qwe % p== 1){
				cout << "���� ���̱�" <<endl;
				}
			else {
				cout << "���� �̱� " << endl;
			}
			////cout << " ���� �̱� " << endl;
		}
		cnt++;
	}

	fin.close();
	fout.close();
}
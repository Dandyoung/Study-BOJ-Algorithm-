#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> rotate(int size, vector<vector<char>> v) {
	vector<vector<char>> new_v(size, vector<char>(size, 0));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			// 시계방향 90도
			new_v[i][j] = v[size - j - 1][i];
			// 반시계방향 90도
			//newGraph[i][j] = graph[j][size - j - 1];
		}
	}
	return new_v;
}

int main() {
	ifstream fin("spinslide.inp");
	ofstream fout("spinslide.out");
	int layer; // 총 testcase 갯수
	int size; // 판 크기
	int count; // spinslide 횟수
	char a; // fin 받아올 char 변수
	vector<vector<char>> v1; // 2차원 벡터
	vector <char> v2; // 2차원 벡터 만들때 쓸 1차원 벡터

	fin >> layer;

	for (int i = 0; i < layer; i++) {
		v1.clear();
		fin >> size >> count;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				fin >> a;
				v2.push_back(a);
				//cout << a;
			}
			v1.push_back(v2);
			v2.clear();
			//cout << endl;
		}

		int cnt = 0;
		while (cnt < count) {
			char c = '.';
			vector<vector<char>> v3;
			vector <char> v4;
			v3.clear();
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (v1[i][j] != '.') {
						v4.push_back(v1[i][j]);
						//v4.push_back(c);
					}
				}
				v3.push_back(v4);
				v4.clear();
			}

			for (int i = 0; i < size; i++) {
				while (v3[i].size() < size) {
					v3[i].insert(v3[i].begin(), c);
					if (v3[i].size() == size) {
						break;
					}
				}
			}

			v3 = rotate(size, v3);


			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					v1[i][j] = v3[i][j];
				}
			}
			cnt++;
		}
		fout << "Case #" << i + 1 << ":" << endl;
		for (vector<char> vec : v1) { //2차원벡터 출력
			for (char n : vec) {
				fout << n;
			}
			fout << endl;
		}
		fout << endl;
	}
	fin.close();
	fout.close();
}
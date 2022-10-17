#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int C, M, N, K;
int Zarray[101][101][101];
int Rarray[101][101];
int Darray[101][101];

void prePro() {
	ifstream fin("C:/Users/이영우/Desktop/sampleData14/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData14/test.out");
	fin >> C;
	while (C--) {
		fin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int a;
			int b;
			fin >> a >> b;
			for (int i = 0; i < K; i++) {
				Zarray[a][b][i] = -1;
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N - 1; j++) {
				int c;
				fin >> c;
				Rarray[i][j] = c;
			}
		}
		for (int i = 0; i < M - 1; i++) {
			for (int j = 0; j < N; j++) {
				int d;
				fin >> d;
				Darray[i][j] = d;
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N - 1; j++) {
				cout << Rarray[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < M - 1; i++) {
			for (int j = 0; j < N; j++) {
				cout << Darray[i][j] << " ";
			}
			cout << endl;
		}
	}
}

//
int main() {

	prePro();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k = K; k++) {
				if (Zarray[i][j][k] != -1) {

				}
			}
		}
	}
	for (int i = 0; i < N; i++) {

	}
}
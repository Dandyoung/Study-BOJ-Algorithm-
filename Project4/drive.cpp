#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int layer;
int N, M, G, L;


int main() {
	ifstream fin("C:/Users/이영우/Desktop/sampleData20/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData20/test.out");
	fin >> layer;
	while (layer--) {
		fin >> N >> M >> G >> L;

		vector < vector <int> > min_v(N, vector <int>(M, 0));
		vector< vector<int>> v;

		for (int i = 0; i < N; i++) {
			vector <int> v2;
			for (int j = 0; j < N; j++) {
				int a;
				fin >> a;
				v2.push_back(a);
			}
			v.push_back(v2);
			v2.clear();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		min_v[0][1] = v[0][1];
		
		for (int i = 1; i < M; i++) {
			min_v[0][i] = min_v[0][i - 1] + v[0][i - 1];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << min_v[i][j] << " ";
			}
			cout << endl;
		}
		
		vector< vector<int>> v3;
		for (int i = 0; i < M; i++) {
			vector <int> v4;
			for (int j = 0; j < M; j++) {
				int a;
				fin >> a;
				v4.push_back(a);
			}
			v3.push_back(v4);
			v4.clear();
		}

		for (int i = 0; i < N-1; i++) {
			for (int j = 0; j < M; j++) {
				cout << v3[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 1; i < N; i++) {
			min_v[i][0] = min_v[i-1][0] + v3[i-1][0];
		}

		cout << "------------초기값 세팅 끝-----------" << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << min_v[i][j] << " ";
			}
			cout << endl;
		}


		
	}

	fin.close();
	fout.close();
}
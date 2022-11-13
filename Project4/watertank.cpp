#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

ifstream fin("C:/Users/�̿���/Desktop/sampleData21/test.inp");
ofstream fout("C:/Users/�̿���/Desktop/sampleData21/test.out");
int A[10][10];
int B[10][10];
int layer, N, M, H;

vector <tuple<int, int, int >> adj[1000][1000];


int main() {
	fin >> layer;
	while (layer--) {
		fin >> N >> M >> H;
        // ���ʿ� grid�� [0][0]�� ������ ����. �װ� �� ���ҵ�?
        for (int i = 1; i <= N + 1; i++) {
            for (int j = 1; j <= M; j++) {
                fin >> A[i][j];
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M + 1; j++)
                fin >> B[i][j];
        }
 
        for (int i = 1; i <= N + 1; i++) {
            for (int j = 1; j <= M; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M + 1; j++) {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }

	}

}
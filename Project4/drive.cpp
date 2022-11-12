#include <iostream>   
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

int min_dp[101][101][202][2];
int layer, M, N, L, G;
int row[101][101];
int col[101][101];

ifstream fin("drive.inp");
ofstream fout("drive.out");


void dp_solve() {
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            int maxturn = 2 * max(M, N);
            for (int k = 1; k <= maxturn; k++) {
                min_dp[i][j][k][0] = min(min_dp[i][j - 1][k][0] + row[i][j - 1], min_dp[i][j - 1][k - 1][1] + row[i][j - 1]);//왼쪽에서: min(왼->왼, 위-> 왼)
                min_dp[i][j][k][1] = min(min_dp[i - 1][j][k][1] + col[i - 1][j], min_dp[i - 1][j][k - 1][0] + col[i - 1][j]);//위에에서: min(위->위, 왼->위)
            }
        }
    }

    int maxturn = 2 * max(M, N);
    for (int k = 0; k <= maxturn; k++) {
        if (min_dp[M - 1][N - 1][k][1] <= G || min_dp[M - 1][N - 1][k][0] <= G) {
            int qq = L * (M - 1 + N - 1) + k;
            fout << qq << '\n';
            return;
        }
    }
    fout << -1 << '\n';
    return;
}


int main() {
    fin >> layer;

    while (layer--) {
        fin >> M >> N >> L >> G;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N - 1; j++) {
                fin >> row[i][j];
            }
        }

        for (int i = 0; i < M - 1; i++) {
            for (int j = 0; j < N; j++) {
                fin >> col[i][j];
            }
        }
        // 값 setting
        int maxturn = 2 * max(M, N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k <= maxturn; k++) {
                    for (int l = 0; l < 2; l++) {
                        min_dp[i][j][k][l] = 99999999;
                    }
                }
            }
        }
        //cout << "------------초기값 세팅 끝(1)-----------" << endl;
        min_dp[0][0][0][0] = min_dp[0][0][0][1] = 0;
        for (int i = 1; i < N; i++) {
            min_dp[0][i][0][0] = min_dp[0][i - 1][0][0] + row[0][i - 1];
        }
        for (int i = 1; i < M; i++) {
            min_dp[i][0][0][1] = min_dp[i - 1][0][0][1] + col[i - 1][0];
        }
        //cout << "------------초기값 세팅 끝(2)-----------" << endl;
        dp_solve();
    }

    fin.close();
    fout.close();
}
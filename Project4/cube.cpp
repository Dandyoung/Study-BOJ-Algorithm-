#include <iostream>
#include <fstream>

#define I i-1
#define J j-1
#define K k-1
#define DP dp[I][J][K]=dp[I][K][J]=dp[J][I][K]=dp[J][K][I]=dp[K][I][J]=dp[K][J][I]

int dp[200][200][200];

using namespace std;
void solution_dp() {
	for (int i = 1; i <= 200; ++i) {
		for (int j = i; j <= 200; ++j) {
			for (int k = j; k <= 200; ++k) {
				if (j % i == 0 && k % i == 0) {
					DP = (j / i) * (k / i); continue;
				}
				int result = 100000000;
				for (int x = 1; x <= i / 2; ++x) {
					int tmp = dp[x - 1][J][K] + dp[I - x][J][K];
					if (tmp < result) result = tmp;
				}
				for (int y = 1; y <= j / 2; ++y) {
					int tmp = dp[I][y - 1][K] + dp[I][J - y][K];
					if (tmp < result) result = tmp;
				}
				for (int z = 1; z <= k / 2; ++z) {
					int tmp = dp[I][J][z - 1] + dp[I][J][K - z];
					if (tmp < result) result = tmp;
				}
				DP = result;
			}
		}
	}
}

int main() {
	ifstream fin("cube.inp");
	ofstream fout("cube.out");

	int layer;
	fin >> layer;

	solution_dp();

	while (layer--) {
		int i, j, k;
		fin >> i >> j >> k;
		fout << dp[I][J][K] << '\n';
	}

	fin.close();
	fout.close();
}
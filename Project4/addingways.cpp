#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int n, k;
long long dp[301][301]{ 0, };


int solution(int n, int k) {
	if (dp[n][k] != 0) {
		return dp[n][k];
	}
	else {
		if (n == k) {
			return dp[n][k] = 1;
		}
		else if (k == 1) {
			return dp[n][k] = 1;
		}
		else if (n < k || k < 1 || n < 2) {
			return dp[n][k] = 0;
		}
		else {
			return dp[n][k] = (solution(n - 1, k - 1) + solution(n - k, k)) % 1000000007;
		}
	}
}

int main() {
	ifstream fin("addingways.inp");
	ofstream fout("addingways.out");

	while (true) {
		fin >> n >> k;
		if (n == 0 && k == 0) {
			break;
		}
		solution(n, k);
		fout << dp[n][k] << '\n';
		memset(dp, 0, sizeof(dp));
	}
	fin.close();
	fout.close();
}
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int layer, len;
int value[1001], dp[1001][1001];
//vector <int> v(1001, 0);
//vector <vector <int>> dp(1001, vector <int>(1001, 0));

int go(int left, int right, int turn) {
	if (left > right) return 0;
	if (dp[left][right]) return dp[left][right];

	if (turn % 2) 
		return dp[left][right] = max(value[left] + go(left + 1, right, turn + 1), value[right] + go(left, right - 1, turn + 1));
	else 
		return dp[left][right] = min(go(left + 1, right, turn + 1), go(left, right - 1, turn + 1));
}



int main() {
	ifstream fin("card.inp");
	ofstream fout("card.out");
	
	fin >> layer;

	while (layer--) {
		fin >> len;
		for (int i = 0; i < len; i++) {
			int a;
			fin >> a;
			value[i] = a;
		}
		go(0, len - 1, 1);
		fout << dp[0][len - 1] << '\n';
		memset(dp, 0, sizeof(dp));
	}

	fin.close();
	fout.close();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
#include <math.h>
using namespace std;
vector<int> v(1024), res(1024);
int n;
int cnt = 0;
void go(int now, int depth) {
	if (depth == n) res[now] = v[cnt++]; //마지막값
	else {
		go(now * 2, depth + 1); //왼
		res[now] = v[cnt++]; //현재
		go(now * 2 + 1, depth + 1); //우
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int nn = pow(2, n) - 1;
	for (int i = 0; i < nn; i++) {
		cin >> v[i];
	}
	go(1, 1);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int len = 1;
		for (int j = 0; j < i; j++) len *= 2; //개수
		for (int j = 0; j < len; j++) {
			cout << res[cnt++] << " ";
		}
		cout << "\n";
	}
}
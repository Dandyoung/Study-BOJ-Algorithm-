#include <iostream>
#include <algorithm>

using namespace std;

int a[1000001] = { 0, };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	//cout << "숫자 입력 : ";
	cin >> n;
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + 1;
		if (i % 2 == 0) {
			a[i] = min(a[i], a[i/2] + 1);
		}
		if (i % 3 == 0) {
			a[i] = min(a[i], a[i/3] + 1);
		}
	}
	cout << a[n];
}
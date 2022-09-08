#include<iostream>

using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	int h, w, n = 0;
	int result = 0;
	for (int i = 0; i < cnt; i++) {
		cin >> h >> w >> n;
		int x = n / h + 1;
		int y = n % h;

		if (y == 0) {
			result = h * 100 + (n / h);
		}
		else {
			result = (n % h) * 100 + (n / h) + 1;
		}
		cout << result << endl;
	}
}

#include <iostream>

using namespace std;

int main() {
	int count[42] = {};

	int v;
	for (int i = 0; i < 10; i++) {
		cin >> v;
		count[v % 42]++;
	}
	int result = 0;

	for (int v : count) {
		if (v > 0) {
			result++;
		}
	}
	cout << result;
}
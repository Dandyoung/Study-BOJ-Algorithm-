#include <iostream>


using namespace std;

int selfNum(int a) {
	int sum = a;

	while (a != 0) {
		sum = sum + (a % 10);
		a = a / 10;
	}
	return sum;
}

int main() {
	bool check[10001]{ false }; // bool check array ¼±¾ð

	for (int i = 1; i < 10001; i++) {
		int cc = selfNum(i);
		if (cc < 10001) {
			check[cc] = true;
		}
	}

	for (int i = 1; i < 10001; i++) {
		if (!check[i]) {
			cout << i << endl;
		}
	}
}
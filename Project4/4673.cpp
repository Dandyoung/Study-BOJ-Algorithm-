#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

int main() {
	vector <int> v{1,3,5,7,9,20,31,42,53,64,75,86,97,113};
	int n = 113;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	while (true) {
		int sum = 0;
		int num = 0;
		num = n;
		if (n > 10000) {
			break;
		}
		if (100 < n && n < 1000) {
			for (int i = 0; i < 3; i++) {
				sum += num % 10; // 10으로 나눠서 나머지를 sum에 입력
				num = num / 10; //맨 뒤에 자리수를 없앤다
			}
			n = n + sum;
			cout << n << endl;
		}
		if (n > 1000) {
			for (int i = 0; i < 4; i++) {
				sum += num % 10; // 10으로 나눠서 나머지를 sum에 입력
				num = num / 10; //맨 뒤에 자리수를 없앤다
			}
			n = n + sum;
			if (n > 10000) {
				break;
			}
			cout << n << endl;
		}
	}
}
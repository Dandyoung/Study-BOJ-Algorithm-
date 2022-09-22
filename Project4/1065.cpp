#include <iostream>

using namespace std;


//int ap(int a) {
//	int cnt = 1;
//	int sum = a;
//	
//	int q = 0;
//
//	if (sum <= 10) {
//		q = sum;
//	}
//
//	if (10 < sum && sum <= 100) {
//		int num = 11;
//		while (num < sum) {
//			int qwe = num % 10;
//			cout << "num : " << num << endl;
//
//
//			num++;
//		}
//	
//	}
//
//	return q;
//}

int main() {
	//int b;
	//cin >> b;

	//int zxc = ap(b);
	//cout << zxc << endl;
	int c = 123;
	int f = c / 100;
	int d = c % 10;
	int t = d / 10;
	//int f = c % 100;
	cout << f << " " << t << " " << d;
}
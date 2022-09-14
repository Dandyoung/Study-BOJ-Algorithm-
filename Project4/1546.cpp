#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	double arr[1000] = { 0, };
	int layer;
	cin >> layer;
	for (int i = 0; i < layer; i++) {
		int sub;
		cin >> sub;
		arr[i] = sub;
	}
	int max = 0;
	for (int i = 0; i < layer; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	for (int i = 0; i < layer; i++) {
		arr[i] = arr[i] / max * 100;
	}
	//cout << endl;
	double sum = 0;;
	for (int i = 0; i < layer; i++) {
		sum += arr[i];
		//cout << arr[i] << " ";
	}
	double c;
	c = sum / (double)layer;
	cout << c;
}
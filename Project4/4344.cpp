#include <iostream>
#include <vector>

using namespace std;

int main() {
	int layer;
	vector <int> v;
	vector <int> v2;
	vector <double> v3;
	cin >> layer;
	for (int i = 0; i < layer; i++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			v.push_back(m);
		}
		double sum = 0;
		double avg = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		avg = sum / n;
		//cout << avg << endl;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > avg) {
				v2.push_back(v[i]);
			}
		}
		//for (int i = 0; i < v2.size(); i++) {
		//	cout << v2[i] << " ";
		//}
		cout << fixed;
		cout.precision(3);
		double a = (double)v2.size() / (double)v.size();
		v3.push_back(a);
		//cout << a*100.0 <<"%";
		v.clear();
		v2.clear();
	}
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] * 100 << "%" << endl;
	}
}
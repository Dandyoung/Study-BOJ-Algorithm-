#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

// 생각보다 오래걸림
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int layer;
	vector <string> v;
	vector <int> v2;
	cin >> layer;
	
	for (int i = 0; i < layer; i++) {
		string s;
		cin >> s;
		v.push_back(s);
		//for (int i = 0; i < v.size(); i++) {
		//	cout << v[i] << " ";
		//}
	}
		int result1 = 0;
		//cout << "ÀÌ°Ô¹º¤§[ : "<< v.size()<< endl;
		for (int i = 0; i < v.size(); i++) {
			char separator = 'X';
			std::istringstream iss(v[i]);
			std::string str_buf;
			int result2 = 0;
			while (getline(iss, str_buf, separator)) {
				//std::cout << str_buf << std::endl;
				int sum = 0;
				for (int i = 0; i <str_buf.size(); i++) {
					sum += i + 1;
					//cout << "ÇÕ°è : " << sum << endl;
				}
				result2 += sum;
			}
			result1 = result2;
			v2.push_back(result1);
		}
		for (int i = 0; i < v2.size(); i++) {
			cout << v2[i] << endl;
		}
}

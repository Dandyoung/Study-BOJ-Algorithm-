#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ifstream fin("test.inp");
	ofstream fout("test.out");
	map<int, string> m_f;
	map<int, string> m_l;
	map<string, int> m_s;
	vector<int> p_num;
	int count;
	int len_first = 0;
	int* ptr = &len_first;
	fin >> count;

	for (int i = 0; i < count; i++) {
		int id;
		string first, last;
		fin >> id >> first >> last;
		//cout << first.length() << endl;
		p_num.push_back(id);
		m_f.insert(make_pair(id, first));
		m_l.insert(make_pair(id, last));
		

		if (len_first < first.length()) {
			*ptr = first.length();
		}

		if (m_s.find(last) == m_s.end()) {
			m_s.insert(make_pair(last, 1));
		}
		else {
			m_s.find(last)->second += 1; // map 전체에 접근하는 것과, map에서 찾은애랑 접근하는 것은 다름.
		}
	}

	for (auto const& pair : m_f) {
		fout.fill('0');
		fout.width(5);
		fout << std::right << pair.first << ' ';
		fout.width(len_first + 1);
		fout.fill(' ');
		fout << std::left << pair.second;

		//for (auto const& pair : m_l) {
		//	cout << std::left << pair.second << endl;
		//}
		//cout << " " << pair.first << " " << pair.second << endl;
		int key = pair.first;
		string s = m_l.at(key);
		fout << s << endl;
	}
	fout << endl;
	for (auto const& pair : m_s) {
		if (pair.second > 1) {
			fout << pair.first << " " << pair.second << endl;
		}
	}
	//delete ptr; delete object 
	fin.close();
	fout.close();
}
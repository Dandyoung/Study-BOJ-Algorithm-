#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main() {
	ifstream fin("coin.inp");
	ofstream fout("coin.out");

	int layer;
	fin >> layer;
	
	int cnt = 0;
	while (cnt < layer) {
		int a = 2;
		int b = 3;
        vector <int> v;
        vector <int> v2;

        for (int i = 0; i < 3; i++) {
            int bucket;
            fin >> bucket;
            v.push_back(bucket % 4);
            v2.push_back(bucket);
        }

        int zero_cnt = 0;
        int one_cnt = 0;
        int two_cnt = 0;
        int thr_cnt = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                zero_cnt++;
            }
            if (v[i] == 1) {
                one_cnt++;
            }
            if (v[i] == 2) {
                two_cnt++;
            }
            if (v[i] == 3) {
                thr_cnt++;
            }
        }

        fout << "(" << v2[0] << " " << v2[1] << " " << v2[2] << ") : ";
        if (zero_cnt == 2 && one_cnt == 1) {
            fout << "-1" << '\n';
        }
        else if (zero_cnt == 1 && two_cnt == 2) {
            fout << "-1" << '\n';
        }
        else if (one_cnt == 3) {
            fout << "-1" << '\n';
        }
        else if (zero_cnt == 1 && thr_cnt == 2) {
            fout << "-1" << '\n';
        }
        else if (thr_cnt == 1 && two_cnt == 1 && one_cnt == 1) {
            fout << "-1" << '\n';
        }
        else {
            fout << "1" << '\n';
        }
        cnt++;
	}


	fin.close();
	fout.close();
}
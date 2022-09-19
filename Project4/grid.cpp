#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream fin("C:/Users/ÀÌ¿µ¿ì/Desktop/sampleData5 (1)/test.inp");
	ofstream fout("grid.out");

	long long layer;
	fin >> layer;

	long long cnt = 0;
    while (cnt < layer) {
        long long col, row, paint;
        fin >> col >> row >> paint;
        vector <long long> p_v;
        for (int i = 0; i < paint; i++) {
            long long a;
            fin >> a;
            p_v.push_back(a);
        }
        int flag = 0;
        if (paint * 2 <= row || paint * 2 <= col) {
            flag = 1;
        }

        long long qwe = 0;
        long long zxc = 0;

        for (int i = 0; i < p_v.size(); i++) {
            if (p_v[i] / row >= 2) {
                qwe += p_v[i] / row;
            }
            if (p_v[i] / col >= 2) {
                zxc += p_v[i] / col;
            }
        }

        if (flag == 1) {
            if (qwe >= col || zxc >= row) {
                cout << "Yes" << endl;
            }
        }
        else {
            if (qwe >= col || zxc >= row) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        //if(qwe >= col || zxc >= row){
        //    if (flag == 1) {
        //        cout << "Yes" << endl;
        //    }
        //    else {
        //        cout << "No" << endl;
        //    }
        //}
        //else {
        //    cout << "No" << endl;
        //}
        cnt++;
    }
    fin.close();
    fout.close();
}
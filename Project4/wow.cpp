#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int p, k, s;
vector <vector<bool>> v(1000001,vector <bool> (8, false));


bool winCheck(int idx, int stair) {
    if (idx != 0 && idx % p == 0) {
        return false;
    }
    for (int i = 1; i <= k; i++) {
        if (i != stair) {
            if (v[idx][i]) {
                return false;
            }
        }
    }
    return true;
}

void coinCheck() {
    for (int i = 1; i <= s; i++) {
        if (i % p != 0 || i == s) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    v[i][j] = winCheck(i - j, j);
                }
            }
        }
    }
}
int chulOryoung() {
    for (int i = 1; i <= k; i++) {
        if (v[s][i]) {
            return s - i;
        }
    }
    return -1;
}



int main() {
    ifstream fin("C:/Users/이영우/Desktop/sampleData11/test.inp");
    ofstream fout("C:/Users/이영우/Desktop/sampleData11/test.out");
    int layer;
    fin >> layer;

    int cnt = 0;
    while (cnt < layer) {
        //int p, k, s;
        fin >> p >> k >> s;
        coinCheck();
        cout << chulOryoung() << endl;
        cnt++;
    }


    //int cnt = 0;
    //while (cnt < layer) {

    //}

    return 0;
}
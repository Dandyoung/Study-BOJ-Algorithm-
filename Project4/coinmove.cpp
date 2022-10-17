#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
vector <vector<bool>> v(1000001, vector <bool>(8, 0));
int p, k, s;

bool winCheck(int index, int step) {
    if (index != 0 && index % p == 0) {
        return false;
    }
    for (int i = 1; i <= k; i++) {
        if (i != step) {
            if (v[index][i]) {
                return false;
            }
        }
    }
    return true;
}

void coinCheck() {
    for (int i = 1; i <= s; i++) {
        if (i == s || i % p != 0) {
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
        if (v[s][i] == 1) {
            return s - i;
        }
    }
    return -1;
}



int main() {
    ifstream fin("coinmove.inp");
    ofstream fout("coinmove.out");
    int layer;
    fin >> layer;
    int cnt = 0;

    while (cnt < layer) {
        fin >> p >> k >> s;
        coinCheck();
        int minindex = chulOryoung();
        fout << minindex << endl;
        cnt++;
    }

    return 0;
}
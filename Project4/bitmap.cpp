#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

vector<vector<char>> v1;
vector<vector<char>> v2;
string out, out2;


void ifD(int row_num, int col_num, int row_st, int col_st) {
    char bitmap_data = cin.get();
    if (bitmap_data == '\n') {
        bitmap_data = cin.get();
    }

    if (bitmap_data == '1' || bitmap_data == '0') {
        for (int i = row_st; i < row_st + row_num; i++) {
            for (int j = col_st; j < col_st + col_num; j++) {
                v2[i][j] = bitmap_data;
            }
        }
    }
    else {
        if (col_num == 1) {
            ifD((int)ceil(row_num / 2.0), col_num, row_st, col_st);
            ifD(row_num / 2, col_num, row_st + (int)ceil(row_num / 2.0), col_st);
        }
        else if (row_num == 1) {
            ifD(row_num, (int)ceil(col_num / 2.0), row_st, col_st);
            ifD(row_num, col_num / 2, row_st, (int)ceil(col_st + col_num / 2.0));
        }
        else {
            ifD((int)ceil(row_num / 2.0), (int)ceil(col_num / 2.0), row_st, col_st);
            ifD((int)ceil(row_num / 2.0), col_num / 2, row_st, col_st + (int)ceil(col_num / 2.0));
            ifD(row_num / 2, (int)ceil(col_num / 2.0), row_st + (int)ceil(row_num / 2.0), col_st);
            ifD(row_num / 2, col_num / 2, row_st + (int)ceil(row_num / 2.0), col_st + (int)ceil(col_num / 2.0));
        }
        return;
    }
    return;
}


void ifB(int row_num, int col_num, int row_st, int col_st) {
    char bitmap_data = v1[row_st][col_st];
    for (int i = row_st; i < row_st + row_num; i++) {
        for (int j = col_st; j < col_st + col_num; j++) {
            if (bitmap_data != v1[i][j]) {
                out += 'D';

                if (col_num == 1) {
                    ifB((int)ceil(row_num / 2.0), col_num, row_st, col_st);
                    ifB(row_num / 2, col_num, row_st + (int)ceil(row_num / 2.0), col_st);
                }
                else if (row_num == 1) {
                    ifB(row_num, (int)ceil(col_num / 2.0), row_st, col_st);
                    ifB(row_num, col_num / 2, row_st, (int)ceil(col_st + col_num / 2.0));
                }
                else {
                    ifB((int)ceil(row_num / 2.0), (int)ceil(col_num / 2.0), row_st, col_st);
                    ifB((int)ceil(row_num / 2.0), col_num / 2, row_st, col_st + (int)ceil(col_num / 2.0));
                    ifB(row_num / 2, (int)ceil(col_num / 2.0), row_st + (int)ceil(row_num / 2.0), col_st);
                    ifB(row_num / 2, col_num / 2, row_st + (int)ceil(row_num / 2.0), col_st + (int)ceil(col_num / 2.0));
                }
                return;
            }
        }
    }
    out += bitmap_data;
}

int main() {
    freopen("bitmap.inp", "r", stdin);
    freopen("bitmap.out", "w", stdout);

    ifstream fin("test.inp");
    ofstream fout("test.out");

    char data;
    while (true) {
        cin >> data;
        if (data == '#') {
            break;
        }
        int row, col = 0;
        cin >> row >> col;
        cin.ignore();

        if (data == 'B') {
            cout << 'D' << " " << row << " " << col << endl;
            string tmpstring;
            v1.resize(row, vector<char>(col));
            while (tmpstring.size() < row * col) {
                string temp;
                getline(cin, temp);
                tmpstring += temp;
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    v1[i][j] = tmpstring[i * col + j];
                }
            }
            ifB(row, col, 0, 0);

            int outLen = out.length();
            int cnt = 0;
            for (int i = 0; i < outLen; i++) {
                if (cnt >= 50) {
                    cnt = 0;
                    cout << endl;
                }
                cout << out[i];
                cnt++;
            }
            cout << endl;
        }
        if (data == 'D') {
            cout << 'B' << " " << row << " " << col << "\n";
            v2.resize(row, vector<char>(col));
            ifD(row, col, 0, 0);
            int cnt = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (cnt >= 50) {
                        cnt = 0;
                        cout << endl;
                    }
                    cout << v2[i][j];
                    cnt++;
                }
            }
            cout << endl;
        }

        v1.clear();
        v2.clear();
        out = "";
        out2 = "";
    }
}
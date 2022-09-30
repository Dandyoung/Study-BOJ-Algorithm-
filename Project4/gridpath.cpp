#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int minmin(int row, int col, vector<vector<int>> &v, vector<vector<int>> &v3) {
    if (row == 0 && col == 0) {
        return v3[row][col];
    }
    if (row == 0) {
        return v3[row][col] = v3[0][col - 1] + v[0][col];
    }
    if (col == 0) {
        return v3[row][col] = v3[row - 1][0] + v[row][0];
    }
    if (v[row - 1][col] != -1 && v[row][col - 1] != -1) {
        if (v3[row - 1][col] <= v3[row][col - 1]) {
            return v3[row][col] = v3[row - 1][col] + v[row][col];
        }
        else {
            return v3[row][col] = v3[row][col - 1] + v[row][col];
        }
    }
    if (v[row - 1][col] == -1) {
        return v3[row][col - 1] + v[row][col];
    }
    if (v[row][col - 1] == -1) {
        return v3[row - 1][col] + v[row][col];
    }

}



int main() {
    ifstream fin("gridpath.inp");
    ofstream fout("gridpath.out");

    int row, col;
    fin >> row >> col;

    vector< vector<int>> v;

    for (int i = 0; i < row; i++) {
        vector <int> v2;
        for (int j = 0; j < col; j++) {
            int a;
            fin >> a;
            v2.push_back(a);
        }
        v.push_back(v2);
    }
    vector < vector <int> > result(row, vector <int>(col, 0));
    vector < vector <int> > v3(row, vector <int>(col, 0));

    int check_row = 0;
    for (int i = 0; i < row; i++) {
        if (v[i][0] == -1) {
            check_row = i;
            break;
        }
    }

    int check_col = 0;
    for (int i = 0; i < col; i++) {
        if (v[0][i] == -1) {
            check_col = i;
            break;
        }
    }

    for (int i = check_row; i < row; i++) {
        if (check_row == 0) {
            break;
        }
        v[i][0] = -1;
    }

    for (int i = check_col; i < col; i++) {
        if (check_col == 0) {
            break;
        }
        v[0][i] = -1;
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (v[i - 1][j] == -1 && v[i][j - 1] == -1) {
                v[i][j] = -1;
            }
        }
    }

    v3[0][0] = v[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            v3[i][j] = minmin(i, j, v, v3);
        }
    }


    if (v[row - 1][col - 1] == -1) {
        fout << "No path." << '\n';
    }
    else {
        int x = row - 1;
        int y = col - 1;
        result[x][y] = 1;
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (result[i][j] == 1) {
                    if (i != 0 && j != 0) {
                        if (v3[i - 1][j] == v3[i][j - 1]) result[i - 1][j] = 1;
                        else {
                            if (v3[i][j] - v[i][j] == v3[i - 1][j]) result[i - 1][j] = 1;
                            else if (v3[i][j] - v[i][j] == v3[i][j - 1]) result[i][j - 1] = 1;
                        }
                    }
                    else if (i != 0 && j == 0) result[i - 1][j] = 1;
                    else if (i == 0 && j != 0) result[i][j - 1] = 1;
                    if (i == 0 && j == 0) result[i][j] = 1;
                }
            }
        }
        //for (int i = 0; i < row; i++) {
        //    for (int j = 0; j < col; j++) {
        //        cout << result[i][j] << ' ';
        //    }
        //}
        fout << v3[row - 1][col - 1] << '\n';
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (result[i][j] == 1) {
                    fout << "(" << i << " " << j << ")" << '\n';
                }
            }
        }
    }


    fin.close();
    fout.close();
}
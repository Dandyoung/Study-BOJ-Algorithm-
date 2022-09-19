#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
void DPYee(int cnt) {
    vector < vector <int> > v(cnt, vector <int>(cnt, 0));
    int num = 1;
    int i, j;

    for (i = 0; i < (cnt / 2) + 1; i++){
        for (j = i; j < cnt - i; j++)   //왼쪽에서 오른쪽으로 값을 넣는 부분이다.
            v[i][j] = num++;

        for (j = i + 1; j < cnt - i; j++)  //위에서 아래로 값을 넣는 부분이다
            v[j][cnt - i - 1] = num++;

        for (j = cnt - i - 2; j >= i; j--)  //오른쪽에서 왼쪽으로 값을 넣는 부분이다.
            v[cnt - i - 1][j] = num++;

        for (j = cnt - i - 2; j >= i + 1; j--)  //밑에서 위로 값을 넣는 부분이다.
            v[j][i] = num++;

    }
    for (i = 0; i < cnt; i++){
        for (j = 0; j < cnt; j++){
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ifstream fin("C:/Users/이영우/Desktop/sampleData5 (1)/test.inp");
    ofstream fout("C:/Users/이영우/Desktop/sampleData5 (1)/test.out");

    int layer;
    fin >> layer;
    int row = 0, col = -1, reverse = 1;
    int cnt = 0;

    while (cnt < layer) {
        int n, p1, p2;
        fin >> n >> p1 >> p2;
        int limit = 0;
        vector < vector <int> > v(n, vector <int>(n, 0));

        for (int count = 1; count <= n * n;) {
            for (int i = 0; i < n - limit; i++) {
                col += reverse;
                v[row][col] = count++;
            }
            for (int i = 0; i < n - limit - 1; i++) {
                row += reverse;
                v[row][col] = count++;
            }
            limit++;
            reverse = -reverse;
        }

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        int a, b, c, d = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (v[i][j] == p1) {
                    a = i;
                    b = j;
                }
                if (v[i][j] == p2) {
                    c = i;
                    d = j;
                }
            }
        }
        //cout << a <<"," << b << endl;
        //cout << c << "," << d << endl;
        int sum = a - c;
        int sum2 = b - d;
        if (abs(sum) == abs(sum2)) {
            cout << "YES" << "\n";
            v.clear();
        }
        else {
            cout << "NO" << "\n";
            v.clear();
        }
        cnt++;
    }
}
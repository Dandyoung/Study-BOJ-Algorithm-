#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main() {
	ifstream fin("C:/Users/이영우/Desktop/sampleData10/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData10/test.out");

    vector <char> coin_v;
    for (int i = 0; i < 25; i++) {
        coin_v.push_back('C');
        coin_v.push_back('A');
        coin_v.push_back('A');
        coin_v.push_back('A');
    }
    for (int i = 0; i < 100; i++) {
        cout << coin_v[i] << " ";
    }
    cout << endl;

	int layer;
	fin >> layer;
	//
	int cnt = 0;
	while (cnt < layer) {
		int a = 2;
		int b = 3;
        vector <int> v;
		//int bucket1, bucket2, bucket3;
        for (int i = 0; i < 3; i++) {
            int bucket;
            fin >> bucket;
            v.push_back(bucket);
        }
        vector <char> result;

        int a_cnt = 0;
        int c_cnt = 0;
        for (int i = 0; i < 3; i++) {
            int c = v[i] - 1;
            if (c < 0) {
                continue;
            }
            if (c >= 0) {
                if (coin_v[c] == 'A') {
                    result.push_back('A');
                    a_cnt++;
                }
                else {
                    result.push_back('C');
                    c_cnt++;
                }
            }
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;


        if (result.size() == 1) {
            if (result[0] == 'A') {
                cout << "1" << endl;
            }
            else {
                cout << "-11" << endl;
            }
        }
        else {
            if (a_cnt == 3) {
                cout << "1" << endl;
            }
            else if (c_cnt == 3) {
                cout << "-1" << endl;
            }
            
            else {
                int sum = 0;
                int check = 0;
                int f_check = 0;
                for (int i = 0; i < v.size(); i++) {
                    sum += v[i];
                    if (v[i] == 1) {
                        check++;
                    }
                    if (v[i] >= 4) {
                        f_check++;
                    }
                }
                if (f_check == 0 && check == 1 && result.size() == 2) {
                    if (coin_v[sum - 1] == 'A') {
                        cout << "1" << endl;
                    }
                    else {
                        cout << "-1" << endl;
                    }
                }
                else if (f_check == 0 && result.size() == 2 && check == 2) {
                    cout << "1" << endl;
                }
                else {
                    if (check == 1) {
                        if (coin_v[sum - 1] == 'A') {
                            cout << "-1" << endl;
                        }
                        else {
                            cout << "-1" << endl;
                        }
                    }
                    else if (check == 3) {
                        if (coin_v[sum - 1] == 'A') {
                            cout << "1" << endl;
                        }
                        else {
                            cout << "-1" << endl;
                        }
                    }

                    else {
                        if (coin_v[sum - 1] == 'A') {
                            cout << "-1" << endl;
                        }
                        else {
                            cout << "1" << endl;
                        }
                    }
                }
            }
        }


        cnt++;
	}


	fin.close();
	fout.close();
}
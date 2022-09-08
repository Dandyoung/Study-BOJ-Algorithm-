#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

template<typename T>
T FindMin(T* arr, size_t n)
{
    int min = arr[0];
    for (size_t j = 0; j < n; ++j) {
        if (arr[j] < min) {
            min = arr[j];
        }
    }
    return min;
}
int main() {
    ifstream fin("7.inp");
    ofstream fout("fcfs.out");
    queue<int> q;
    char t[20];
    fin.getline(t, 20);
    int layer = atoi(t);  /* 맨 처음 몇층인지 알아봄 */
    int cnt = 0;
    int** array = new int* [layer];

    for (int i = 0; i < layer; i++) {
        int a[1001] = { 0 };
        while (true) {
            fin >> a[cnt];
            if (a[cnt] == -1) {
                a[cnt] = -1;
                break;
            }
            cnt++;
        }
        array[i] = new int[cnt + 1];
        for (int j = 0; j < cnt + 1; j++) {
            array[i][j] = 0;
            array[i][j] = a[j];
        }
        cnt = 0;
    }
    int* state_array = new int[layer](); // state 상태 배열
    int* value_array = new int[layer]();// value 배열 
    int* index_array = new int[layer](); // index 배열
    int* end_array = new int[layer](); // 끝나는 배열
    int* tmp_array = new int[layer]();
    int time = 0; // 전체시간 체크
    int idle = 0;
    int t_time = 0;  // 이전시간 체크
    for (int i = 0; i < layer; i++) {
        tmp_array[i] = array[i][index_array[i]];
        cout << tmp_array[i] << " ";
    }
    cout << endl;
 
    while (true) {
        int m1_cnt = 0;
        int zero_cnt = 0;
        int one_cnt = 0;
        int m2_cnt = 0;
        int min = 0;
        int min_index = 0;
        min = tmp_array[0];

        for (int i = 0; i < layer; i++) {
            if (tmp_array[i] < min) {
                min = tmp_array[i];
                min_index = i;
            }
        }
        t_time = time;
        time = tmp_array[min_index];

        for (int i = 0; i < layer; i++) {
            if (time == tmp_array[i] && state_array[i] == 0) {
                q.push(i);
                index_array[i]++;
                tmp_array[i] += array[i][index_array[i]];
                value_array[i] = array[i][index_array[i]]; // 밸류 처음
            }
            cout << endl;
            if (state_array[i] == 1 || state_array[i] == -1) {
                value_array[i] -= (time - t_time);  //밸류 두번째
            }
            if (value_array[i] == 0) { // value == 0 일때 if
                if (state_array[i] == -1) { //io끝
                    if (array[i][index_array[i]] == -1) {
                        state_array[i] = -2;
                        end_array[i] = time;
                    }
                    else{
                        value_array[i] = array[i][index_array[i]];  //밸류 세번쨰
                        state_array[i] = 0;
                        tmp_array[i] += value_array[i];
                        q.push(i);
                        tmp_array[i] += 100001;
                        index_array[i]++;
                    }
                }
                else if (state_array[i] == 1) { // cpu 끝
                    if (array[i][index_array[i]] == -1) {
                        state_array[i] = -2;
                        end_array[i] = time;
                    }
                    else {
                        state_array[i] = -1;
                        value_array[i] = array[i][index_array[i]]; // 밸류 네번째
                        tmp_array[i] += value_array[i];
                        //index_array[i]++;
                    }
                }
            }// value == 0 일때 if
            if (state_array[i] == -1) {
                m1_cnt++;
            }
            if (state_array[i] == 0) {
                zero_cnt++;
            }
            if (state_array[i] == 1) {
                one_cnt++;
            }
            if (state_array[i] == -2) {
                m2_cnt++;
            }
        } // 큰 for문
        if (m2_cnt == layer) {
            break;
        }
        if ((m1_cnt + m2_cnt) == layer) {
            int q1 = 0;
            for (int i = 0; i < layer; i++) {
                if (value_array[i] >= 0 && array[i][index_array[i]] == -1) {
                    q1++;
                }
            }
            if ((m1_cnt + m2_cnt) != q1) {
                idle++;
            }
        }
        if (one_cnt == 0) {
            if (zero_cnt > 0 && zero_cnt <= layer) {
                if (q.empty() == false) {
                    state_array[q.front()] = 1;
                    index_array[q.front()]++;
                    cout <<"이거 뭐고 씹덕아" << value_array[q.front()];
                    tmp_array[q.front()] = time + value_array[q.front()];
                    q.pop();
                }
                else {
                    int qwe = 0;
                    int asd = 0;
                    int asdasd = 0;
                    for (int i = 0; i < layer; i++) {
                        if (array[i][index_array[i]] == -1) {
                            qwe++;
                        }
                        if (state_array[i] == -2) {
                            asd++;
                        }
                        if (value_array[i] >= 0) {
                            if (array[i][index_array[i]] == -1) {
                                asdasd++;
                            }
                        }
                    }
                    if (asd != layer - asdasd) {
                        idle++;
                    }
                }
            }
        }

        cout << "time : "<<time << endl;
        for (int i = 0; i < layer; i++) {
            cout << state_array[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < layer; i++) {
            cout << value_array[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < layer; i++) {
            cout << tmp_array[i] << " ";
        }
        cout << endl;
    }// while
    //for (int i = 0; i < layer; i++) {
    //    cout << end_array[i] << endl;
    //}
    for (int i = 0; i < layer; i++) {
        delete[] array[i];
    }
    delete[] array;
    delete[] state_array;
    delete[] value_array;
    delete[] index_array;
    delete[] end_array;
    fin.close();
    fout.close();

}// main


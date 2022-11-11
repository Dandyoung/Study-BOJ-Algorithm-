#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <tuple>
using namespace std;

vector <tuple<int, int, int >> v[10005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
bool visited[10001];
int sum;

void prim(int a) {
    visited[a] = true;           // ���� ��� �湮  ó��
    for (int i = 0; i < v[a].size(); i++) { // Node a�� ����� �湮 ���� �ٸ� ���� �켱���� ť�� �ֱ�
        if (!visited[v[a][i].second]) {
            pq.push(make_pair(v[a][i].first, v[a][i].second));
        }
    }
    while (!pq.empty()) {
        pair<int, int> pp = pq.top();

        pq.pop();
        if (!visited[pp.second]) {  // �湮���� ���� ��� �� ���� ����ġ�� ������ �߰� �� �� ��带 ���ڰ����� prim�Լ� ȣ�� �� �Լ� ������
            sum += pp.first;
            cout << pp.first << endl;
            prim(pp.second);
            return;
        }
    }
}
int main() {
    ifstream fin("C:/Users/�̿���/Desktop/sampleData19/test.inp");
    ofstream fout("C:/Users/�̿���/Desktop/sampleData19/test.out");

    int a, b;
    fin >> a >> b;
    for (int i = 1; i <= b; i++)        // ���� ����� ������ �Է�.
    {
        int a, ab, cost;                 // ���� 1, ���� 2, ����ġ
        fin >> a >> b >> cost;
        visited[a].push_back({ a, b, cost });
        visited[b].push_back({ cost, a , i });
    }
    prim(0);                            // ù��° ��带 ���ڰ��� �־� prim �Լ� ȣ��
    cout << sum;
    return 0;
}
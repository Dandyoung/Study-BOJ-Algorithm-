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
    visited[a] = true;           // 시작 노드 방문  처리
    for (int i = 0; i < v[a].size(); i++) { // Node a와 연결된 방문 안한 다른 노드들 우선순위 큐에 넣기
        if (!visited[v[a][i].second]) {
            pq.push(make_pair(v[a][i].first, v[a][i].second));
        }
    }
    while (!pq.empty()) {
        pair<int, int> pp = pq.top();

        pq.pop();
        if (!visited[pp.second]) {  // 방문하지 않은 노드 중 가장 가중치가 적은거 발견 시 그 노드를 인자값으로 prim함수 호출 후 함수 끝내기
            sum += pp.first;
            cout << pp.first << endl;
            prim(pp.second);
            return;
        }
    }
}
int main() {
    ifstream fin("C:/Users/이영우/Desktop/sampleData19/test.inp");
    ofstream fout("C:/Users/이영우/Desktop/sampleData19/test.out");

    int a, b;
    fin >> a >> b;
    for (int i = 1; i <= b; i++)        // 정점 연결과 가중지 입력.
    {
        int a, ab, cost;                 // 정점 1, 정점 2, 가중치
        fin >> a >> b >> cost;
        visited[a].push_back({ a, b, cost });
        visited[b].push_back({ cost, a , i });
    }
    prim(0);                            // 첫번째 노드를 인자값에 넣어 prim 함수 호출
    cout << sum;
    return 0;
}
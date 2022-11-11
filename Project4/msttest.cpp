#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <queue>

#define X first
#define Y second
using namespace std;

int v, e;
vector <tuple<int, int, int >> adj[10005];
bool chk[10005];
int cnt = 0;
int ans = 0;



int main() {
	ifstream fin("C:/Users/이영우/Desktop/sampleData19/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData19/test.out");
	

	fin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		fin >> a >> b >> cost;
		adj[a].push_back({ cost, b, i });
		adj[b].push_back({ cost, a , i});
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	chk[1] = 1;
	for (auto a : adj[1]) {
		pq.push({ a.X, 1, a.Y });
	}
	
	while (cnt < v - 1) {
		int cost, a, b;
		tie(cost, a, b) = pq.top(); 
		pq.pop();
		if (chk[b]) {
			continue;
		}

		cout << cost << ' ' << a << ' ' << b << endl;
		ans += cost;
		chk[b] = 1;
		cnt++;
		for (auto a : adj[b]) {
			if (!chk[a.Y]) {
				pq.push({ a.X, b, a.Y });
			}
		}
	}
	cout << "답 : " << ans;
}
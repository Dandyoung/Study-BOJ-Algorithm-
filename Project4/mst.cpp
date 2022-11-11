#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int node_case, edge_case;
vector <int> check_v(10000001, 0);
//
vector<pair<int, int> >spare[10001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
bool visited[10001];
int sum2;




class Edge {
public:
	int node[2];
	int distance;
	int s;
	int number;
	Edge(int a, int b, int distance, int number) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
		this->number = number;
	}

	//간선을 오름차순으로 정렬(기준 : distance) 
	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int getParent(int node) {
	if (check_v[node] == node) return node;
	return getParent(check_v[node]);
}

//연결 
void unionParent(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (node1 < node2) check_v[node2] = node1;
	else check_v[node1] = node2;
}

//싸이클이 존재하면 true, 아니면 false를 반환
bool isCycle(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (node1 == node2) {
		return true;
	}
	else {
		return false;
	}
}



int main() {
	ifstream fin("C:/Users/이영우/Desktop/sampleData19/test.inp");
	ofstream fout("C:/Users/이영우/Desktop/sampleData19/test.out");
	
	fin >> node_case >> edge_case;

	vector<Edge> v;
	vector<Edge> p_v;

	for (int i = 0; i < edge_case; i++) {
		int v1, v2, weight;
		fin >> v1 >> v2 >> weight;
		v.push_back(Edge(v1, v2, weight, i));  // 크루스컬알고리즘
		p_v.push_back(Edge(v1, v2, weight, i)); // 프림알고리즘
		//v[v1].push_back(make_pair(weight, v2));
  //      v[v2].push_back(make_pair(weight, v1));
	}

	sort(v.begin(), v.end());
	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i].node[0] << " " << v[i].node[1] << " " << v[i].distance << endl;
	//}
	//초기화(자기자신을 가리키게
	for (int i = 1; i <= node_case; i++) {
		check_v[i] = i;
	}
	int kruskal_sum = 0;
	

	vector <int> qq;
	for (int i = 0; i < v.size(); ++i) {
		if (!isCycle(v[i].node[0], v[i].node[1])) {
			kruskal_sum += v[i].distance;
			//cout << v[i].distance << endl;
			qq.push_back(v[i].number);
			unionParent(v[i].node[0], v[i].node[1]);

		}
	}

	cout << "Tree edges by Kruskal algorithm: " << kruskal_sum << '\n';
	for (int i = 0; i < qq.size(); i++) {
		cout << qq[i] << '\n';
	}

	cout << "Tree edges by Prim algorithm with starting vertex 0: " <<'\n';

	fin.close();
	fout.close();

}
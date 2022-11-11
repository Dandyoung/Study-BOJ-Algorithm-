#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#define inf 1e9

using namespace std;

ifstream fin("C:/Users/�̿���/Desktop/sampleData18/test.inp");
ofstream fout("C:/Users/�̿���/Desktop/sampleData18/test.out");
int n, m;
vector<int> arr;
vector<int> sum;
int d[501][501]; //d[s][k] : s~n ������ ���� k���� �����뿡 ��Ȱ���� �ִ� ��� ��� �ּ� ���

//d[s][k] ä���
int go(int s, int k)
{
	//��
	if (s > n)
	{
		if (k == 0) return 0;//����
		else return inf;//�Ұ���
	}
	if (k == 0) return inf; //�Ұ���

	int& ret = d[s][k];
	if (ret != -1) return ret;
	ret = inf;

	int mid; //�߰��� 
	int cost; //��� ���

	//s~i ���� ������ ������ 1���� ä��� ���
	for (int i = s; i <= n; i++)
	{
		mid = (s + i) / 2;
		cost = (sum[i] - sum[mid]) - (sum[mid] - sum[s - 1]) + ((mid - s + 1) - (i - mid)) * arr[mid];
		ret = min(ret, go(i + 1, k - 1) + cost);
	}
	return ret;
}

int solve()
{
	fin >> n >> m;
	arr.resize(n + 1);
	sum.resize(n + 1);
	memset(d, -1, sizeof(d));

	for (int i = 1; i <= n; i++)
	{	
		int a;
		fin >> a;
		arr[i] = a;
		//scanf("%d", &arr[i]);
	}
	cout << endl;
	sort(arr.begin(), arr.end()); //�������� ����
	for (int i = 1; i <= n; i++)
	{
		int a;
		fin >> a;
		cout << arr[i] << " ";
		//scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		sum[i] = arr[i] + sum[i - 1];
	}
	return go(1, m);
}

int main(int argc, char** argv)
{
	int T, test_case;
	int Answer;

	fin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = solve();
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		cout << d[1][m] << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
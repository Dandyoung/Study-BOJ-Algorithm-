#pragma warning(disable:4996)
#include <iostream>
using namespace std;


char arr[205][205];
string ans = "";
int idx = 0;
//string 시간 초과 날 것 같은데..
string calcBitmap(int strN, int strM, int endN, int endM) {
	//n,m이 1,1일때,
	string temp = "";
	if (strN == endN && strM == endM) {
		temp += arr[strN][endM];
		return temp;
	}
	//행이 한 줄 일때, M만 분리.
	if (strN == endN) {

		int divM = (strM + endM) / 2;
		string temp1 = calcBitmap(strN, strM, endN, divM);
		string temp2 = calcBitmap(strN, divM + 1, endN, endM);
		//두 문자 같다면
		if (temp1 == temp2 && temp1[0] != 'D') {
			return temp1;
		}
		else {
			temp += 'D' + temp1 + temp2;
			return temp;
		}
	}
	else if (strM == endM) {
		//열이 같다면 N만 분리
		int divN = (strN + endN) / 2;
		string temp1 = calcBitmap(strN, strM, divN, endM);
		string temp2 = calcBitmap(divN + 1, strM, endN, endM);
		//두 문자 같다면
		if (temp1 == temp2 && temp1[0] != 'D') {
			return temp1;
		}
		else {
			temp += 'D';
			temp += temp1;
			temp += temp2;
			return temp;
		}
	}
	else {
		//둘 다 분리해야 한다면,
		int divN = (strN + endN) / 2;
		int divM = (strM + endM) / 2;
		string temp1 = calcBitmap(strN, strM, divN, divM);
		string temp2 = calcBitmap(strN, divM + 1, divN, endM);
		string temp3 = calcBitmap(divN + 1, strM, endN, divM);
		string temp4 = calcBitmap(divN + 1, divM + 1, endN, endM);

		if (temp1 == temp2 && temp2 == temp3 && temp3 == temp4 && temp1[0] != 'D') {
			//같은 숫자라면,
			return temp1;
		}
		else {
			temp += 'D';
			temp += temp1;
			temp += temp2;
			temp += temp3;
			temp += temp4;
			return temp;
		}
	}
}

void calcDatamap(int strN, int strM, int endN, int endM) {
	if (strN == endN && strM == endM) {
		arr[strN][strM] = ans[idx++];
		return;
	}
	if (ans[idx] == 'D') {
		idx++;

		if (strN == endN) {
			int divM = (strM + endM) / 2;
			calcDatamap(strN, strM, endN, divM);
			calcDatamap(strN, divM + 1, endN, endM);
		}
		else if (strM == endM) {
			int divN = (strN + endN) / 2;
			calcDatamap(strN, strM, divN, endM);
			calcDatamap(divN + 1, strM, endN, endM);
		}
		else {
			int divN = (strN + endN) / 2;
			int divM = (strM + endM) / 2;
			calcDatamap(strN, strM, divN, divM);
			calcDatamap(strN, divM + 1, divN, endM);
			calcDatamap(divN + 1, strM, endN, divM);
			calcDatamap(divN + 1, divM + 1, endN, endM);
		}
	}
	else {
		if (strN == endN) {
			int divM = (strM + endM) / 2;
			calcDatamap(strN, strM, endN, divM);
			idx--;
			calcDatamap(strN, divM + 1, endN, endM);
		}
		else if (strM == endM) {
			int divN = (strN + endN) / 2;
			calcDatamap(strN, strM, divN, endM);
			idx--;
			calcDatamap(divN + 1, strM, endN, endM);

		}
		else {
			int divN = (strN + endN) / 2;
			int divM = (strM + endM) / 2;
			calcDatamap(strN, strM, divN, divM);
			idx--;
			calcDatamap(strN, divM + 1, divN, endM);
			idx--;
			calcDatamap(divN + 1, strM, endN, divM);
			idx--;
			calcDatamap(divN + 1, divM + 1, endN, endM);

		}
	}
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	//freopen("1.inp", "r", stdin);
	//freopen("bitmap.out", "w", stdout);


	while (true) {
		char type;
		int N, M;

		cin >> type;
		if (type == '#') return 0;

		cin >> N >> M;

		if (type == 'B') {
			//입력
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cin >> arr[i][j];
				}
			}
			printf("D %3d %3d\n", N, M);
			//			cout << "D " << N << " " << M << "\n";
			string temp = calcBitmap(0, 0, N - 1, M - 1);
			int idx = 0;
			for (int i = 0; i < temp.size(); i++) {
				if (idx == 50) {
					cout << "\n";
					idx = 0;
				}
				idx++;
				cout << temp[i];
			}
			cout << "\n";
		}
		else {
			//
			cin >> ans;
			idx = 0;
			calcDatamap(0, 0, N - 1, M - 1);
			printf("B %3d %3d\n", N, M);
			//			cout << "B " << N << " " << M << "\n";
			idx = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (idx == 50) {
						cout << "\n";
						idx = 0;
					}
					idx++;
					cout << arr[i][j];
				}
			}
			cout << "\n";
		}
	}
}
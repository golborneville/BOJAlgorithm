#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int level[17];
int numque[17]; 
bool chk[17];
int arr[17];
int CNT = 0;
int M;
int N, L, R, X; //문제 개수, 난이도 합 최소 값, ㅏㄴ이도 합 최대값,| 젤쉬움 - 젤 어려움| >=X
bool chkvalidity(int least, int maxs, int sum) {
	if (sum < L) return false;
	if (sum > R) return false;
	if (maxs - least < X) return false;
	return true;
}
void getcount() {
	//arr[] 에 대해 
	int least = 987654321;
	int maxs = -987654321;
	int sum = 0;
	for (int i = 0; i < M; i++) {
		int scr = level[arr[i]];
		if (least > scr) least = scr;
		if (maxs < scr) maxs = scr;
		sum += scr;

		//if (i < 1)continue;

	}
	if (chkvalidity(least, maxs, sum)) CNT++;
}
void rec(int m, int dep) {

	if (dep == M) {
		//getcount
		getcount();
		return;
	}


	for(int i = m; i < N; i++) {
		if (chk[i])continue;
		chk[i] = true;
		arr[dep] = numque[i];
		rec(i + 1, dep + 1);
		chk[i] = false;
	}


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R >> X;
	
	for (int i =0; i < N; i++) {
		numque[i] = i;
	}

	for (int i = 0; i < N; i++) {
		cin >> level[i];
	}
	for (int i = 2; i <= N; i++) {
		M = i;
		rec(0,0);
	}
	cout << CNT;
	return 0;
}
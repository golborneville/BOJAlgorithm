#include<iostream>
using namespace std;
bool chk[1003];
bool comb[22][22][22][22];
int cnt = 0;
void solve(int a, int b, int c, int d) {
	if (a < 0 || b < 0 || c < 0 || d < 0) return;
	if (!chk[a + 5 * b + 10 * c + 50 * d]) {
		cnt++;
		chk[a + 5 * b + 10 * c + 50 * d] = true;
	}
	if (comb[a][b][c][d]) {
		return;
	}
	comb[a][b][c][d] = true;

	


	solve(a - 1, b + 1, c, d);

	solve(a - 1, b, c + 1, d);

	solve(a - 1, b, c, d + 1);
}

int main() {

	int N;
	cin >> N;
	solve(N, 0, 0, 0);
	cout << cnt;
	return 0;
}
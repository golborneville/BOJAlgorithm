#include<iostream>
#include<queue>
using namespace std;
int N;
int arr[130][130];
bool chk[130][130];

int side[7] = { 2,4,8,16,32,64,128 };
int cnt[2]; // 0 -> white, 1-> blue

bool chkarea(int x, int y, int color, int ss) {
	for (int i = 0; i < ss; i++) {
		for (int j = 0; j < ss; j++) {
			if (arr[x + i][y + j] != color || chk[x+i][y+j])return false;
		}
	}

	for (int i = 0; i < ss; i++) {
		for (int j = 0; j < ss; j++) {
			chk[x + i][y + j] = true;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int ss = N/2;
	while (ss > 0) {
		for (int i = 0; i < N; i += ss) {
			for (int j = 0; j < N; j += ss) {
				if (!chk[i][j]) {
					bool res = chkarea(i, j, arr[i][j], ss);
					if (res) {
						cnt[arr[i][j]]++;
					}
				}
			}
		}
		ss /= 2;
	}

	cout << cnt[0] << "\n" << cnt[1];
	return 0;


}
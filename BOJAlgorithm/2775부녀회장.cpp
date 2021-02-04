#include<iostream>
using namespace std;

unsigned long long int room[15][15];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 14; i++) {
		room[0][i] = i;
		room[i][1] = 1;
	}
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			room[i][j] = room[i][j - 1] + room[i - 1][j];
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int k, n;
		cin >> k >> n;
		cout << room[k][n] << "\n";
	}
	
	return 0;
}
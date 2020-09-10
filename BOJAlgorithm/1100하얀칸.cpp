#include<iostream>
using namespace std;

char arr[10][10];
int main() {
	int ans = 0;
	for (int i = 0; i<8; i++) {
		for (int j = 0; j<8; j++) {
			cin >> arr[i][j];
			if (i % 2 == 0 && j % 2 == 0) {
				if (arr[i][j] == 'F') {
					ans++;
				}
			}
			if (i % 2 == 1 && j % 2 == 1) {
				if (arr[i][j] == 'F') {
					ans++;
				}
			}

		}
	}
	cout << ans;
}
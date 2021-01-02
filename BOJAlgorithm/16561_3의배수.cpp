#include<iostream>
using namespace std;

bool chk[1003][1003];
int main() {
	int n;
	int k, totalCNT=0;
	cin >> n;
	k = n / 3;

	if (k < 3) {
		cout << 0;
		return 0;
	}

	k -= 3;

	
	for (int i = 0; i <= k; i++) { // second number
		for (int j = 0; j <= k; j++) { //first number
			if (k - i - j < 0) continue;

			if (!chk[i][j]) {
				chk[i][j] = true;
				totalCNT++;
			}
		}
	}
	
	
	cout << totalCNT;
	return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
unsigned long long int DP[100][10]; //각 N자리 마다 0~ 9 의 등장(필요) 개수
int main() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << 9; 
		return 0;
	}
	DP[1][0] = 0;
	DP[1][1] = 1;
	DP[1][2] = 1;
	DP[1][3] = 1;
	DP[1][4] = 1;
	DP[1][5] = 1;
	DP[1][6] = 1;
	DP[1][7] = 1;
	DP[1][8] = 1;
	DP[1][9] = 1;

	for (int i = 1; i < N; i++) {
		//0->1 횟수 추가
		DP[i + 1][1] += (DP[i][0] % 1000000000);
		for (int j = 1; j < 9; j++) {
			//1~8
			DP[i + 1][j+1] += (DP[i][j] % 1000000000);
			DP[i + 1][j-1] += (DP[i][j] % 1000000000);
		}
		DP[i + 1][8] += (DP[i][9] % 1000000000); // 9->8
	}
	long long unsigned int result = (DP[N - 1][0] + DP[N - 1][9]) %1000000000;
	for (int j = 1; j < 9; j++) {
		result += ((DP[N - 1][j] * 2) %1000000000);
	}
	cout << result%1000000000;

	
}
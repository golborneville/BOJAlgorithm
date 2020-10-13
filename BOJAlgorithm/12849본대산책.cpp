#include<iostream>

long long unsigned int dp[8][8];
int main(){
	//enum { science, comp, future,   };
	//int soongsil[8] = {}
	/*
	정보과학관 0		전산관 1
	미래관 2			신앙관 3
	진리관 4			한경직기념관 5
	학생회관 6			형남공학관 7
	*/
	int D;
	
	//dp[0][0] = 0;
	dp[0][1] = 1;
	dp[0][2] = 1;
	dp[1][0] = 1;
	dp[1][2] = 1;
	dp[1][3] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][3] = 1;
	dp[2][5] = 1;
	dp[3][1] = 1;
	dp[3][4] = 1;
	dp[3][5] = 1;
	dp[3][2] = 1;
	dp[4][3] = 1;
	dp[4][5] = 1;
	dp[4][6] = 1;
	dp[5][2] = 1;
	dp[5][3] = 1;
	dp[5][4] = 1;
	dp[5][7] = 1;
	dp[6][4] = 1;
	dp[6][7] = 1;
	dp[7][5] = 1;
	dp[7][6] = 1;


	std::cin >> D;
	

	//행렬의 D번 곱셈
	long long unsigned int frow[8] = {dp[0][0], dp[0][1],dp[0][2],dp[0][3],dp[0][4],dp[0][5],dp[0][6],dp[0][7], };
	for (int i = 0; i < D-1; i++) {
		long long unsigned int tmp[8] = { 0,0,0,0,0,0,0,0 };
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				tmp[j] += (frow[k] * dp[j][k]);
			}
		}
		for (int k = 0; k < 8; k++) {
			frow[k] = tmp[k] % 1000000007;
		}
	}
	
	std::cout << frow[0];
}

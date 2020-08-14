#include<iostream>
#include<cstring>
using namespace std;
int dp[1003]; //0 = 1*2 , 1 = 2*1 , 2 = 2*2, 3 = 세가지 다 합한거?
int main() {
	int n;
	scanf_s("%d", &n);
	memset(dp, 0, sizeof(dp)); //방법 존재 가지 수  1 (초기) 없으면 0
	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i-2] * 2) %10007;
	}
	printf("%d", dp[n]);

}
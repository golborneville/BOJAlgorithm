#include<iostream>
#include<cstring>
using namespace std;
int dp[1003]; //0 = 1*2 , 1 = 2*1 , 2 = 2*2, 3 = ������ �� ���Ѱ�?
int main() {
	int n;
	scanf_s("%d", &n);
	memset(dp, 0, sizeof(dp)); //��� ���� ���� ��  1 (�ʱ�) ������ 0
	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i-2] * 2) %10007;
	}
	printf("%d", dp[n]);

}
#include <iostream>
using namespace std;

int N;
unsigned long long dp[32][62];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	dp[0][0] = 0;
	dp[0][1] = 1;

	for (int i = 0; i <= 30; i++)
	{
		for (int j = 0; j <= 60; j++)
		{
			if (i - 1 >= 0)
				dp[i][j] += dp[i - 1][j + 1];
			if (j - 1 >= 0)
				dp[i][j] += dp[i][j - 1];
		}
	}
	do{
		cin >> N;
		if (!N) break;
		cout << dp[N][0] << "\n";

	} while (N != 0);
}
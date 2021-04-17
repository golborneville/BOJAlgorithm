#include<iostream>
using namespace std;

int N, B, C;
int arr[1000003];
unsigned long long res = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> B >> C;

	//계산 가능한 경우의 수
	// 총감독 1  /  총감독 1 + 부감독 k명
	for (int i = 0; i < N; i++)
	{
		int tmp = arr[i];
		int cnt = 1;
		//1. 총감독 1명인 경우
		if(tmp > B)
		{
			tmp -= B;
			
			int vcnt = tmp / C;
			if (tmp - vcnt * C > 0) vcnt++;
			cnt += vcnt;
		}
		res += cnt;
	}
	cout << res;
	return 0;
}
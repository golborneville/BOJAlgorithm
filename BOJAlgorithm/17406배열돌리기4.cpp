#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, K;
int arr[52][52];
int origin[52][52];
int comb[6];
int resmin = 987654321;
struct info {
	int r, c, s;
};
info turn[6];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void initFun()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			arr[i][j] = origin[i][j];
		}
	}
}
int getArrVal()
{
	int minfun = 987654321;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= M; j++)
		{
			sum += arr[i][j];
		}
		if (minfun > sum) minfun = sum;
	}
	return minfun;
}
void rotate(int r, int c, int s)
{
	int tmp[52][52];
	memset(tmp, 0, sizeof(tmp));
	//rotate s개의 그룹있음
	for (int i = 0; i < s; i++)
	{
		int strx = r - s + i; int stry = c - s + i;
		for (int ind = 0; ind < 4; ind++)
		{
			for (int j = 0; j < 2 * s - i * 2; j++) //여기 맞는지 확인좀.. 다른 예제도 확ㅇ니 필요!!!!!
			{
				int nx = strx + dx[ind]; int ny = stry + dy[ind];
				tmp[nx][ny] = arr[strx][stry];
				strx = nx; stry = ny;	
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if(tmp[i][j])
				arr[i][j] = tmp[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			origin[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		int  r, c, s;
		cin >> r >> c >> s;
		turn[i] = { r,c,s };
		comb[i] = i;
	}
	do {
		//comb 순서대로 k번 의 회전 연산 완료하기
		for (int i = 0; i < K; i++)
		{
			info tmp = turn[comb[i]];
			rotate(tmp.r, tmp.c, tmp.s);
		}

		//최솟값 구하기
		//get array value -> cmp it with resmin& update if needed. 
		int tmpres = getArrVal();
		if (resmin > tmpres) resmin = tmpres;
		initFun();
	} while (next_permutation(comb, comb + K));
	cout << resmin;
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[302][302];
int group[302][302]; //group num start from 1 ~ min(N, M )/2
int N, M, R;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	int grpN = min(N, M) / 2; //무조건 짝수 보장
	for (int i = 0; i < grpN; i++)
	{
		int nx = i; int ny = i;
		for (int j = 0; j < 4; j++)
		{
			while (!(nx < 0 || ny < 0 || nx >= N || ny >= M))
			{
				if (group[nx][ny] != 0 && group[nx][ny] != i + 1) break;
				group[nx][ny] = i + 1;
				nx += dx[j]; ny += dy[j];
			}
			nx -= dx[j]; ny -= dy[j];
		}
	}
	
	while (R--)
	{
		int tmparr[302][302];
		memset(tmparr, 0, sizeof(tmparr));
		for (int i = 0; i < grpN; i++)
		{
			int nx = i; int ny = i;

			int ind = 0;
			while (ind < 4)
			{
				//move 
				bool flag = false;
				int val = arr[nx][ny];
				nx += dx[ind]; ny += dy[ind];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				{
					nx -= dx[ind]; ny -= dy[ind];
					ind++;
					flag = true;
				}
				if (group[nx][ny] != i + 1)
				{
					nx -= dx[ind]; ny -= dy[ind];
					ind++;
					flag = true;
				}
				if (flag)
				{
					nx += dx[ind]; ny += dy[ind];
				}
				tmparr[nx][ny] = val;
				if (nx == i && ny == i) break;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				arr[i][j] = tmparr[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
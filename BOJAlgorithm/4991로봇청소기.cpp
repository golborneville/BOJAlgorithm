#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


int w, h;
char room[22][22];


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int dp[22][22][22][22];
void get_track(pair<int, int> src)
{
	int chk[22][22];
	memset(chk, -1, sizeof(chk));
	queue<pair<int, int>> qu;
	chk[src.first][src.second] = 0;
	qu.push(src);
	while (!qu.empty())
	{
		pair<int, int> node = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = node.first + dx[i]; int ny = node.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if ((room[nx][ny] == '.' || room[nx][ny] == '*') && chk[nx][ny]== -1)
			{
				chk[nx][ny] = chk[node.first][node.second] + 1;
				if (room[nx][ny] == '*')
				{
					dp[src.first][src.second][nx][ny] = chk[nx][ny];
				}
				qu.push({ nx,ny });
			}

		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		vector<pair<int, int>> dirtList;
		int res = 987654321, flag = 0;
		pair<int, int> vac;
		memset(room, 'x', sizeof(room));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> room[i][j];
				if (room[i][j] == 'o')
				{
					vac = { i,j };
					room[i][j] = '.';
				}
				if (room[i][j] == '*') dirtList.push_back({ i,j });

			}
		}
		get_track(vac);
		for (int i = 0; i < dirtList.size(); i++)
			get_track(dirtList[i]);
		do
		{
			int sum = 0;
			pair<int, int> tmpvac = vac;
			for (int i = 0; i < dirtList.size(); i++)
			{
				int len = dp[tmpvac.first][tmpvac.second][dirtList[i].first][dirtList[i].second];
				if (!len)
				{
					flag = 1;
					break;
				}
				tmpvac = dirtList[i];
				sum += len;
			}
			if (flag) break;
			if (res > sum) res = sum;
		} while (next_permutation(dirtList.begin(), dirtList.end()));
		
		if (flag) cout << -1 << "\n"; //## 여기!!!!!!!!!!!!!! -1 인경우 처리만!!!!!!
		else cout << res << "\n";
	}
	return 0;
}
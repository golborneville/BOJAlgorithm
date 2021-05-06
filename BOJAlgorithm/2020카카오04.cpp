#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int chk[27][27];
int res = 987654321;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//»óÇÏ -> 0   ÁÂ¿ì -> 1
struct info
{
	int x, y;
	int prev;
	int cost;
};
int solution(vector<vector<int>> board) {
	// int answer = 0;
	queue<info> qu;
	int N = board.size();
	qu.push({ 0,0, -1,0 });
	board[0][0] = 1;
	while (!qu.empty())
	{
		int x = qu.front().x; int y = qu.front().y;
		int prevdir = qu.front().prev;
		int cost = qu.front().cost;
		qu.pop();
		if (x == N - 1 && y == N - 1)
		{
			if (res > cost) res = cost;
			continue;
		}
		for (int i = 0; i<4; i++)
		{
			//if(abs(i-prevdir) == 2)continue;
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 1) continue;
			int tmpcost = cost;
			if (i == prevdir || prevdir == -1) tmpcost += 100;
			else tmpcost += 600;
			if (board[nx][ny] == 0 || board[nx][ny] >= tmpcost)
			{
				board[nx][ny] = tmpcost;
				qu.push({ nx,ny,i,tmpcost });
			}

		}
	}
	return res;
}
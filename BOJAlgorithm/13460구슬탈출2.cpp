#include<iostream>
#include<queue>
using namespace std;

int N, M;
char board[12][12];
int rem[12][12][12][12]; // red x y / blue x y
pair<int, int> hole;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct info
{
	int rx, ry;
	int bx, by;
};
info moveBall(info node, int dir)
{
	info nxt = node;
	int val = rem[node.rx][node.ry][node.bx][node.by];
	bool redf = false, bluef = false;
	switch (dir)
	{
	case 0: // down
		if (node.ry == node.by)
		{
			//값 크기에 따라 순서 존재
			if (node.rx < node.bx)
			{ // red is upper, blue is lower; blue -> red 순서로 이동
				while (true)
				{
					if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						bluef = true;
						break;
					}
					node.bx += dx[dir]; node.by += dy[dir];
				}
				while (true)
				{
					if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						node.rx += dx[dir]; node.ry += dy[dir];
						redf = true;
						break;
					}
					if (node.rx + dx[dir] == node.bx && node.by == node.ry + dy[dir]) break;
					node.rx += dx[dir]; node.ry += dy[dir];
				}
			}
			else
			{ // blue up - red down ; red -> blue 순서로 이동
				while (true)
				{
					if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						node.rx += dx[dir]; node.ry += dy[dir];
						redf = true;
						break;
					}
					node.rx += dx[dir]; node.ry += dy[dir];
				}
				while (true)
				{
					if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						bluef = true;
						break;
					}
					if (node.bx + dx[dir] == node.rx && node.ry == node.by + dy[dir]) break;
					node.bx += dx[dir]; node.by += dy[dir];
				}
			}
		}
		else
		{
			//그냥 움직이면 됨
			//red -> blue로 하자
			while (true)
			{
				if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
				if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
				if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
				{
					//구멍에 빠짐
					node.rx += dx[dir]; node.ry += dy[dir];
					redf = true;
					break;
				}
				node.rx += dx[dir]; node.ry += dy[dir];
			}
			while (true)
			{
				if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
				if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
				if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
				{
					//구멍에 빠짐
					bluef = true;
					break;
				}
				if (node.bx + dx[dir] == node.rx && node.ry == node.by + dy[dir]) break;
				node.bx += dx[dir]; node.by += dy[dir];
			}
		}
		if (nxt.bx == node.bx && nxt.by == node.by && nxt.rx == node.rx && nxt.ry == node.ry)
		{
			return { -1,-1,-1,-1 };
		}
		if (!bluef && !(rem[node.rx][node.ry][node.bx][node.by]))
		{
			rem[node.rx][node.ry][node.bx][node.by] = val + 1;
			return node;
		}
		else if (bluef || (rem[node.rx][node.ry][node.bx][node.by]))
		{
			//rem[node.rx][node.ry][node.bx][node.by] = -1;
			return { -1,-1,-1,-1 };
		}
		break;
	case 1: //up

		if (node.ry == node.by)
		{
			//값 크기에 따라 순서 존재
			if (node.rx > node.bx)
			{ // blue is upper, red is lower; blue -> red 순서로 이동
				while (true)
				{
					if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						bluef = true;
						break;
					}
					node.bx += dx[dir]; node.by += dy[dir];
				}
				while (true)
				{
					if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						node.rx += dx[dir]; node.ry += dy[dir];
						redf = true;
						break;
					}
					if (node.rx + dx[dir] == node.bx && node.by == node.ry + dy[dir]) break;
					node.rx += dx[dir]; node.ry += dy[dir];
				}
			}
			else
			{ // red up - blue down ; red -> blue 순서로 이동
				while (true)
				{
					if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						node.rx += dx[dir]; node.ry += dy[dir];
						redf = true;
						break;
					}
					node.rx += dx[dir]; node.ry += dy[dir];
				}
				while (true)
				{
					if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						bluef = true;
						break;
					}
					if (node.bx + dx[dir] == node.rx && node.ry == node.by + dy[dir]) break;
					node.bx += dx[dir]; node.by += dy[dir];
				}
			}
		}
		else
		{
			//그냥 움직이면 됨
			//red -> blue로 하자
			while (true)
			{
				if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
				if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
				if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
				{
					//구멍에 빠짐
					node.rx += dx[dir]; node.ry += dy[dir];
					redf = true;
					break;
				}
				node.rx += dx[dir]; node.ry += dy[dir];
			}
			while (true)
			{
				if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
				if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
				if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
				{
					//구멍에 빠짐
					bluef = true;
					break;
				}
				if (node.bx + dx[dir] == node.rx && node.ry == node.by + dy[dir]) break;
				node.bx += dx[dir]; node.by += dy[dir];
			}
		}
		if (nxt.bx == node.bx && nxt.by == node.by && nxt.rx == node.rx && nxt.ry == node.ry)
		{
			return { -1,-1,-1,-1 };
		}
		if (!bluef && !(rem[node.rx][node.ry][node.bx][node.by]))
		{
			rem[node.rx][node.ry][node.bx][node.by] = val + 1;
			return node;
		}
		else if (bluef || (rem[node.rx][node.ry][node.bx][node.by]))
		{
			//rem[node.rx][node.ry][node.bx][node.by] = -1;
			return { -1,-1,-1,-1 };
		}

		break;
	case 2: //right
		if (node.rx == node.bx)
		{
			//값 크기에 따라 순서 존재
			if (node.ry < node.by)
			{ // blue is right, red is left; blue -> red 순서로 이동
				while (true)
				{
					if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						bluef = true;
						break;
					}
					node.bx += dx[dir]; node.by += dy[dir];
				}
				while (true)
				{
					if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						node.rx += dx[dir]; node.ry += dy[dir];
						redf = true;
						break;
					}
					if (node.rx + dx[dir] == node.bx && node.by == node.ry + dy[dir]) break;
					node.rx += dx[dir]; node.ry += dy[dir];
				}
			}
			else
			{ // red right - blue left ; red -> blue 순서로 이동
				while (true)
				{
					if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						node.rx += dx[dir]; node.ry += dy[dir];
						redf = true;
						break;
					}
					node.rx += dx[dir]; node.ry += dy[dir];
				}
				while (true)
				{
					if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						bluef = true;
						break;
					}
					if (node.bx + dx[dir] == node.rx && node.ry == node.by + dy[dir]) break;
					node.bx += dx[dir]; node.by += dy[dir];
				}
			}
		}
		else
		{
			//그냥 움직이면 됨
			//red -> blue로 하자
			while (true)
			{
				if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
				if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
				if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
				{
					//구멍에 빠짐
					node.rx += dx[dir]; node.ry += dy[dir];
					redf = true;
					break;
				}
				node.rx += dx[dir]; node.ry += dy[dir];
			}
			while (true)
			{
				if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
				if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
				if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
				{
					//구멍에 빠짐
					bluef = true;
					break;
				}
				if (node.bx + dx[dir] == node.rx && node.ry == node.by + dy[dir]) break;
				node.bx += dx[dir]; node.by += dy[dir];
			}
		}
		if (nxt.bx == node.bx && nxt.by == node.by && nxt.rx == node.rx && nxt.ry == node.ry)
		{
			return { -1,-1,-1,-1 };
		}
		if (!bluef && !(rem[node.rx][node.ry][node.bx][node.by]))
		{
			rem[node.rx][node.ry][node.bx][node.by] = val + 1;
			return node;
		}
		else if (bluef || (rem[node.rx][node.ry][node.bx][node.by]))
		{
			//rem[node.rx][node.ry][node.bx][node.by] = -1;
			return { -1,-1,-1,-1 };
		}
		break;
	case 3: //left
		if (node.rx == node.bx)
		{
			//값 크기에 따라 순서 존재
			if (node.ry > node.by)
			{ // red is right, blue is left; blue -> red 순서로 이동
				while (true)
				{
					if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						bluef = true;
						break;
					}
					node.bx += dx[dir]; node.by += dy[dir];
				}
				while (true)
				{
					if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						node.rx += dx[dir]; node.ry += dy[dir];
						redf = true;
						break;
					}
					if (node.rx + dx[dir] == node.bx && node.by == node.ry + dy[dir]) break;
					node.rx += dx[dir]; node.ry += dy[dir];
				}
			}
			else
			{ // red left - blue right ; red -> blue 순서로 이동
				while (true)
				{
					if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
					if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						node.rx += dx[dir]; node.ry += dy[dir];
						redf = true;
						break;
					}
					node.rx += dx[dir]; node.ry += dy[dir];
				}
				while (true)
				{
					if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
					if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
					{
						//구멍에 빠짐
						bluef = true;
						break;
					}
					if (node.bx + dx[dir] == node.rx && node.ry == node.by + dy[dir]) break;
					node.bx += dx[dir]; node.by += dy[dir];
				}
			}
		}
		else
		{
			//그냥 움직이면 됨
			//red -> blue로 하자
			while (true)
			{
				if (node.rx + dx[dir] < 0 || node.ry + dy[dir] < 0 || node.rx + dx[dir] >= N || node.ry + dy[dir] >= M) break;
				if (board[node.rx + dx[dir]][node.ry + dy[dir]] == '#') break;
				if (board[node.rx + dx[dir]][node.ry + dy[dir]] == 'O')
				{
					//구멍에 빠짐
					node.rx += dx[dir]; node.ry += dy[dir];
					redf = true;
					break;
				}
				node.rx += dx[dir]; node.ry += dy[dir];
			}
			while (true)
			{
				if (node.bx + dx[dir] < 0 || node.by + dy[dir] < 0 || node.bx + dx[dir] >= N || node.by + dy[dir] >= M) break;
				if (board[node.bx + dx[dir]][node.by + dy[dir]] == '#') break;
				if (board[node.bx + dx[dir]][node.by + dy[dir]] == 'O')
				{
					//구멍에 빠짐
					bluef = true;
					break;
				}
				if (node.bx + dx[dir] == node.rx && node.ry == node.by + dy[dir]) break;
				node.bx += dx[dir]; node.by += dy[dir];
			}
		}
		if (nxt.bx == node.bx && nxt.by == node.by && nxt.rx == node.rx && nxt.ry == node.ry)
		{
			return { -1,-1,-1,-1 };
		}
		if (!bluef && !(rem[node.rx][node.ry][node.bx][node.by]))
		{
			rem[node.rx][node.ry][node.bx][node.by] = val + 1;
			return node;
		}
		else if(bluef || (rem[node.rx][node.ry][node.bx][node.by]))
		{
			//rem[node.rx][node.ry][node.bx][node.by] = -1;
			return { -1,-1,-1,-1 };
		}

		break;
	}
}
int play(pair<int, int> red, pair<int,int> blue)
{
	queue<info> qu;
	//rem[red.first][red.second][blue.first][blue.second] = 1;
	qu.push({ red.first, red.second, blue.first, blue.second });
	while (!qu.empty())
	{
		info node = qu.front();
		qu.pop();

		//if (rem[node.rx][node.ry][node.bx][node.by]) continue;
		for (int i = 0; i < 4; i++)
		{
			//각 방향으로 노력해보기....
			info nxt = moveBall(node, i);
			//if (nxt.bx == node.bx && nxt.by == node.by && nxt.rx == node.rx && nxt.ry == node.ry) continue; // 움직이지 않았다
			if (nxt.bx == -1 && nxt.by == -1 && nxt.rx == -1 && nxt.ry == -1) continue; //blue got in the hole
			//red만 빠져 나오는거 성공?
			if (nxt.rx == hole.first && nxt.ry == hole.second) return rem[nxt.rx][nxt.ry][nxt.bx][nxt.by];
			if (rem[nxt.rx][nxt.ry][nxt.bx][nxt.by] >= 10) continue; //10번 초과 경우 실패 
			qu.push(nxt);
		}

	}
	return -1;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	pair<int, int> red, blue;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'B')
			{
				blue = { i,j };
				board[i][j] = '.';
			}
			if (board[i][j] == 'R')
			{
				red = { i,j };
				board[i][j] = '.';
			}
			if (board[i][j] == 'O') hole = { i,j };
		}
	}
	int res = play(red, blue);
	cout << res;
	return 0;
}
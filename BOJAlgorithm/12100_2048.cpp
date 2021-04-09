#include<iostream>
#include<cstring>
using namespace std;

int N;
int board[22][22];
int origin[22][22];
int res = 0;
int dx[4] = { -1,1,0,0 }; //up - down - left - right
int dy[4] = { 0,0,-1,1 };
bool chk[22][22];
int comb[5];
int getMaxBlock()
{
	int cmp = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (cmp < board[i][j]) cmp = board[i][j];
		}
	}
	return cmp;
}
void slide(int dir)
{
	int val, nx, ny;
	switch (dir)
	{
	case 0://up
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				////다시 구현하자 시발
				//nx = i; ny = j;
				//while (nx >= 0)
				//{
				//	if (board[nx][ny] != 0)
				//	{

				//	}
				//	nx = nx + dx[dir];
				//}
				val = board[i][j];
				if (val == 0)continue;
				board[i][j] = 0;
				nx = i + dx[dir]; ny = j + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				{
					board[i][j] = val;
					continue;
				}
				while (board[nx][ny] == 0)
				{
					nx = nx + dx[dir]; ny = ny + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					{
						nx = nx - dx[dir]; ny = ny - dy[dir];
						break;
					}
				}
				if (board[nx][ny] == val)
				{ //same number-> add sum!
					if (!chk[nx][ny])
					{
						board[nx][ny] *= 2;
						chk[nx][ny] = true;
					}
					else
					{
						nx = nx - dx[dir]; ny = ny - dy[dir];
						board[nx][ny] = val;
					}
				}
				else if (board[nx][ny] == 0)
				{
					board[nx][ny] = val;
				}
				else
				{
					nx = nx - dx[dir]; ny = ny - dy[dir];
					board[nx][ny] = val;
				}

			}
		}
		break;
	case 1: //down
		for (int i = N-1; i >=0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				val = board[i][j];
				if (val == 0)continue;
				board[i][j] = 0;
				nx = i + dx[dir]; ny = j + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				{
					board[i][j] = val;
					continue;
				}
				while (board[nx][ny] == 0)
				{
					nx = nx + dx[dir]; ny = ny + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					{
						nx = nx - dx[dir]; ny = ny - dy[dir];
						break;
					}
				}
				if (board[nx][ny] == val)
				{ //same number-> add sum!
					if (!chk[nx][ny])
					{
						board[nx][ny] *= 2;
						chk[nx][ny] = true;
					}
					else
					{
						nx = nx - dx[dir]; ny = ny - dy[dir];
						board[nx][ny] = val;
					}
				}
				else if (board[nx][ny] == 0)
				{
					board[nx][ny] = val;
				}
				else
				{
					nx = nx - dx[dir]; ny = ny - dy[dir];
					board[nx][ny] = val;
				}

			}
		}
		break;
	case 2: //left
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				val = board[i][j];
				if (val == 0)continue;
				board[i][j] = 0;
				nx = i + dx[dir]; ny = j + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				{
					board[i][j] = val;
					continue;
				}
				while (board[nx][ny] == 0)
				{
					nx = nx + dx[dir]; ny = ny + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					{
						nx = nx - dx[dir]; ny = ny - dy[dir];
						break;
					}
				}
				if (board[nx][ny] == val)
				{ //same number-> add sum!
					if (!chk[nx][ny])
					{
						board[nx][ny] *= 2;
						chk[nx][ny] = true;
					}
					else
					{
						nx = nx - dx[dir]; ny = ny - dy[dir];
						board[nx][ny] = val;
					}
				}
				else if (board[nx][ny] == 0)
				{
					board[nx][ny] = val;
				}
				else
				{
					nx = nx - dx[dir]; ny = ny - dy[dir];
					board[nx][ny] = val;
				}
			}
		}
		break;
	case 3://right
		for (int j = N-1; j >= 0; j--)
		{
			for (int i = 0; i < N; i++)
			{
				val = board[i][j];
				if (val == 0)continue;
				board[i][j] = 0;
				nx = i + dx[dir]; ny = j + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				{
					board[i][j] = val;
					continue;
				}
				while (board[nx][ny] == 0)
				{
					nx = nx + dx[dir]; ny = ny + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					{
						nx = nx - dx[dir]; ny = ny - dy[dir];
						break;
					}
				}
				if (board[nx][ny] == val)
				{ //same number-> add sum!
					if (!chk[nx][ny])
					{
						board[nx][ny] *= 2;
						chk[nx][ny] = true;
					}
					else
					{
						nx = nx - dx[dir]; ny = ny - dy[dir];
						board[nx][ny] = val;
					}
				}
				else if (board[nx][ny] == 0)
				{
					board[nx][ny] = val;
				}
				else
				{
					nx = nx - dx[dir]; ny = ny - dy[dir];
					board[nx][ny] = val;
				}
			}
		}
		break;
	}
}
void moveBoard()
{
	
	for (int d = 0; d < 5; d++)
	{
		memset(chk, false, sizeof(chk));
		//move board
		slide(comb[d]);


	}
}
void get_comb(int dep)
{
	if (dep == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j] = origin[i][j];
			}
		}
		moveBoard();
		//5 times moved-> get max block and return 
		int mblock = getMaxBlock();
		if (res < mblock) res = mblock;
		return;
	}
	for (int d = 0; d < 4; d++)
	{
		comb[dep] = d;
		get_comb(dep + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			origin[i][j] = board[i][j];
		}
	}

	get_comb(0);

	cout << res;
	return 0;
}
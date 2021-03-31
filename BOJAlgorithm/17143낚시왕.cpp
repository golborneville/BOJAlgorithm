#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int R, C, M, sum = 0;
vector<int> sea[102][102];
//1 up, 2 down, 3 right, 4 left
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
struct info 
{
	int sharknum, x, y, speed, dir, size, alive;
};
info shark[10002];

bool cmp(int a, int b)
{
	return shark[a].size > shark[b].size;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y >> shark[i].speed >> shark[i].dir >> shark[i].size;
		shark[i].sharknum = i;
		shark[i].alive = 1;
		shark[i].x = x - 1;
		shark[i].y = y - 1;

		sea[shark[i].x][shark[i].y].push_back(i);
	}
	for (int i = 0; i < C; i++) //column
	{
		//어부가 한칸씩 이동
		//1. eat nearest shark -> 이상태에선 한칸에 하나의 상어만임을 보장
		for (int j = 0; j < R; j++)
		{
			if (sea[j][i].size() > 0 && shark[sea[j][i][0]].alive)
			{
				sum += shark[sea[j][i][0]].size;
				shark[sea[j][i][0]].alive = 0;
				sea[j][i].pop_back();
				break;
			}
		}

		//2. move sharks-> 시간 초과 나면 여기 shark 벡터로 재구현 필요
		for (int s = 0; s < M; s++)
		{
			if (!shark[s].alive) continue;
			//shark list update, -> x, y, dir 만 수정필요
			int move;
			int nx = shark[s].x; int ny = shark[s].y;
			if (shark[s].dir == 1 || shark[s].dir == 2)
			{
				//up down
				move = shark[s].speed * dx[shark[s].dir];
				//nx = shark[s].x + move;
				if (shark[s].x + move >= 0 && shark[s].x + move < R)
				{
					nx = shark[s].x + move;
				}
				else if (shark[s].x + move >= R)
				{
					nx = move;
					nx -= (R - 1 - shark[s].x);
					if ((nx / (R - 1)) % 2)
					{
						//몫이 odd
						nx = (nx % (R - 1));
						shark[s].dir = 2;
					}
					else
					{
						//몫 even
						nx = (R - 1) - (nx % (R - 1));
						shark[s].dir = 1;
					}
				}
				else if (shark[s].x + move < 0)
				{
					nx = move * -1;
					//nx *= -1;
					nx -= shark[s].x;
					if ((nx / (R - 1)) % 2)
					{
						//몫이 odd
						nx = (R - 1) - (nx % (R - 1));
						shark[s].dir = 1;
					}
					else
					{
						//몫 even
						nx = (nx % (R - 1));
						shark[s].dir = 2;
					}
				}

			}
			else if (shark[s].dir == 3 || shark[s].dir == 4)
			{
				//right left
				move = shark[s].speed * dy[shark[s].dir];
				//ny = shark[s].y + move;
				if (shark[s].y + move >= 0 && shark[s].y + move < C)
				{
					ny = shark[s].y + move;
				}
				if (shark[s].y + move >= C)
				{
					ny = move;
					ny -= (C - 1 - shark[s].y);
					if ((ny / (C-1)) % 2)
					{
						//몫이 odd
						ny = (ny % (C-1));
						shark[s].dir = 3;
					}
					else
					{
						//몫 even
						ny = C - 1 - (ny % (C-1));
						shark[s].dir = 4;
					}
				}
				else if (shark[s].y + move < 0)
				{
					ny = move * -1;
					ny -= shark[s].y;
					if ((ny / (C - 1)) % 2)
					{
						//몫이 odd
						ny = (C - 1) - (ny % (C - 1));
						shark[s].dir = 4;
					}
					else
					{
						//몫 even
						ny = (ny % (C - 1));
						shark[s].dir = 3;
					}
				}
			}

		
			//sea array upadate
			auto iter = find(sea[shark[s].x][shark[s].y].begin(), sea[shark[s].x][shark[s].y].end(), shark[s].sharknum);
			sea[shark[s].x][shark[s].y].erase(iter);

			shark[s].x = nx; shark[s].y = ny;
			sea[nx][ny].push_back(shark[s].sharknum);
			
		}

		//3. sharks eat each other where they are together(bigger one wins)
		for (int s = 0; s < M; s++)
		{
			if (sea[shark[s].x][shark[s].y].size() > 1)
			{
				sort(sea[shark[s].x][shark[s].y].begin(), sea[shark[s].x][shark[s].y].end(), cmp);
				while (sea[shark[s].x][shark[s].y].size() > 1)
				{
					int ind = 0; 
					shark[sea[shark[s].x][shark[s].y][sea[shark[s].x][shark[s].y].size() - 1]].alive = 0;
					sea[shark[s].x][shark[s].y].pop_back();
				}
			}
		}
	}
	//cout the total of size of sharks caught by fisherman
	cout << sum;
	return 0;
}
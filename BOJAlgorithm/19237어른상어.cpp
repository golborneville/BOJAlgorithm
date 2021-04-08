#include<iostream>
#include<map>
using namespace std;

int N, M, K;
pair<int,int> sea[22][22]; //냄새(shakr N.)와 남은 유지시간
int dx[5] = { 0, -1, 1, 0, 0 };//위 아래 왼 오른
int dy[5] = { 0, 0, 0, -1, 1 };

int sharkdir[402][5][5]; //shark's direction priority
struct info
{
	int dir, x, y;
};
info shark[402]; //shark's current direction, pos
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int value;
			cin >> value;
			if (!value)
				sea[i][j] = { value ,0 };
			else
			{
				sea[i][j] = { value, K };
				shark[value] = { 0, i,j }; //0 is temp
			}
		}
	}
	for (int i = 1; i <= M; i++)
		cin >> shark[i].dir;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> sharkdir[i][j][k];
			}
			
		}
	}
	int rep = M;
	int timecnt = 0;
	while (rep > 1)
	{
		if (timecnt >= 1000)
		{
			cout << -1;
			return 0;
		}
		timecnt++;
		map<int, info> input; //shark N, pos
		//move all sharks. 
		//while doing it , pop where same pos
		for (int i = 1; i <= M; i++)
		{

			//#################
			//추가로 처리해얗 ㅏ는 부분: 중간에 emer 로 값 넣은 다음에 후 순서의 상어가 K+1 이라서 접근 가능해짐 -> 원래부터 차있던 자리라 안된다소 ㅅㅂ
			//################
			if (shark[i].x == -1 && shark[i].y == -1) continue; //dead shark
			//choose where to move
			//update sea & shark;
			bool flag = false;
			int x = shark[i].x; int y = shark[i].y; int dir = shark[i].dir;
			pair<int, int> emer;
			int emdir =0;
			for (int j = 0; j < 4; j++)
			{
				int ndir = sharkdir[i][dir][j];
				int nx = x + dx[sharkdir[i][dir][j]];
				int ny = y + dy[sharkdir[i][dir][j]];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
				if (sea[nx][ny].first == 0)
				{
					flag = true;
					input.insert({ i,{ndir, nx, ny} });
					break;
				}

				/*if (sea[nx][ny].first == 0 || sea[nx][ny].second == K + 1)
				{
					//다음 이동!
					flag = true;
					if (sea[nx][ny].first == 0)
					{
						sea[nx][ny] = { i, K + 1 };
						shark[i] = { ndir,nx,ny };
					}
					else
					{
						if (sea[nx][ny].first > i)
						{
							int num = sea[nx][ny].first;
							sea[nx][ny] = { i, K + 1 };
							shark[num] = { -1,-1,-1 }; //dead

						}
						else
						{
							//shark[sea[nx][ny].first] = { ndir,nx,ny };
							shark[i] = { -1,-1,-1 }; //dead
						}
						rep--;
					}
					break;
				}*/
				if (sea[nx][ny].first == i && emdir == 0)
				{
					emer = { nx, ny };
					emdir = ndir;
				}
			}
			if (!flag)
			{
				//sea[emer.first][emer.second] = { i, K + 1 };
				//shark[i] = { emdir ,emer.first, emer.second};
				input.insert({ i,{ emdir ,emer.first, emer.second } });
			}
		}

		//map->sea
		for (auto iter = input.begin(); iter != input.end(); iter++)
		{
			int nx = iter->second.x; int ny = iter->second.y; int ndir = iter->second.dir;
			if (sea[nx][ny].first == 0 || sea[nx][ny].first == iter->first)
			{
				sea[nx][ny] = { iter->first, K + 1 };
				shark[iter->first] = { ndir,nx,ny };
			}
			else
			{
				if (sea[nx][ny].first > iter->first)
				{
					int num = sea[nx][ny].first;
					sea[nx][ny] = { iter->first, K + 1 };
					shark[num] = { -1,-1,-1 }; //dead

				}
				else if(sea[nx][ny].first < iter->first)
				{
					shark[iter->first] = { -1,-1,-1 }; //dead
				}
				rep--;
			}
		}

		//all smell -1 sec
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (sea[i][j].first)
				{
					sea[i][j].second--;
					if (!sea[i][j].second)
						sea[i][j].first = 0;
				}
			}
		}

	}
	cout << timecnt;
	return 0;
}
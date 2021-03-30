#include<iostream>
#include<vector>
#include <deque>
using namespace std;


int N, K;
int mapcolor[14][14];
vector<int> pos_hor[14][14];
struct info {
	int x; 
	int y;
	int dir;
};
info horse[12];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> mapcolor[i][j]; // 0 white, 1 red, 2 blue
		}
	}

	for (int i = 1; i <= K; i++)
	{
		cin >> horse[i].x >> horse[i].y >> horse[i].dir;
		pos_hor[horse[i].x][horse[i].y].push_back(i);
	}

	for(int t=1; t<=1000; t++)
	{
		for (int i = 1; i <= K; i++)
		{
			int nx = horse[i].x + dx[horse[i].dir];
			int ny = horse[i].y + dy[horse[i].dir];
			int color, opdir, flag = 0;;
			deque<int> leave;
			if (nx <= 0 || ny <= 0 || nx > N || ny > N) color = 2;
			else color = mapcolor[nx][ny];
			switch (color)
			{
				case 0: //white
					for (int l = 0; l < pos_hor[horse[i].x][horse[i].y].size(); l++) {
						if (pos_hor[horse[i].x][horse[i].y][l] == i) flag = 1;
						if (flag)
						{// 여기 이동하는 수정 중이엇음 *** 스택 순서 조심할것

							leave.push_back(pos_hor[horse[i].x][horse[i].y][l]);
						}
					}
					for (int e = 0; e < leave.size(); e++)
					{
						pos_hor[horse[i].x][horse[i].y].pop_back();
						pos_hor[nx][ny].push_back(leave[e]);
					}
					for (int e = 0; e < leave.size(); e++)
					{
						horse[leave[e]].x = nx; horse[leave[e]].y = ny;
					}

					break;
				case 1: //red
					for (int l = 0; l < pos_hor[horse[i].x][horse[i].y].size(); l++) {
						if (pos_hor[horse[i].x][horse[i].y][l] == i) flag = 1;
						if (flag)
						{
							leave.push_front(pos_hor[horse[i].x][horse[i].y][l]);
						}
					}
					for (int e = 0; e < leave.size(); e++)
					{
						pos_hor[horse[i].x][horse[i].y].pop_back();
						pos_hor[nx][ny].push_back(leave[e]);
					}
					for (int e = 0; e < leave.size(); e++)
					{
						horse[leave[e]].x = nx; horse[leave[e]].y = ny;
					}

					break;
				case 2: //blue
					if (horse[i].dir == 1) opdir = 2;
					else if (horse[i].dir == 2) opdir = 1;
					else if (horse[i].dir == 4) opdir = 3;
					else if (horse[i].dir == 3) opdir = 4;

					nx = horse[i].x + dx[opdir];
					ny = horse[i].y + dy[opdir];
					horse[i].dir = opdir;
					if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
					if (mapcolor[nx][ny] != 2)
					{
						for (int l = 0; l < pos_hor[horse[i].x][horse[i].y].size(); l++) {
							if (pos_hor[horse[i].x][horse[i].y][l] == i) flag = 1;
							if (flag)
							{// 여기 이동하는 수정 중이엇음 *** 스택 순서 조심할것
								if(mapcolor[nx][ny] == 0)
									leave.push_back(pos_hor[horse[i].x][horse[i].y][l]);
								else if(mapcolor[nx][ny] == 1)
									leave.push_front(pos_hor[horse[i].x][horse[i].y][l]);
							}
						}
						for (int e = 0; e < leave.size(); e++)
						{
							pos_hor[horse[i].x][horse[i].y].pop_back();
							pos_hor[nx][ny].push_back(leave[e]);
						}
						for (int e = 0; e < leave.size(); e++)
						{
							horse[leave[e]].x = nx; horse[leave[e]].y = ny;
						}
					}
					break;
			}

			if (pos_hor[nx][ny].size() >= 4)
			{
				cout << t;
				return 0;
			}
			
		}
	}
	cout << -1;
	return 0;
}
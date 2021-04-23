#include<iostream>
#include<queue>
using namespace std;

bool chk[52][52];
char cave[52][52];
int R, C, total = 0;
pair<int, int> beaver, door;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, pair<int, int>>> moveB; // { step #, {x, y}} -> beaver
queue<pair<int, pair<int, int>>> water; // { step #, {x, y}} -> water

int BFS() //틀렸습니다 뜨는거 보니까 반례 찾아보자 ㅠ
{
	int step = 1; //need update dont forget
	while (total > 0) // while there is empty space left
	{
	//1. beaver moves 1 
		//if moved pos is predicted to be flooded in the next move, not a valid move
		while (!moveB.empty() && moveB.front().first == step)
		{
			int tmpstep = moveB.front().first;
			pair<int, int> Bpos = moveB.front().second;
			moveB.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = Bpos.first + dx[i]; int ny = Bpos.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (cave[nx][ny] == 'D') return tmpstep;
				if (cave[nx][ny] != '.' || chk[nx][ny] != 0) continue; 
				bool flag = false;
				for (int s = 0; s < 4; s++)
				{
					int nnx = nx + dx[s]; int nny = ny + dy[s];
					if (nnx < 0 || nny < 0 || nnx >= R || nny >= C) continue;
					if (cave[nnx][nny] == '*')
					{
						flag = true;
						break;
					}
				}
				if (flag)continue;
				moveB.push({ tmpstep + 1,{nx,ny} });
				chk[nx][ny] = 1;
			}
		}
		if (moveB.empty()) return -1;
	//2. overflow water based on '*'
		while (!water.empty() && water.front().first == step)
		{
			int tmpstep = water.front().first;
			pair<int, int> Bpos = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = Bpos.first + dx[i]; int ny = Bpos.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (cave[nx][ny] != '.') continue; //|| chk[nx][ny] != 0

				water.push({ tmpstep + 1,{ nx,ny } });
				cave[nx][ny] = '*';
				total--;
				if (total <= 0) return -1;
			}
		}
		step++;
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	
	total = R * C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> cave[i][j];
			if (cave[i][j] == 'S')
			{	
				cave[i][j] = '.';
				beaver = { i,j };
				chk[i][j] = 1;
			}
			if (cave[i][j] == 'D') door = { i,j };
			if (cave[i][j] == 'X') total--;;
			if (cave[i][j] == '*')
			{
				total--;
				water.push({ 1,{i,j} });
			}
		}
	}
	//요기가 문제였네 ㅋㅋㅋ
	if (R * C == 1)
	{
		cout << "KAKTUS";
		return 0;
	}
	if (total == 2) 
	{
		cout << 1;
		return 0;
	}
	total -= 2;
	moveB.push({ 1, {beaver.first, beaver.second} });
	int res = BFS();
	if (res == -1)
		cout << "KAKTUS";
	else
		cout << res;
	return 0;
}
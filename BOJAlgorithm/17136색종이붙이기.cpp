#include<iostream>
#include<algorithm>
using namespace std;

int paper[12][12];
int cnt[5] = { 0,0,0,0,0 };
int minres = 987654321;
bool try_attach(int x, int y, int size)
{
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			if (!paper[x + i][y + j]) return false;
		}
	}
	return true;
}
void update_paper(int x, int  y, int size, int flag) //0 attach, 1 detach
{
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			paper[x + i][y + j] = flag;
		}
	}
}
void DFS(int x, int y, int pp)
{
	
	while (paper[x][y] == 0)
	{
		y++;
		if (y >= 10)
		{
			x++;
			y = 0;
			if (x >= 10)
			{
				minres = min(minres, pp);
				return;
			}
		}
	}
	if (minres <= pp) return; //굳이 더 이상 진행할 이유X ( 어차피 최솟값 아님..)

	//모든 크기 도전 5~1 
	for (int i = 4; i >= 0; i--)
	{
		//남은 색종이 없거나 범위 넘어감
		if (x + i >= 10 || y + i >= 10 || cnt[i] == 5) continue;

		if (try_attach(x, y, i))
		{
			update_paper(x, y, i, 0);
			cnt[i]++;
			DFS(x, y, pp + 1);

			update_paper(x, y, i, 1);
			cnt[i]--;
		}

	}

}
int main()
{
	int tcnt = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> paper[i][j];
			if (paper[i][j]) tcnt++;
		}
	}
	if (tcnt == 100)
	{
		cout << 4; 
		return 0;
	}
	DFS(0, 0, 0);
	if (minres == 987654321) minres = -1;
	cout << minres;
	return 0;

}
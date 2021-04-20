#include<iostream>
#include<string>
using namespace std;

int R, C;
char arr[22][22];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool chk[26]; // alphabet chk
int res = 1;

void DFS(int x, int y, int cnt) // 얘를 string, str.size() 에서 cnt 로 바꿔주니 시간 초과 해결남 (WHY>>>?) size()는 O(1)아닌가?
{
	if (res < cnt) res = cnt;
	for (int i = 0; i < 4; i++)
	{
		int nx =x + dx[i]; int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > R || ny > C) continue;
		if (chk[arr[nx][ny] - 'A']) continue;
		chk[arr[nx][ny] - 'A'] = true;
		DFS(nx, ny, cnt +1);
		chk[arr[nx][ny] - 'A'] = false;
	}


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	chk[arr[1][1] - 'A'] = true;
	DFS(1,1, 1);
	cout << res;
	return 0;
}
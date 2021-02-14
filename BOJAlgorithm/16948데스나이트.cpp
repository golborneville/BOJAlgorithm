#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int dr[6] = { -2,-2,0,0,2,2 };
int dc[6] = { -1,1,-2,2,-1,1 };
int N;
//int chess[202][202];
int chk[202][202];
int BFS(int r1, int c1, int r2, int c2) {
	queue<pair<int, int>> qu;

	chk[r1][c1] = 0;
	qu.push({ r1,c1 });
	while (!qu.empty()) {
		pair<int, int> node = qu.front();
		qu.pop();
		for (int i = 0; i < 6; i++) {
			int nx = node.first + dr[i];
			int ny = node.second + dc[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (chk[nx][ny]==-1) {
				qu.push({ nx,ny });
				chk[nx][ny] =chk[node.first][node.second] +1;
				if (nx == r2 && ny == c2) return chk[nx][ny];
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(chk, -1, sizeof(chk));
	cin >> N;
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int res = BFS(r1, c1, r2, c2);
	cout << res;
	return 0;
}

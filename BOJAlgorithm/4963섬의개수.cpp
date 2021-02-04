#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

queue<pair<int, int>> qu;
int island[53][53];
bool chk[53][53];
int w, h;
int dx[8] = { 1,-1,0,0, 1,-1,1,-1 };
int dy[8] = { 0,0,1,-1, 1,1,-1,-1 };
int CNT = 0;
void BFS(int x, int y) {
	if (chk[x][y]) return;
	CNT++;
	chk[x][y] = true;
	qu.push({ x,y });
	while (!qu.empty()) {
		pair<int, int> front = qu.front();
		qu.pop();
		for (int i = 0; i < 8; i++) {
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h)continue;
			if (!chk[nx][ny] && island[nx][ny]) {
				qu.push({ nx,ny });
				chk[nx][ny] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int T;
	//cin >> T;
	do {
		cin >> h >> w;
		if (!w && !h)continue;
		memset(island, 0, sizeof(island));
		memset(chk, false, sizeof(chk));
		CNT = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> island[i][j];
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (island[i][j]) {
					BFS(i, j);
				}
			}
		}
		cout << CNT << "\n";
	} while (w || h);
}
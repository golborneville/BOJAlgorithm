#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int field[55][55];
bool chk[55][55];
int T, M, N, K, cnt = 0;

void BFS(int x, int y) {
	cnt++;
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	chk[x][y] = true;
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (!chk[node.first + dx[i]][node.second + dy[i]]
				 && field[node.first + dx[i]][node.second + dy[i]] == 1) {
				q.push(make_pair(node.first + dx[i], node.second + dy[i]));
				chk[node.first + dx[i]][node.second + dy[i]] = true;
			}
		}

	}
	


}
int main() {
	scanf_s("%d", &T);
	while (T--) {
		cnt = 0;
		memset(field, 0, sizeof(field));
		memset(chk, false, sizeof(chk));
		scanf_s("%d %d %d", &M, &N, &K);
		while (K--) {
			int X, Y;
			scanf_s("%d %d", &X, &Y);
			field[X][Y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!chk[i][j] && field[i][j] == 1) {
					BFS(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
}
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int T, N, K,total = 0;
int road[10][10]; //8*8
int chk[10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
int BFS(int x, int y) {
	int most = 0;
	chk[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (road[nx][ny] < road[node.first][node.second]) {
					q.push({ nx,ny });
					chk[nx][ny] = chk[node.first][node.second] + 1;
					if (most < chk[nx][ny])most = chk[nx][ny];
				}
			}
		}
	}
	return most;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++) {
		memset(road, 0, sizeof(road));
		memset(chk, 0, sizeof(chk));
		total = 0;
		//input
		cin >> N >> K;
		int tmpMax = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> road[i][j];
				if (tmpMax < road[i][j])tmpMax = road[i][j];
			}
		}
		//최대 봉우리 탐색 -> K개의 경우에 수 만큼 계산
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (road[i][j] != tmpMax)continue;
				//
				for (int l = 0; l < N; l++) {
					for (int m = 0; m < N; m++) {
						if (i == l && j == m)continue; //가장높은 봉우리 제외
						for (int k = 0; k <= K; k++) {
							int roadCnt = BFS(i, j); //최대경로수 반환
							if (roadCnt > total) total = roadCnt;
							memset(chk, 0, sizeof(chk));
							road[l][m]--;
						}
						road[l][m] += K +1;
					}
				}
			}
		}
		cout << "#" << t << " " << total << "\n";
	}
}
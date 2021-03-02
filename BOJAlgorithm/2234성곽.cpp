#include<iostream>
#include<bitset>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

bool chk[53][53];
vector<int> castle[53][53]; // pos 기준 갈 수 잇는 방향 1서 2북 4동 8남 // 사이즈 0~4 가능
//인덱스 접근 위해 서0 북1 동2 남3
int M, N;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = -987654321; //answer 2
int sumres = -987654321; //answer 3

int chkRoom(int x, int y) {
	int ss = 1;
	queue<pair<int, int>> qu;

	chk[x][y] = true;
	qu.push({ x,y });
	while (!qu.empty()) {
		pair<int, int> front = qu.front();
		qu.pop();
		for (int i = 0; i < castle[front.first][front.second].size(); i++) {
			int nx = front.first + dx[castle[front.first][front.second][i]]; int ny = front.second + dy[castle[front.first][front.second][i]];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (!chk[nx][ny]) {
				ss++;
				qu.push({ nx,ny });
				chk[nx][ny] = true;
			}
		}
	}
	return ss;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	unsigned int west = 0x1;
	unsigned int north = 0x2;
	unsigned int east = 0x4;
	unsigned int south = 0x8;
	int roomcnt = 0; //answer 1

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (!(tmp & west)) castle[i][j].push_back(0);
			if (!(tmp & north)) castle[i][j].push_back(1);
			if (!(tmp & east)) castle[i][j].push_back(2);
			if (!(tmp & south)) castle[i][j].push_back(3);
			sort(castle[i][j].begin(), castle[i][j].end());
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!chk[i][j]) {
				int tmpSize = chkRoom(i, j);
				roomcnt++;
				if (res < tmpSize) res = tmpSize;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (castle[i][j].size() == 4) continue;
			for (int ind = 0; ind < 4; ind++) {
				bool flag = false;
				for (int k = 0; k < castle[i][j].size(); k++) {
					if (castle[i][j][k] == ind) flag = true;
				}
				if (flag)continue;

				castle[i][j].push_back(ind);
				memset(chk, false, sizeof(chk));
				if (!chk[i][j]) {
					int tmpSize = chkRoom(i, j);
					
					if (sumres < tmpSize) sumres = tmpSize;
					
				}
				castle[i][j].pop_back();
			}
		}
	}

	cout << roomcnt << "\n" << res << "\n" << sumres;

	return 0;
}
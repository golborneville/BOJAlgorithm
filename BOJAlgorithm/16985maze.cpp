#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
#include<algorithm>
using namespace std;
int chk[5][5][5];
int cube[5][5][5];//floor , x, y
int tmpcube[5][5][5];
int original[5][5][5];
int leastMove = 987654321;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int df[6] = {0,0,0,0,1,-1};
int floorNum[5] = { 0,1,2,3,4 };
void rotateCube(int floor, int angl) { // 몇층 , 몇번(90도 회전 기준 몇회- 시계 방향)
	for (int a = 0; a < angl; a++) {
		//int tmp[5] = {cube[floor][0][4],cube[floor][1][4] ,cube[floor][2][4] ,cube[floor][3][4] ,cube[floor][4][4] };
		int preval[5][5][5];
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					preval[i][j][k] = cube[i][j][k];
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) { // 0->4
				cube[floor][j][4-i] = preval[floor][i][j];
			}
		}
	}
}
void resetCube() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cube[i][j][k] = tmpcube[i][j][k];
			}
		}
	}
}
int BFS(tuple<int,int,int> src, tuple<int, int, int> des) {
	queue<tuple<int, int, int>> q;
	chk[get<0>(src)][get<1>(src)][get<2>(src)] = 0;
	q.push(src);
	while (!q.empty()) {
		tuple<int, int, int> front = q.front();
		int f = get<0>(front);
		int px = get<1>(front);
		int py = get<2>(front);
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nf = f + df[i];
			int npx = px + dx[i];
			int npy = py + dy[i];
			if (nf < 0 || npx < 0 || npy < 0 || nf >= 5 || npx >= 5 || npy >= 5)continue;
			if (cube[nf][npx][npy] && chk[nf][npx][npy] == -1) {
				q.push({nf, npx, npy});
				chk[nf][npx][npy] = chk[f][px][py] + 1;
			}

		}
	}

	if (chk[4][4][4] == -1) {
		return -1;
	}
	else {
		return chk[4][4][4];
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(chk, -1, sizeof(chk));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> cube[i][j][k];
				original[i][j][k] = cube[i][j][k];
			}
		}
	}
	do {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					tmpcube[i][j][k] = original[floorNum[i]][j][k];
				}
			}
		}
	
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l < 4; l++) {
						for (int m = 0; m < 4; m++) {
							resetCube();

							//회전!
							rotateCube(0, i);
							rotateCube(1, j);
							rotateCube(2, k);
							rotateCube(3, l);
							rotateCube(4, m);
					
							//BFS로 최단거리 탐색
							int tmpcmp = -1;
							//4가지 경우
							//0,0,0 - 4,4,4
							if(cube[0][0][0] ==1)
								tmpcmp = BFS({ 0,0,0 }, { 4,4,4 });
							memset(chk, -1, sizeof(chk));//chk init
							if (leastMove > tmpcmp && tmpcmp!=-1) leastMove = tmpcmp;
						
							if (leastMove == 12) {
								cout << 12;
								return 0;
							}
						}
					}
				}
			}
		}
	} while (next_permutation(floorNum, floorNum + 5));
	if (leastMove == 987654321) {
		cout << -1;
		return 0;
	}
	cout << leastMove;
	return 0;

}
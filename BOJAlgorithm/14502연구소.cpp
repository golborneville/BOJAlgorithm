#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

int N, M, safe_area = 0, max_safe = 0, infec = 0;
int arr[10][10];
int chk[10][10];
vector<pair<int, int>> q;
queue<pair<int, int>> each;
vector<pair<int, int>> occ[3];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void BFS(int x, int y) {
	chk[x][y] = 2;
	each.push(make_pair(x, y));
	while (!each.empty()) {
		int fir = each.front().first;
		int sec = each.front().second;
		each.pop();
		for (int j = 0; j < 4; j++) {
			//int node = arr[x + dx[j]][y + dy[j]];
			if (chk[fir + dx[j]][sec + dy[j]] == 0) {
				chk[fir + dx[j]][sec + dy[j]] = 2;
				each.push(make_pair(fir + dx[j], sec + dy[j]));
				infec++;
			}
		}
		if (infec + 3 == safe_area)
			return;
	}
}
int main() {
	memset(arr, -1, sizeof(arr));
	memset(chk, -1, sizeof(chk));
	scanf_s("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%d", &arr[i][j]);
			chk[i][j] = arr[i][j];

			if (arr[i][j] == 2) {
				q.push_back(make_pair(i, j));
			}
			if (arr[i][j] == 0) {
				safe_area++;
				occ[0].push_back(make_pair(i, j));
				occ[1].push_back(make_pair(i, j));
				occ[2].push_back(make_pair(i, j));
			}
		}
	}

	
	for (int a = 0; a < occ[0].size(); a++) {
		for (int b = a+1; b < occ[1].size(); b++) {
			for (int c = b+1; c < occ[2].size(); c++) {

				//add wall 
				int o0_x = occ[0][a].first;
				int o0_y = occ[0][a].second;

				int o1_x = occ[1][b].first;
				int o1_y = occ[1][b].second;
				
				int o2_x = occ[2][c].first;
				int o2_y = occ[2][c].second;
			

				chk[o0_x][o0_y] = 1;
				chk[o1_x][o1_y] = 1;
				chk[o2_x][o2_y] = 1;

				for (int i = 0; i < q.size(); i++) {
					BFS(q[i].first, q[i].second);
					if (infec + 3 == safe_area)
						break;
				}
				if (safe_area - infec - 3 > max_safe)
					max_safe = safe_area - infec - 3;
				infec = 0;
				while (!each.empty()) {
					each.pop();
				}
				// reset added wall
				//chk[o0_x][o0_y] = 0;
				//chk[o1_x][o1_y] = 0;
				//chk[o2_x][o2_y] = 0;

				memset(chk, -1, sizeof(chk));
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= M; j++) {
						chk[i][j] = arr[i][j];
					}
				}

			}
		}
	}
	printf("%d", max_safe);


	return 0;
}
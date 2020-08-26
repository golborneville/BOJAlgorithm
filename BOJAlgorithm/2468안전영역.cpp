#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int maxArea = 0;
int N, arr[103][103];
int chk[103][103]; // 1은 방문, 0은 미방문, -1 은 침수
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
int safeArea(int height) {
	int area_number = 0;
	//setting
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] <= height) {
				chk[i][j] = -1;
			}
			else {
				chk[i][j] = 0;
			}
		}
	}
	//BFS
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (chk[i][j] == 0) {
				area_number++;
				q.push(make_pair(i, j));
				chk[i][j] = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						if (chk[x + dx[k]][y + dy[k]] == 0) {
							chk[x + dx[k]][y + dy[k]] = 1;
							q.push(make_pair(x + dx[k], y + dy[k]));
						}
					}
				}
			}
		}
	}



	return area_number;
}
int main() {
	int max_height = 0;
	memset(arr, 0, sizeof(arr));
	memset(chk, -1, sizeof(chk));
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &arr[i][j]);
			if (max_height < arr[i][j]) {
				max_height = arr[i][j];
			}
		}
	}
	for (int i = 0; i < max_height; i++) {
		int tmp = safeArea(i);
		if (tmp > maxArea) {
			maxArea = tmp;
		}
		memset(chk, -1, sizeof(chk));
	}

	cout << maxArea;

}
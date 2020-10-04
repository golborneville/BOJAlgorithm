#include<iostream>
#include <queue>
#include<cstring>
using namespace std;

int M, N; 
int box[1003][1003];
int chk[1003][1003];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ripe = 0, totalTomato, maxDate = 0; 
queue<pair<int, int>> q;
void BFS() {
	//pair<int, int> xy = q.front();
	//chk[xy.first][xy.second] = 0;
	//q.pop();
	while (!q.empty()) {
		pair<int, int> xy = q.front();	
		q.pop(); 
		ripe++;

		for (int i = 0; i < 4; i++) {
			pair<int, int> newxy = { xy.first + dx[i], xy.second + dy[i] };
			if (!chk[newxy.first][newxy.second] && box[newxy.first][newxy.second] == 0) {
				q.push(newxy);
				chk[newxy.first][newxy.second] = 1 + chk[xy.first][xy.second];
				box[newxy.first][newxy.second] = 1;
				if (chk[newxy.first][newxy.second] > maxDate)
					maxDate = chk[newxy.first][newxy.second];
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(box, -1, sizeof(box));

	cin >> M >> N;
	totalTomato = M *N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i, j });
			}
			if (box[i][j] == -1) {
				totalTomato--;
			}
		}
	}
	BFS();
	if (totalTomato != ripe) {
		cout << -1;
		return 0;
	}
	if (totalTomato == 0) { // 근데 백준에서 이런 케이스는 없다 하드라
		cout << -1;
		return 0;
	}
	cout << maxDate;
	return 0;




}
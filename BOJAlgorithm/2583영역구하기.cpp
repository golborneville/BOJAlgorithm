#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int res = 0;
vector<int> resar;
int M, N, K;
int arr[102][102];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int chk_area(int i, int j) {
	queue<pair<int, int>> qu;
	int sum = 1;
	arr[i][j] = 1;
	res++;
	qu.push({ i,j });
	while (!qu.empty()) {
		pair<int, int> fr = qu.front();
		qu.pop();
		for (int k = 0; k < 4; k++) {
			int nx = fr.first + dx[k]; int ny = fr.second + dy[k];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)continue;
			if (!arr[nx][ny]) {
				qu.push({ nx,ny });
				sum++;
				arr[nx][ny] = 1;
			}
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int lx, ux, ly, uy;
		cin >> lx >> ly >> ux >> uy;
		for (int x = lx; x < ux; x++) {
			for (int y = ly; y < uy; y++) {
				arr[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!arr[i][j]) {
				int areaval = chk_area(i, j);
				resar.push_back(areaval);
			}
		}
	}
	sort(resar.begin(), resar.end());
	cout << res << "\n";
	for (int i = 0; i < resar.size(); i++) {
		cout << resar[i] << " ";
	}
	return 0;
}
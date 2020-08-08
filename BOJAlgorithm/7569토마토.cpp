#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int dx[6] = { 1, -1, 0, 0 ,0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int date=0, cur=0, tom=0; //지난 날짜 카운팅, 현재 익은 토마토 개수, 전체 토마토 개수
int M, N, H, arr[105][105][105];
queue< tuple <int,int,int>> q;
int BFS(int epoch) {
	int pushCnt = 0;
	
	while (epoch--) {
		if (!q.empty()) {
			tuple <int, int, int> tmp = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nearTomato = arr[get<0>(tmp) + dz[i]][get<1>(tmp) + dx[i]][get<2>(tmp) + dy[i]];
				if (nearTomato == 0) {
					cur++;
					pushCnt++;
					q.push(make_tuple(get<0>(tmp) + dz[i], get<1>(tmp) + dx[i], get<2>(tmp) + dy[i]));
					arr[get<0>(tmp) + dz[i]][get<1>(tmp) + dx[i]][get<2>(tmp) + dy[i]] = 1;
				}
			}
		}
	}
	if (pushCnt != 0)
		date++;
	return pushCnt;

}
int main() {
	memset(arr, -1, sizeof(arr));
	scanf_s("%d %d %d", &M, &N, &H);
	for (int h = 1; h <= H; h++) {
		for (int n = 1; n <= N; n++) {
			for (int m = 1; m <= M; m++) {
				scanf_s("%d", &arr[n][m][h]);
				if (arr[n][m][h] != -1) {
					tom++;
					if (arr[n][m][h] == 1) {
						q.push(make_tuple(n, m, h));
						cur++;
					}
				}
			}
		}
	}

	int epoch = cur;
	while (!q.empty()) {
		epoch = BFS(epoch);
	}
	if (cur != tom)
		printf("%d", -1);
	else if (tom == 0)
		printf("%d", -1);
	else
		printf("%d", date);
}
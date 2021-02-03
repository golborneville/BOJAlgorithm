#include<iostream>
#include<vector>
using namespace std;
pair<int, pair<int, int>> city[1003]; // 특별유무 / (x, y)
int disarr[1003][1003];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, T, M;
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		int sp, x, y;
		cin >> sp >> x >> y;
		city[i] = { sp, {x, y} };
	}

	//distance value from I to J
	//initialize & 한번에 직행 및 텔레포트 가능한 애드 ㄹ최솟값으로 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			disarr[i][j] = 987654321;

			if (city[i].first && city[j].first) {
				//both cities are special =  teleport!
				if (disarr[i][j] > T) disarr[i][j] = T;
			}
			//manhatten distance 도 고려 해줘야 함
			int tmpdis = abs(city[i].second.first - city[j].second.first) + abs(city[i].second.second - city[j].second.second);
			if (disarr[i][j] > tmpdis) disarr[i][j] = tmpdis;

		}
	}
	//#######################플로이드 와샬!!!!!!!!!!!!!!!!
	for (int i = 1; i <= N; i++) {	//거쳐가는 노드
		for (int j = 1; j <= N; j++) { // 출발 노드
			for (int k = 1; k <= N; k++) { //도착 노드
				if (disarr[j][i] + disarr[i][k] < disarr[j][k])disarr[j][k] = disarr[j][i] + disarr[i][k];
			}
		}
	}



	cin >> M;
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
	
		cout << disarr[c1][c2] << "\n";
	}
	return 0;
}
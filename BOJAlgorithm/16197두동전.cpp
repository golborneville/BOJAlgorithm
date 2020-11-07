#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int N, M;
char coin[24][24]; //-1 바깥, 0 빈칸, 1벽, 2동전 
queue<pair<pair<int,int>,pair<int,int>>> q; // coin 1 coin 2
int chk[24][24][24][24]; // coin 1 x,y && coin 2 x, y
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool outofboundary(int x, int y) {
	return x < 1 || x > N || y < 1 || y > M;
}
int BFS() {

	while (!q.empty()) {
		pair<int, int> coin1 = q.front().first;
		pair<int, int> coin2 = q.front().second;
		q.pop();
		if (chk[coin1.first][coin1.second][coin2.first][coin2.second] > 10) return -1;
		if (outofboundary(coin1.first, coin1.second) ^ outofboundary(coin2.first, coin2.second)) {
			//only one coin drop
			return chk[coin1.first][coin1.second][coin2.first][coin2.second]; // d여기 기준 마다 다르니까 조심
		}
		for (int j = 0; j < 4; j++) {
			pair<int, int> next1 = { coin1.first + dx[j], coin1.second + dy[j] };
			pair<int, int> next2 = { coin2.first + dx[j], coin2.second + dy[j] };
			
			//둘다 떨어지는 경우
			if (outofboundary(next1.first, next1.second) && outofboundary(next2.first, next2.second)) continue;

			//벽으로 막혀서 못 나아가는 경우
			if (coin[next1.first][next1.second] == '#') {
				next1 = coin1;
			}
			if (coin[next2.first][next2.second] == '#') {
				next2 = coin2;
			}
			if (chk[next1.first][next1.second][next2.first][next2.second] >= 0) continue;
			
			chk[next1.first][next1.second][next2.first][next2.second] = chk[coin1.first][coin1.second][coin2.first][coin2.second] + 1;
			q.push({ next1, next2 });
			
		}
	}
	return -1;
}
int main() {
	//memset(coin, -1, sizeof(coin));
	memset(chk, -1, sizeof(chk));
	cin >> N >> M;
	pair<int, int> coinpos[2];
	int ind = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> coin[i][j];
			if (coin[i][j] == 'o')
			{
				coinpos[ind] = { i,j };
				ind++;
			}
		}
	}

	q.push({ {coinpos[0].first,coinpos[0].second},{ coinpos[1].first,coinpos[1].second } });
	chk[coinpos[0].first][coinpos[0].second][coinpos[1].first][coinpos[1].second] = 0;
	int ans = BFS();
	cout << ans << "\n";
	return 0;
}
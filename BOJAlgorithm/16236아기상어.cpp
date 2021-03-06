#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int sea[23][23];
int chk[23][23];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
struct fish {
	int size;
	int x; 
	int y;
	int dis;
};
struct shark {
	int size;
	int x;
	int y;
	int eaten;
};
bool cmp(const fish &a, const fish &b) {

	if (a.x > b.x) {
		return true;
	}
	else if (a.x == b.x) {
		return a.y > b.y;
	}
	else
		return false;

}

vector<fish> mob;
shark baby;
vector<fish> appl;
void BFS( ) {
	//아기 상어위치 기준으로 가까운 곳에 있는 애들 먼저 먹음
	//baby 가 target까지 이동 + 그 자리에 잇는 물고기 먹는 과정 이 전부 
	//물고기 먹엇을때 레벨업 조건 충족하면 레벨업 시켜주기 (베이비 사이즈)
	queue<pair<int, int>> qu;
	int lval = 987654321;
	chk[baby.x][baby.y] = 0;
	qu.push({ baby.x, baby.y });
	sea[baby.x][baby.y] = 0;
	while (!qu.empty()) {
		pair<int, int> nd = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nd.first + dx[i]; int ny = nd.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (chk[nx][ny] == -1 && sea[nx][ny] >= 0 && sea[nx][ny] <= baby.size) {
				chk[nx][ny] = chk[nd.first][nd.second] + 1;
				qu.push({ nx,ny });

				if (sea[nx][ny] > 0 && sea[nx][ny] < baby.size) {
					if (lval > chk[nx][ny]) lval = chk[nx][ny];
					if (lval == chk[nx][ny]) appl.push_back({ sea[nx][ny], nx,ny, chk[nx][ny] });
					
				}

			}
		}
	}
	//return 0;

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int helpday = 0;


	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> sea[i][j];
			if (sea[i][j] >= 1 && sea[i][j] <= 6) {
				fish tmp = { sea[i][j], i,j, 0 };
				mob.push_back(tmp);
			}
			if (sea[i][j] == 9) baby = { 2, i,j ,0};
		}

	while (mob.size() > 0) {
		//(동일) 최단 거리 내 모든 후보 => appl에 존재
		memset(chk, -1, sizeof(chk));
		BFS();
		if (!appl.size()) break;
		sort(appl.begin(), appl.end(), cmp);
		fish target = appl[appl.size() - 1];
		appl.clear();

		helpday += target.dis;
		sea[target.x][target.y] = 9;
		baby.eaten = baby.eaten + 1;
		if (baby.size == baby.eaten) {
			baby.eaten = 0;
			baby.size = baby.size + 1;
		}
		baby.x = target.x; baby.y = target.y;//상어 위치 업뎃

	}
	cout << helpday;
	return 0;
}
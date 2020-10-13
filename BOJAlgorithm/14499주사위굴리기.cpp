#include<iostream>
using namespace std;
int N, M, x, y, K;
int mapvalue[22][22];
int dx[5] = { 0, 0, 0, -1, 1 }; //index 0 not in use
int dy[5] = { 0, 1, -1, 0, 0 };
pair<int, int> currentstate;
int dice[6]; // 위0, 아래1, 동2, 서3 , 남4, 북5 순서임
void turnDice(int dir) {
	int tmp;
	switch (dir)
	{
	case 1: // 동
		tmp = dice[0]; // 위 값 임시 저장
		dice[0] = dice[3]; // 서->위
		dice[3] = dice[1]; // 아래->서
		dice[1] = dice[2]; // 동->아래
		dice[2] = tmp;	   // 위->동
		break;
	case 2: // 서
		tmp = dice[2]; // 동 값 임시 저장
		dice[2] = dice[1]; // 아래->동
		dice[1] = dice[3]; // 서->아래
		dice[3] = dice[0]; // 위->서
		dice[0] = tmp;	   // 동->위
		break;
	case 3: // 북
		tmp = dice[5]; // 북 값 임시 저장
		dice[5] = dice[0]; // 위->북
		dice[0] = dice[4]; // 남->위
		dice[4] = dice[1]; // 아래->남
		dice[1] = tmp; // 북->아래
		break;
	case 4: //남
		tmp = dice[0]; // 위 값 임시 저장
		dice[0] = dice[5]; // 북->위
		dice[5] = dice[1]; // 아래->북
		dice[1] = dice[4]; // 남->아래
		dice[4] = tmp;	   // 위->남
		break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mapvalue[i][j];
		}
	}
	currentstate = { x, y };
	while (K--) {
		int dir;
		cin >> dir;
		int nx = currentstate.first + dx[dir];
		int ny = currentstate.second + dy[dir];
		if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
		currentstate = { nx, ny };

		turnDice(dir); //dice배열 값만 바뀜

		//바닥 0인지 확인후 처리 
		if (!mapvalue[currentstate.first][currentstate.second]) {
			//floor is 0 
			mapvalue[currentstate.first][currentstate.second] = dice[1];
		}
		else {//floor is NOT 0
			dice[1] = mapvalue[currentstate.first][currentstate.second];
			mapvalue[currentstate.first][currentstate.second] = 0;
		}
		cout << dice[0] << "\n";
	}



}
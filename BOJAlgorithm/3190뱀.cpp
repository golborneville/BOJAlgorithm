#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int headx = 1, heady = 1;
int N, K, L;
int map[103][103];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int time = 0, xyIndex = 0;
queue<pair<int, int>> cmd;
queue<pair<int, char>> snake; //front가 뱀의 꼬리 위치 좌표
int main() {
	memset(map, 0, sizeof(map)); //0이 기본 빈 칸 // 1이 사과 있는 칸 //2가 뱀 있는 칸
	scanf_s("%d %d", &N, &K);
	while (K--) {
		int x, y;
		scanf_s("%d %d", &x, &y);
		map[x][y] = 1;

	}
	scanf_s("%d", &L);
	while (L--) {
		int sec;
		char way;
		scanf_s("%d %c", &sec, &way);
		cmd.push(make_pair(sec, way));
	}
	map[1][1] = 2;
	snake.push(make_pair(1, 1));
	//한칸 이동할 때 마다 게임 끝나느거 확인하기 
	while (!cmd.empty()) {
		pair<int,char> cmd_dis = cmd.front();
		cmd.pop();

		int sec = cmd_dis.first - time;
		char direction = cmd_dis.second;
		while (sec--) {
			time++;
			headx += dx[xyIndex];
			heady += dy[xyIndex];
			//항상 예외처리 해주기 (out of index)
			if ((map[headx][heady] == 2) || (headx > N) || (heady > N) || (headx < 1) || (heady < 1)) {
				printf("%d", time);
				return 0;
			}
			snake.push(make_pair(headx, heady));
			if (map[headx][heady] != 1) {
				map[snake.front().first][snake.front().second] = 0;
				snake.pop();
			}
			map[headx][heady] = 2;


		}
		time++;
		if (direction == 'L')//왼쪽 회전
			xyIndex = (xyIndex + 4 - 1) % 4;
		else if (direction == 'D') //오른쪽 회전
			xyIndex = (xyIndex + 4 + 1) % 4;

		headx += dx[xyIndex];
		heady += dy[xyIndex];
		//항상 예외처리 해주기 (out of index)
		if ((map[headx][heady] == 2) || (headx > N) || (heady > N) || (headx < 1) || (heady < 1)) {
			printf("%d", time);
			return 0;
		}

		snake.push(make_pair(headx, heady));
		if (map[headx][heady] != 1) {
			map[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		map[headx][heady] = 2;

	}
	while (1) {
		time++;
		headx += dx[xyIndex];
		heady += dy[xyIndex];
		//항상 예외처리 해주기 (out of index)
		if ((map[headx][heady] == 2) || (headx > N) || (heady > N) || (headx < 1) || (heady < 1)) {
			printf("%d", time);
			return 0;
		}
		snake.push(make_pair(headx, heady));
		if (map[headx][heady] != 1) {
			map[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		map[headx][heady] = 2;
	}


}
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
queue<pair<int, char>> snake; //front�� ���� ���� ��ġ ��ǥ
int main() {
	memset(map, 0, sizeof(map)); //0�� �⺻ �� ĭ // 1�� ��� �ִ� ĭ //2�� �� �ִ� ĭ
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
	//��ĭ �̵��� �� ���� ���� �������� Ȯ���ϱ� 
	while (!cmd.empty()) {
		pair<int,char> cmd_dis = cmd.front();
		cmd.pop();

		int sec = cmd_dis.first - time;
		char direction = cmd_dis.second;
		while (sec--) {
			time++;
			headx += dx[xyIndex];
			heady += dy[xyIndex];
			//�׻� ����ó�� ���ֱ� (out of index)
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
		if (direction == 'L')//���� ȸ��
			xyIndex = (xyIndex + 4 - 1) % 4;
		else if (direction == 'D') //������ ȸ��
			xyIndex = (xyIndex + 4 + 1) % 4;

		headx += dx[xyIndex];
		heady += dy[xyIndex];
		//�׻� ����ó�� ���ֱ� (out of index)
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
		//�׻� ����ó�� ���ֱ� (out of index)
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
#include<iostream>
#include<cstring>
using namespace std;

int N, M, r, c, d;
int room[53][53]; // 1�� ��, 0�� û�� ���� �� , 2�� û�� �Ѱ�
int cnt = 0;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int main() {
	memset(room, 0, sizeof(room));
	scanf_s("%d %d", &N, &M);
	scanf_s("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &room[i][j]);
		}
	}

	int seed = d;
	while (1) {
		if (room[r][c] == 0) {
			cnt++;
			room[r][c] = 2;
		}
		//õõ�� �����غ���
		int seex = r + dx[seed];
		int seey = c + dy[seed];
		seed = (seed + 4 - 1) % 4;



		int wallscnt = 3;
		while (room[seex][seey] != 0 && wallscnt--) {
			seex = r + dx[seed];
			seey = c + dy[seed];
			seed = (seed + 4 - 1) % 4;
		}
		if (wallscnt < 0) {
			//2.c or 2.d
			int back = (seed + 4 + 1- 2) % 4;
			seex = r + dx[back];
			seey = c + dy[back];

			if (room[seex][seey] != 1) {
				//���� �ƴ� => ����!
				r = seex;
				c = seey;
			}
			else {
				//���� ���� �۵� ���߱�
				printf("%d\n", cnt);
				return 0;
			}
		}
		else {
			r = seex;
			c = seey;
		}
	}

}
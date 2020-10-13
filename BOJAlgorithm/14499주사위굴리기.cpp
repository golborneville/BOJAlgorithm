#include<iostream>
using namespace std;
int N, M, x, y, K;
int mapvalue[22][22];
int dx[5] = { 0, 0, 0, -1, 1 }; //index 0 not in use
int dy[5] = { 0, 1, -1, 0, 0 };
pair<int, int> currentstate;
int dice[6]; // ��0, �Ʒ�1, ��2, ��3 , ��4, ��5 ������
void turnDice(int dir) {
	int tmp;
	switch (dir)
	{
	case 1: // ��
		tmp = dice[0]; // �� �� �ӽ� ����
		dice[0] = dice[3]; // ��->��
		dice[3] = dice[1]; // �Ʒ�->��
		dice[1] = dice[2]; // ��->�Ʒ�
		dice[2] = tmp;	   // ��->��
		break;
	case 2: // ��
		tmp = dice[2]; // �� �� �ӽ� ����
		dice[2] = dice[1]; // �Ʒ�->��
		dice[1] = dice[3]; // ��->�Ʒ�
		dice[3] = dice[0]; // ��->��
		dice[0] = tmp;	   // ��->��
		break;
	case 3: // ��
		tmp = dice[5]; // �� �� �ӽ� ����
		dice[5] = dice[0]; // ��->��
		dice[0] = dice[4]; // ��->��
		dice[4] = dice[1]; // �Ʒ�->��
		dice[1] = tmp; // ��->�Ʒ�
		break;
	case 4: //��
		tmp = dice[0]; // �� �� �ӽ� ����
		dice[0] = dice[5]; // ��->��
		dice[5] = dice[1]; // �Ʒ�->��
		dice[1] = dice[4]; // ��->�Ʒ�
		dice[4] = tmp;	   // ��->��
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

		turnDice(dir); //dice�迭 ���� �ٲ�

		//�ٴ� 0���� Ȯ���� ó�� 
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
//������ ����ϰ� ���� �ֱ� �� ������ �˻� (��Ʈ��ŷ)
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int N;
bool chk[17][17][17]; // �� �ܰ迡 �����ϱ� �� ��δ� . �׷��� ���� ��ų�� ��ġ�� �κ��� �Ȼ����
int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }; //��� ��� �٢� �֢�
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void chkPath(int x, int y, bool tf) { //tf �� true false �Ѱܼ� chk ó�� �� ���� ���� ����
	chk[x][x][y] = tf;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			chk[x][nx][ny] = tf;
			nx = nx + dx[i];
			ny = ny + dy[i];
		}
	}
}
int main() {
	int total = 0;
	memset(chk, false, sizeof(chk));
	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	stack<pair<int, int>> possible;
	for (int i = N-1; i >= 0; i--) {
		possible.push({ 0, i });
	}
	while (!possible.empty()) {
		//1.���� ��� üũ(�Ƹ� top) &  pop 
		pair<int, int> tmp = possible.top();
		possible.pop();
		for (int i = tmp.first; i < N; i++) {
			memset(chk[i], false, sizeof(chk[i]));
		}
		//2. ���� ��忡 ���� chk ����( ���� ��� �湮 true�� ����)
		chkPath(tmp.first, tmp.second, true);

		//3. �� ���� �� (i+1) �� ���� ��� ������ ��ǥ �� chk false�� �ֵ鸸 ��� ���ÿ� ����(������ �˻�)
		int cnt_map = 0;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j <= tmp.first; j++) {
				if (chk[j][tmp.first + 1][i] == false) { //���� �ܰԵ鵵 Ȯ���� ����� ���� �´�
					cnt_map++;
				}
			}
			if (cnt_map == tmp.first + 1) {
				possible.push({ tmp.first + 1 , i });
			}
			cnt_map = 0;
		}
		if (possible.empty()) {
			cout << total;
			return 0;
		}
		while (possible.top().first == N - 1) { //������ ���ܤƴ� ��� üũ ���ϰ� �ٷ� ��
			total++;
			//chkPath()
			possible.pop();
			if (possible.empty()) {
				cout << total;
				return 0;
			}
		}
		// �ش� tmp.first��쿡 �ϳ��� Ǫ�� �Ǵ°� ������..?
		// �ƴϸ� ���� ������ �ܰ� ����� �����ؼ� �ٸ� ����� �� üũ �ؾ���
		//if (tmp.first + 1 !=  possible.top().first) {
			//�̹� �ܰ迡�� Ǫ�� �� �ֵ��� �ϳ��� ����
			//chkpath �� ���� �� �ʱ�ȭ
		//	chkPath(tmp.first, tmp.second, false);
		//}
		
	}

	cout << total;
	return 0;
}
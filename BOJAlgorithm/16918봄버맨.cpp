#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define bomb 'O'
#define blank '.'
int R, C, N;
char box[203][203];
int countb[203][203];
int timecnt = 1;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void explode() {
	while(!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		countb[i][j] = 0;
		box[i][j] = blank;
		for (int k = 0; k < 4; k++) {
			if (box[i + dx[k]][j + dy[k]] != 'n') {
			box[i + dx[k]][j + dy[k]] = blank;
			countb[i + dx[k]][j + dy[k]] = 0;
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(countb, 0, sizeof(countb));
	memset(box, 'n', sizeof(box));

	cin >> R >> C >> N;

	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> box[i][j];
			if (box[i][j] == bomb) {
				countb[i][j] = timecnt; //2�ܰ� ���� �Ϸ� //timecnt == 1
			}
		}
	}
	while (timecnt != N) {
		timecnt++;
		//�� �ð� ���� ��=>  ���ǿ� �´� ���� => ??
		if (timecnt % 2 == 0) { //������ ������ �߰� ��ġ(�ٵ� 0���� �ʱ�ȭ�� �� 
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					if (box[i][j] == bomb) { //���� ��ź �ð� ����
						countb[i][j]++;
					}
					else if (box[i][j] == blank) { //�� ��ź ��ġ
						box[i][j] = bomb;
					}
				}
			}
		}
		else {
			//����
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
						if (countb[i][j] == 2 && box[i][j] == bomb) {
							//�ش� �ܰ迡�� ++ �Ǿ 3�ʰ��� -> ����
							//���� ��Ű��-> �� �ܰԿ��� box[i][j]�� �޶��������� 
							q.push({i,j});

						}
						else if(countb[i][j] < 2 && box[i][j] == bomb) {
							//not yet explode & nly increase time
							countb[i][j]++;
						}
				}
			}
			explode();
		}

	}


	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout <<  box[i][j];
		}
		cout << "\n";
	}


}

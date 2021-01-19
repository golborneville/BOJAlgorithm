#include<iostream>
#include<cstring>
using namespace std;

int N, M;
int pan[23][23];
bool chk[23][23];
int res = 0;
int cnt = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool cont = true;
void searchter(int x, int y) {
	if (!cont) return;

	chk[x][y] = true;
	cnt++;
	for (int k = 0; k < 4; k++) {
		if (x + dx[k] < 0 || y + dy[k] < 0 || x + dx[k] >= N || y + dy[k] >= M) continue;
		if (pan[x + dx[k]][y + dy[k]] == 0) {
			cont = false;
			chk[x + dx[k]][y + dy[k]] = false;
			cnt = 0;
			return;
		}
		else if (pan[x + dx[k]][y + dy[k]] == 2 && !chk[x + dx[k]][y + dy[k]]) {
			searchter(x + dx[k], y + dy[k]); //DFS  �ѹ��̶� 0�� �����ϸ� �����ΰ���;
			//chk[x + dx[k]][y + dy[k]] = false;
			if (!cont) {
				chk[x + dx[k]][y + dy[k]] = false;
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> pan[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//pair<int, int> pos1;
		    //.�ٵ�1 ��ġ ���� = {i,j}
			if (pan[i][j] != 0) continue;
			pan[i][j] = 1;
			for (int i2 = i; i2 < N; i2++) {
				for (int j2 = 0; j2 < M; j2++) {
					//.�ٵ�2 ��ġ ���� = {i2,j2}
					//pair<int, int> pos2;

					int tmp = 0;
					if (pan[i2][j2] != 0) continue;

					//�ٵϵα�
					
					pan[i2][j2] = 1;

					//Ž�� ( ��� ��������...)
					//�ٵ� �а� �������� �ֺ� Ž�� -> �������� �ѷ����ΰ� X ����
					for (int k = 0; k < 4; k++) {
						if (i + dx[k] < 0 || j + dy[k] < 0 || i + dx[k] >= N || j + dy[k] >= M) continue;
						if (pan[i + dx[k]][j + dy[k]] == 2 && !chk[i + dx[k]][j + dy[k]]) {
							searchter(i + dx[k], j + dy[k]); //DFS  �ѹ��̶� 0�� �����ϸ� �����ΰ���;
							//if (res < cnt) res = cnt;
							tmp += cnt;
							cnt = 0;
							cont = true;
						}
					}
					for (int k = 0; k < 4; k++) {
						if (i2+ dx[k] < 0 || j2 + dy[k] < 0 || i2 + dx[k] >= N || j2 + dy[k] >= M) continue;
						if (pan[i2 + dx[k]][j2 + dy[k]] == 2 && !chk[i2 + dx[k]][j2 + dy[k]]) {
							searchter(i2 + dx[k], j2 + dy[k]); //DFS  �ѹ��̶� 0�� �����ϸ� �����ΰ���;
		
							tmp += cnt;
							cnt = 0;
							cont = true;
						}
					}
					if (res < tmp) res = tmp;

					//recover
					
					pan[i2][j2] = 0;
					memset(chk, false, sizeof(chk));
				}
			}
			pan[i][j] = 0;
		}
	}
	cout << res;
	return 0;
}
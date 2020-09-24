//스택을 사용하고 스택 넣기 전 유망성 검사 (백트래킹)
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int N;
bool chk[17][17][17]; // 각 단계에 저장하기 각 경로는 . 그래야 복구 시킬때 겹치는 부분이 안사라짐
int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }; //↓↑ →← ↘↙ ↗↖
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void chkPath(int x, int y, bool tf) { //tf 에 true false 넘겨서 chk 처리 랑 복구 동시 구현
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
		//1.기준 노드 체크(아마 top) &  pop 
		pair<int, int> tmp = possible.top();
		possible.pop();
		for (int i = tmp.first; i < N; i++) {
			memset(chk[i], false, sizeof(chk[i]));
		}
		//2. 기준 노드에 대해 chk 변경( 가능 경로 방문 true로 수정)
		chkPath(tmp.first, tmp.second, true);

		//3. 그 다음 행 (i+1) 에 대해 모든 가능한 좌표 중 chk false인 애들만 노드 스택에 삽입(유망성 검사)
		int cnt_map = 0;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j <= tmp.first; j++) {
				if (chk[j][tmp.first + 1][i] == false) { //이전 단게들도 확ㅇ니 해줘야 하지 맞다
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
		while (possible.top().first == N - 1) { //마지막 ㄷ단ㅖ는 경로 체크 안하고 바로 팝
			total++;
			//chkPath()
			possible.pop();
			if (possible.empty()) {
				cout << total;
				return 0;
			}
		}
		// 해당 tmp.first경우에 하나도 푸시 되는게 없으면..?
		// 아니면 이제 마지막 단계 제대로 수행해서 다른 경우의 수 체크 해야함
		//if (tmp.first + 1 !=  possible.top().first) {
			//이번 단계에서 푸시 된 애들이 하나도 업ㅠ
			//chkpath 만 복구 및 초기화
		//	chkPath(tmp.first, tmp.second, false);
		//}
		
	}

	cout << total;
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#define JI 1
#define GH 2
#define MH 3

using namespace std;
//경기 순서 : 지우 - 경희 - 민호
//지우가 이길수 있는가?

int N, K;//손동작 수, 우승 위한 최종 승수
int relation[11][11];
int turn[4][22];
int indexcnt[4];
int wincnt[4];
bool result = false;
bool keep = true;
void playgame(int p1, int p2) { //player1 player2
	//종료조건
	//????
	if (indexcnt[1] > N) keep = false;
	if (wincnt[GH] >= K || wincnt[MH] >= K) keep = false;
	if (wincnt[JI] >= K) {
		result = true;
		keep = false;
	}
	if (!keep) return;

	if (p1 > p2) swap(p1, p2); // p1이 더 작도록 항상 조심

	//순서 증가 
	indexcnt[p1]++;
	indexcnt[p2]++;
	//****p1기준****
	if (relation[turn[p1][indexcnt[p1]]][turn[p2][indexcnt[p2]]] == 2) {
		//win(p1)
		//1.이긴사람 카운트 증가
		wincnt[p1]++;
		//2. 다음 게임 차례 지정
		int nextp = 6 - (p1 + p2);//참가X

		//3. 호출
		keep = true;
		playgame(p1, nextp);
		//돌아왔을때 복구
		wincnt[p1]--;
		indexcnt[p1]--;
		indexcnt[p2]--;
	}
	else {
		//lose(p1) & draw
		//1.이긴사람 카운트 증가
		wincnt[p2]++;
		//2. 다음 게임 차례 지정
		int nextp = 6 - (p1 + p2);//참가X
		//3. 호출
		keep = true;
		playgame(p2, nextp);
		//돌아왔을때 복구
		wincnt[p2]--;
		indexcnt[p1]--;
		indexcnt[p2]--;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> relation[i][j]; //상성
	for (int i = 2; i <= 3; i++) for(int j=1; j<=20;j++) cin >> turn[i][j]; //내는 순서
	for (int i = 1; i <= N; i++) turn[1][i] = i; //지우 손동장 차례 1~N

	do {
		if (N < K) {
			cout << 0; 
			return 0;
		}

		playgame(JI, GH);
		if (result)break;
		keep = true;
		memset(wincnt, 0, sizeof(wincnt));
		memset(indexcnt, 0, sizeof(indexcnt));
		
	} while (next_permutation(turn[1] + 1, turn[1] + N + 1));
	if (result) cout << 1;
	else cout << 0;
	return 0;
}


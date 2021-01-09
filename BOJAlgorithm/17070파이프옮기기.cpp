#include<iostream>
#include<stack>
//bool chk[20][20];
using namespace std;
int home[20][20];
int total = 0;
int N;
pair<int,int> pipe[2];//start, end psir(x,y)
void nextPipe(int state, pair<int,int> pos) { //DFS implement
	//pos는 도착점 기준
	//state값에 따라 움직일수 있는 경우가 각자 다름
	int x = pos.first;
	int y = pos.second;

	if (x == N && y == N) {
		total++;
		return;
	}
	//chk[x][y] = true;
	//각 스테이트에서 이동하는 모든 각 경우에 대해 칸이 비어있는지**
	//이미 방문한 경로가 아닌지?-> 계속 앞으로 나아가는 제한된 조건이라 굳이  필요X

	//state 0 가로
	if (state == 0) {
		//1) 가로 

		if (!home[x][y + 1]&&(N >= x && N >= y + 1)) { //비어있어야 접은가능
			nextPipe(0, { x , y + 1 });
		}
		//2) 대각선
		if (!(home[x + 1][y + 1]|| home[x + 1][y] || home[x][y+1]) && (N >= x + 1 && N >= y + 1)) {
			nextPipe(2, { x + 1, y+1 });	
		}
	}
	//state 1 세로
	else if (state == 1) {
		//1)세로
		if (!home[x+1][y] && (N >= x + 1 && N >= y)) { //비어있어야 접은가능
			nextPipe(1, { x + 1, y});
		}
		//2) 대각선
		if (!(home[x + 1][y + 1] || home[x + 1][y] || home[x][y + 1]) && (N >= x + 1 && N >= y + 1)) {
			nextPipe(2, { x + 1, y + 1 });
		}
	}
	//state 2 대각선
	else if (state == 2) {
		//1) 가로 
		if (!home[x][y + 1] && (N >= x && N >= y + 1)) { //비어있어야 접은가능
			nextPipe(0, { x , y + 1 });
		}
		//2)세로
		if (!home[x + 1][y] && (N >= x + 1 && N >= y)) { //비어있어야 접은가능
			nextPipe(1, { x + 1, y });
		}
		//3)대각선
		if (!(home[x + 1][y + 1] || home[x + 1][y] || home[x][y + 1]) && (N >= x + 1 && N >= y + 1)) {
			nextPipe(2, { x + 1, y + 1 });
		}
	}
	
	


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int pipeState = 0; //0 가로, 1 세로, 2 대각선
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> home[i][j];
		}
	}
	//chk[1][1] = true;
	//chk[1][2] = true;
	//pipe[0] = { 1,1 };
	//pipe[1] = { 1,2 };
	nextPipe(0, { 1,2 });
	cout << total;
	return 0;
}
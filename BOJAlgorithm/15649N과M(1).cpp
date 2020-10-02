#include<iostream> //재귀로 푸는 순열
using namespace std;

bool chk[10];
int arr[10];
int M, N;
void recur(int m, int depth) { // 베이스는DFS임 //애초에 m은 쓰이지 않는 매개 변수임
	if (depth == M) { //m번째 층가지 깊이 들어간 경우 
		for (int i= 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	//좀 더 한 단계씩 깊이 들어가야 하는 경우
	for (int i = 1; i <= N; i++) {
		if (chk[i])continue;
		chk[i] = true;
		arr[depth] = i;
		recur(i, depth + 1);
		chk[i] = false;

	}




}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> M; // nPm
	recur(0,0); 

}
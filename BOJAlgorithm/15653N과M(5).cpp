#include<iostream> //재귀로 푸는 순열 + 숫자가 1~N이 아님**
#include<algorithm>
using namespace std;

bool chk[10];
int arr[10];
int ans[10];
int M, N;

void recur(int depth) { // 베이스는DFS임
	if (depth == M) { //m번째 층가지 깊이 들어간 경우 
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	//좀 더 한 단계씩 깊이 들어가야 하는 경우
	for (int i = 0; i < N; i++) {
		if (chk[i])continue;
		chk[i] = true;
		ans[depth] = arr[i];
		recur(depth + 1); //3 -> 3 중복 조합**이라서 다음단계를 i+1이 아니라
		//i 단계에서 싲가해줘야 함 i= m 이 맞고 ***
		chk[i] = false;

	}




}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M; // nPm
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); //오름차순
	recur(0);

}
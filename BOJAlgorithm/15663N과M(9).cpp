#include<iostream> //재귀로 푸는 순열
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

bool chk[10];
int arr[10];
int M, N;
vector<int> vec;
set<vector<int>> S;
void recur(int depth) { // 베이스는DFS임 //애초에 m은 쓰이지 않는 매개 변수임
	if (depth == M) { //m번째 층가지 깊이 들어간 경우 
		S.insert(vec);
		return;
	}
	//좀 더 한 단계씩 깊이 들어가야 하는 경우
	for (int i = 0; i < N; i++) {
		if (chk[i])continue;
		chk[i] = true;
		vec.push_back(arr[i]);
		//arr[depth] = i;
		recur(depth + 1);
		vec.pop_back();
		chk[i] = false;

	}




}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> M; // nPm
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); //오름차순
	recur(0);

	for (auto iter = S.begin(); iter != S.end(); iter++) {
		for (size_t i = 0; i < iter->size(); i++)
		{
			cout << iter->at(i) << " ";
		}
		cout << '\n';
	}

}
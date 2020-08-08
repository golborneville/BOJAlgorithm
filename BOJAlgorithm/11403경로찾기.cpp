#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int N;
vector<int> arr[105];
int result[105][105];
bool chk[105];
void BFS(int x) {
	queue<int> q;
	q.push(x);
	//chk[x] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < arr[front].size(); i++) {
			if (!chk[arr[front][i]]) {
				q.push(arr[front][i]);
				chk[arr[front][i]] = true;
				result[x][arr[front][i]] = 1;
			}
		}
	}

}
int main() {
	memset(arr, 0, sizeof(arr));
	memset(result, 0, sizeof(result));
	//memset(chk, 0, sizeof(chk));

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val;
			scanf_s("%d", &val);
			if (val == 1) {
				arr[i].push_back(j);
				//arr[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		
			memset(chk, 0, sizeof(chk));
			BFS(i);

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}




}
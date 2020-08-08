#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int T, N, cnt =0;
int com[1003] = { 0 };
bool chk[1003];
vector<int> cycle[1003];
/*void bfs(int st) {
	queue<int> bf;
	cnt++;
	bf.push(cycle[st][0]);
	chk[st] = true;
	while (!bf.empty()) {
		int node = bf.front();
		bf.pop();
		if (!chk[node]) {
			chk[node] = true;
			bf.push(cycle[node][0]);
		}
	}
}*/
void dfs(int start) {
	chk[start] = true;
	for (int j = 0; j < cycle[start].size(); j++) {
		int node = cycle[start][j];
		if (!chk[node]) {
			dfs(node);
		}
	}

}
int main() {
	scanf_s("%d", &T);
	while (T--) {
		memset(chk, false, sizeof(chk));
		memset(cycle, 0, sizeof(cycle));
		scanf_s("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf_s("%d", &com[i]);
			cycle[i].push_back(com[i]);
			cycle[com[i]].push_back(i);
		}
		for (int i = 1; i <= N; i++) {
			if (!chk[i]) {
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
		cnt = 0;

	}

}
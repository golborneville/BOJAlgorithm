#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;


bool chk[1005];
vector<int> grh[1005];
queue<int> bfsq;
int N, M, V;
void BFS(int start) {
	bfsq.push(start);
	chk[start]=true;
	while (!bfsq.empty()) {
		int front = bfsq.front();
		cout << front << " ";
		bfsq.pop();
		for (int i = 0; i < grh[front].size(); i++) {
			if (!chk[grh[front][i]]) {
				bfsq.push(grh[front][i]);
				chk[grh[front][i]] = true;
				
			}
		}
	}

}
void DFS(int node) {
	chk[node] = true;
	cout << node << " ";
	for (int i = 0; i < grh[node].size(); i++) {
		if (!chk[grh[node][i]]) {
			DFS(grh[node][i]);
		}
	}
}
int main() {
	memset(grh, 0, sizeof(grh));
	memset(chk, false, sizeof(chk));


	cin >> N >> M >> V;
	while (M--) {
		int v1, v2;
		cin >> v1 >> v2;
		grh[v1].push_back(v2);
		grh[v2].push_back(v1);
		sort(grh[v1].begin(), grh[v1].end());
		sort(grh[v2].begin(), grh[v2].end());
	}
	DFS(V);
	cout << "\n";
	memset(chk, false, sizeof(chk));
	BFS(V);

	return 0;
}
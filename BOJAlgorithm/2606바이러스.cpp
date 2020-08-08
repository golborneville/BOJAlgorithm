#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int C, V, cnt = 0;
queue<int> bfsQue;
vector<int> computer[105];
bool chk[105];
void BFS(int start) {
	bfsQue.push(start);
	chk[start] = true;
	while (!bfsQue.empty()) {
		int node = bfsQue.front();
		//cout << node << " ";
		bfsQue.pop();
		for (int i = 0; i < computer[node].size(); i++) {
			if (!chk[computer[node][i]]) {
				bfsQue.push(computer[node][i]);
				chk[computer[node][i]] = true;
				cnt++;
			}
		}
	}
}
int main() {
	memset(computer, 0, sizeof(computer));
	memset(chk, false, sizeof(chk));
	cin >> C >> V;
	while (V--) {
		int c1, c2;
		scanf_s("%d %d", &c1, &c2);
		computer[c1].push_back(c2);
		computer[c2].push_back(c1);
	}
	BFS(1);
	cout << cnt;



	return 0;
}
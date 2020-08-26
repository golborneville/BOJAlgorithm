#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

vector<int> family[103];
queue<int> q;
bool chk[103];
bool visit = false;
int weight[103];
int n, p1, p2, m, x, y, CNT = 0;
void BFS() {
	chk[p1] = true;
	q.push(p1);
	
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		bool flag = false;
		for (int j = 0; j < family[node].size(); j++) {
			int tmp = family[node][j];
			if (!chk[tmp]) {
				chk[tmp] = true;
				q.push(tmp);
				flag = true;
				weight[tmp] = weight[node] + 1;
			}
		}

		if (chk[p2]) {
			visit = true;
			return;
		}

	}
}
int main() {
	memset(family, 0, sizeof(family));
	memset(chk, false, sizeof(chk));
	memset(weight, 0, sizeof(weight));
	scanf_s("%d %d %d %d", &n, &p1, &p2, &m);
	weight[p1] = 0;
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &x, &y);
		family[x].push_back(y);
		family[y].push_back(x);
	}
	BFS();
	if (visit)
		printf("%d", weight[p2]);
	else
		printf("-1");
	return 0;
}
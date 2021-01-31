#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;


vector<int> bin[20003];
bool chk[20003];
int colornode[20003]; //0 red  && 1 black
int V, E;
queue<int> qu;

bool searchBin(int start) {
	if (!chk[start]) {
		chk[start] = true;
		qu.push(start);
	}
	//colornode[start] = 0;
	while (!qu.empty()) {
		int node = qu.front();
		qu.pop();

		for (int i = 0; i < bin[node].size(); i++) {
			int next = bin[node][i];
			if (colornode[next] == colornode[node]) return false;
			if (!chk[next]) {
				qu.push(next);
				chk[next] = true;
				//colornode[next] = (colornode[node] + 1) % 2;//0->1 , 1->0
			}
		}
	}
	return true;
}
void colorbfs(int start) {
	if (chk[start])	return;
	chk[start] = true;
	qu.push(start);
	colornode[start] = 0;
	while (!qu.empty()) {
		int node = qu.front();
		qu.pop();

		for (int i = 0; i < bin[node].size(); i++) {
			int next = bin[node][i];
			if (!chk[next]) {
				qu.push(next);
				chk[next] = true;
				colornode[next] = (colornode[node] + 1) % 2;//0->1 , 1->0
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	
	cin >> T;
	while (T--) {
		//초기화
		memset(chk, false, sizeof(chk));
		memset(colornode, -1, sizeof(colornode));
		
		cin >> V >> E;
		//그래프 구현
		for (int i = 0; i < E; i++) {
			int src, dst;
			cin >> src >> dst;
			bin[src].push_back(dst);
			bin[dst].push_back(src);
		}
		//색칠
		for (int i = 1; i <= V; i++) {
			colorbfs(i);
		}
		//탐색
		memset(chk, false, sizeof(chk));
		bool res = true;
		for (int i = 1; i <= V; i++) {

			if (!searchBin(i)) {
				res = false;
			}
		}
		if(res)	cout << "YES\n";
		else cout << "NO\n";
		while (!qu.empty()) {
			qu.pop();
		}
		for (int i = 1; i <= V; i++) {
			bin[i].clear();
		}
	}

}
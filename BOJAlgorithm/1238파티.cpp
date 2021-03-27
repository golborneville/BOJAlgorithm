#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

int N, M, X;
int dis[1003][1003];
//int dis_node[1003];
bool chk[1003];
#define INF 987654321

struct cmp {
	bool operator()(pair<int, int> t, pair<int, int> u) {
		return t.second > u.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> dijk; // node, (shortest)distance

void Dijkstra(int src)
{
	for (int i = 1; i <= N; i++)
	{
		dijk.push({ i, dis[src][i] });
	}
	while (!dijk.empty()) {
		pair<int, int> nxt = dijk.top();
		dijk.pop();
		if (nxt.second <= dis[src][nxt.first]) {
			for (int i = 1; i <= N; i++)
			{
				if (dis[src][i] > dis[src][nxt.first] + dis[nxt.first][i])
				{
					dijk.push({ i,dis[src][nxt.first] + dis[nxt.first][i] });
					dis[src][i] = dis[src][nxt.first] + dis[nxt.first][i];
				}
			}
		}
	}
}
int main() {
	int res = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> X; 
	chk[X] = true;
	for (int i = 1; i <= N; i++) 
	{	
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			dis[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) 
	{
		int s, d, v;
		cin >> s >> d >> v;
		dis[s][d] = v;
	}
	//end of input

	
	for (int i = 1; i <= N; i++)
	{
		Dijkstra(i);
	}
	for (int i = 1; i <= N; i++)
	{
		if (res < dis[X][i] + dis[i][X]) res = dis[X][i] + dis[i][X];
	}
	cout << res;
	return 0;

}
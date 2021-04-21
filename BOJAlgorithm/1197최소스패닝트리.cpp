//Kruskal - union-find implement
#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
int leader[10002];
struct edge {
	int weight,src, dst;
};
struct cmp {
	bool operator()(const struct edge a, const struct edge b)
	{
		return a.weight > b.weight; //cmp 는 true 일때 교환 행함 
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E;
	int wval = 0;
	priority_queue<edge, vector<edge>, cmp> pq;
	
	
	cin >> V >> E;
	for (int i = 1; i <= V; i++)
		leader[i] =i;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge inp = { c, a,b };
		pq.push(inp);
	}

	while (!pq.empty())
	{
		edge tmp = pq.top();
		pq.pop();
		if (leader[tmp.src] == leader[tmp.dst])continue;
		int l1 = leader[tmp.src]; int l2 = leader[tmp.dst];
		int nl = leader[tmp.src] < leader[tmp.dst] ? leader[tmp.src] : leader[tmp.dst];
		for (int i = 1; i <= V; i++)
			if (leader[i] == l1 || leader[i] == l2)
				leader[i] = nl;
		wval += tmp.weight;
	}
	cout << wval;
	return 0;
}

//prim algorithm -> 백준 제출시 메모리 초과 뜸 ^^..
/*#include<iostream>
#include<vector>
using namespace std;

int selected[10002]; //이미 선택된 정점 정보
int mindis[10002]; //정점까지 최소 거리 정보
int wt[10002][10002];
#define INF 987654321

int V, E;
int get_min_v()
{
	int v;
	for (int i = 1; i <= V; i++)
	{
		if (!selected[i])
		{
			v = i;
			break;
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (!selected[i] && mindis[i] < mindis[v])
		{
			v = i;
		}
	}
	return v;
}
void Prim(int s) // s is start
{
	for (int i = 1; i <= V; i++)
		mindis[i] = INF;
	mindis[s] = 0;

	for (int i = 1; i <= V; i++)
	{
		int u = get_min_v();
		selected[u] = 1;

		if (mindis[u] == INF) continue;
		for (int i = 1; i <= V; i++)
		{
			if (wt[u][i] != INF)
			{
				if (!selected[i] && wt[u][i] < mindis[i])
					mindis[i] = wt[u][i];
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int wval = 0;

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		wt[a][b] = c;
		wt[b][a] = c;
	}
	Prim(1);
	for (int i = 1; i <= V; i++)
	{
		wval += mindis[i];
	}


	cout << wval;
	return 0;
}*/
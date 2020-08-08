#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define INF 987654321
struct city {
	//int number;
	int next;
	int weight;
};
int N, M, dis[1005], start, destination;
vector<city> arr[1005];

void dijk(int start) {
	priority_queue<pair<int, int>> set; // 기본적으로 내림 차순인데 오름 차순 형태로 구현 하고 싶어서
	//근데 타입형이 페어라서 구현 복잡해서 마이너스 곱하기
	set.push(make_pair(0, start)); //distance, current node
	while (!set.empty()) {
		int front = set.top().second;
		set.pop();
		for (int i = 0; i < arr[front].size(); i++) {
			int cur = dis[arr[front][i].next];
			int newweight = dis[front] + arr[front][i].weight;
			if (cur > newweight) {
				dis[arr[front][i].next] = newweight;
				set.push(make_pair(-1*newweight, arr[front][i].next));
			}
		}
	}


}
int main() {
	scanf_s("%d %d", &N, &M);
	//memset(dis, 0, sizeof(dis));
	memset(arr, 0, sizeof(arr));
	while (M--) {

		int cityNum,next, weight;
		scanf_s("%d %d %d", &cityNum, &next, &weight);
		arr[cityNum].push_back(city{ next , weight });
	}
	scanf_s("%d %d", &start, &destination);

	for (int i = 1; i <= N; i++) {
		dis[i] = INF;
	}
	dis[start] = 0;
	dijk(start);
	printf("%d", dis[destination]);
}
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
//Kruskal 

int N, M; // school num, road num
struct univ {
	//int leader; //init = itself(src)
	int src;
	int dest;
	int distance;
};
struct cmp {
	bool operator()(const univ& t, const univ& u) {
		return t.distance > u.distance;
	}
};

priority_queue<univ, vector<univ>, cmp> city; 
int leader[1002]; //i��° ������ �׷��� ���� �� ������ ����
char gender[1003];
int main() {

	unsigned int len = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		cin >> gender[i]; // why is this even needed?

	for (int i = 0; i < M; i++) {
		int src, dst, dis;
		cin >> src >> dst >> dis; //relationship
		city.push({ src, dst, dis }); 
	}
	for (int i = 1; i <= N; i++) {
		leader[i] = i;
	}

	while (!city.empty()) {
		univ tmp = city.top();
		city.pop();
		
		//0. �� - �� ���� �켱 üũ
		if (gender[tmp.src] == gender[tmp.dest]) continue;

		//1. ���� ������ ���ϴ��� üũ(����Ŭ ���� üũ)
		//.1-2) ���� ���� -> ť���� �����ְ� ��������
		if (leader[tmp.src] == leader[tmp.dest]) continue;
		
		// 1-3) �ٸ� ���� -> �� ���� ���� ������ �������ְ� �θ� ��������
		int nl = leader[tmp.src] < leader[tmp.dest] ? leader[tmp.src] : leader[tmp.dest];
		int l1 = leader[tmp.src];
		int l2 = leader[tmp.dest];

		for (int i = 1; i <= N; i++) {
			if (leader[i] == l1 || leader[i] == l2) {
				leader[i] = nl;
			}
		} 

	//	leader[tmp.src] = nl;
	//	leader[tmp.dest] = nl;
		len += tmp.distance;

	}

	bool flag = false;
	for (int i = 1; i < N; i++) {
		if (leader[i] != leader[i + 1]) flag = true;
	}
	if (flag) cout << -1;
	else cout << len;
	return 0;

}
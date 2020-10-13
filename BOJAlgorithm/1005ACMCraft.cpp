#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, K, W;
queue<int> pa; // indegree is 0 
int building[1003]; //각 빌딩당 건설하는데 걸리는 시간
int result[1003];
int inde[1003]; //indegree 개수
//vector<int> order;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		vector<int> buildre[1003]; //빌딩간 그래프 관계
		memset(buildre, 0, sizeof(buildre));

		//1. 문제 위한 입력 받기
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> building[i];
		}
		for (int i = 1; i <= K; i++) {
			int tmp1, tmp2;
			cin >> tmp1>> tmp2;
			buildre[tmp1].push_back(tmp2); // graph
			inde[tmp2]++;
		}
		cin >> W; //건설해야하는 건물 번호

		//2. 위상정렬 구현하기 
		for (int i = 1; i <= N; i++) {
			if (inde[i] == 0) {
				pa.push(i);
				result[i] = building[i];
			}
		}

		while (!pa.empty()) {
			int node = pa.front(); pa.pop(); //요 시점에서 0이 될때가 같은 시간대 (단계 ) 애들 수행할때임
			
			//order.push_back(node);
			for (int j = 0; j < buildre[node].size(); j++) {
				//여기 RESULT업데이트가 핵!!!!!!!!!!!!심!!!!!!!!!!
				result[buildre[node][j]] = max(result[buildre[node][j]], result[node] + building[buildre[node][j]]);
				if (!--inde[buildre[node][j]]) {
					pa.push(buildre[node][j]); //indegree is 0
				}
			}
		}
			
		//3. 최소시간 업데이트해주기
		cout << result[W] << "\n";
		//4. 다 쓴 애들 초기화 해주기
		memset(inde, 0, sizeof(inde));
		memset(building, 0, sizeof(building));
		memset(result, 0, sizeof(result));

	}
}

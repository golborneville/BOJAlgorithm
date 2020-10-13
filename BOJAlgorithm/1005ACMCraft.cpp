#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, K, W;
queue<int> pa; // indegree is 0 
int building[1003]; //�� ������ �Ǽ��ϴµ� �ɸ��� �ð�
int result[1003];
int inde[1003]; //indegree ����
//vector<int> order;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		vector<int> buildre[1003]; //������ �׷��� ����
		memset(buildre, 0, sizeof(buildre));

		//1. ���� ���� �Է� �ޱ�
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
		cin >> W; //�Ǽ��ؾ��ϴ� �ǹ� ��ȣ

		//2. �������� �����ϱ� 
		for (int i = 1; i <= N; i++) {
			if (inde[i] == 0) {
				pa.push(i);
				result[i] = building[i];
			}
		}

		while (!pa.empty()) {
			int node = pa.front(); pa.pop(); //�� �������� 0�� �ɶ��� ���� �ð��� (�ܰ� ) �ֵ� �����Ҷ���
			
			//order.push_back(node);
			for (int j = 0; j < buildre[node].size(); j++) {
				//���� RESULT������Ʈ�� ��!!!!!!!!!!!!��!!!!!!!!!!
				result[buildre[node][j]] = max(result[buildre[node][j]], result[node] + building[buildre[node][j]]);
				if (!--inde[buildre[node][j]]) {
					pa.push(buildre[node][j]); //indegree is 0
				}
			}
		}
			
		//3. �ּҽð� ������Ʈ���ֱ�
		cout << result[W] << "\n";
		//4. �� �� �ֵ� �ʱ�ȭ ���ֱ�
		memset(inde, 0, sizeof(inde));
		memset(building, 0, sizeof(building));
		memset(result, 0, sizeof(result));

	}
}

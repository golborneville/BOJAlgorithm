#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
vector<int> height[32002];
int cntWe[32002] = { 0 }; //���� ����
queue<int> line; //ť
queue<int> sorted; //��������
int A, B;
int main() {
	memset(height, 0, sizeof(height));
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &A, &B);
		height[A].push_back(B); //���⼺ �׷���
		cntWe[B]++;
	}
	for (int i = 1; i <= N; i++) {
		if (cntWe[i] == 0) {
			line.push(i);
		}
	}
	while (!line.empty()) {
		int node = line.front();
		line.pop();
		sorted.push(node);
		for (int i = 0; i < height[node].size(); i++) {
			int ind = height[node][i];

			cntWe[ind]--;
			if (cntWe[ind] == 0) {
				line.push(ind);
			}
			height[node][i] = 0;
		}
	}
	while (!sorted.empty()) {
		printf("%d ",sorted.front());
		sorted.pop();
	}
}
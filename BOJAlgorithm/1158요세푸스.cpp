#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int circle[5003];
int N, K, cnt = 0, current = 0;


/*
1   4 5  7 
3 
6
9->2

*/



int main() {

	queue<int> ans;
	memset(circle, 0, sizeof(circle));
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		//1~N
		circle[i] = i;
	}
	while (1) {
		for (int i = 0; i < K; i++) {
			current++;
			if (current > N) {
				current = 1;
			}
			while (circle[current] == 0) {
				current++;
				if (current > N) {
					current = 1;
				}
			}

		}
		ans.push(circle[current]);
		circle[current] = 0;
		cnt++;
		if (cnt == N) break;
	}
	cout << "<";
	while (ans.size() > 1) {
		cout << ans.front() << ", ";
		ans.pop();
	}
	cout << ans.front() << ">";
}
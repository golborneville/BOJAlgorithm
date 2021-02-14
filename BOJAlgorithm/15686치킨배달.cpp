#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int city[53][53];
bool chk[53][53];
int N, M;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
int choice[13];
int getMin() {
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		int minval = 987654321;
		for (int j = 0; j < chicken.size(); j++) {
			if (choice[j]) {
				int tmp = abs(chicken[j].first - home[i].first) + abs(chicken[j].second - home[i].second);
				if (tmp < minval) minval = tmp;
			}
		}
		sum += minval;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int minmin = 987654321;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				home.push_back({ i,j });
			}
			if (city[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < M; i++) {
		choice[i] = 1;
	}
	sort(choice, choice + chicken.size());
	do {
		int res = getMin();
		if (minmin > res) minmin = res;


	} while (next_permutation(choice, choice + chicken.size()));
	cout << minmin;
}
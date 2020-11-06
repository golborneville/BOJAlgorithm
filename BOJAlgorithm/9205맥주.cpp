#include<iostream>
#include<cstring>
using namespace std;
pair<int,int> posArr[105];
int dis[105][105];
int main() {
	int T;
	int n;
	int songdo;
	bool hap = false;
	cin >> T;

	while (T--) {
		memset(posArr, 0, sizeof(posArr));
		memset(dis, 0, sizeof(dis));
		cin >> n;
		cin >> posArr[0].first >> posArr[0].second;
		for (int i = 1; i <= n; i++) {
			cin >> posArr[i].first >> posArr[i].second;
		}
		cin >> posArr[n + 1].first >> posArr[n+1].second;
		for (int i = 0; i <= n+1; i++) {
			for (int j = 0; j <= n+1; j++) {
				int d = abs(posArr[i].first - posArr[j].first) + abs(posArr[i].second - posArr[j].second);
				if (0 < d && d <= 1000) {
					dis[i][j] = 1;
				}
			}
		}
		for (int k = 0; k <= n + 1; k++) {
			for (int i = 0; i <= n + 1; i++) {
				for (int j = 0; j <= n + 1; j++) {
					if (dis[i][k] && dis[k][j]) {
						dis[i][j] = 1;
						if (dis[0][n + 1]) {
							hap = true;
							break;
						}
					}

				}
			}
		}
		/*for (int i = 0; i <= n; i++) {
			if (dis[i][n+1] > 0) {
				hap = true;
				break;
			}
		}*/
		if (hap)	cout << "happy\n";
		else cout << "sad\n";

		hap = false;
	}
}

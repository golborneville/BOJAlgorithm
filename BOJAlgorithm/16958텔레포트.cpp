#include<iostream>
#include<vector>
using namespace std;
pair<int, pair<int, int>> city[1003]; // Ư������ / (x, y)
int disarr[1003][1003];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, T, M;
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		int sp, x, y;
		cin >> sp >> x >> y;
		city[i] = { sp, {x, y} };
	}

	//distance value from I to J
	//initialize & �ѹ��� ���� �� �ڷ���Ʈ ������ �ֵ� ���ּڰ����� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			disarr[i][j] = 987654321;

			if (city[i].first && city[j].first) {
				//both cities are special =  teleport!
				if (disarr[i][j] > T) disarr[i][j] = T;
			}
			//manhatten distance �� ��� ����� ��
			int tmpdis = abs(city[i].second.first - city[j].second.first) + abs(city[i].second.second - city[j].second.second);
			if (disarr[i][j] > tmpdis) disarr[i][j] = tmpdis;

		}
	}
	//#######################�÷��̵� �ͼ�!!!!!!!!!!!!!!!!
	for (int i = 1; i <= N; i++) {	//���İ��� ���
		for (int j = 1; j <= N; j++) { // ��� ���
			for (int k = 1; k <= N; k++) { //���� ���
				if (disarr[j][i] + disarr[i][k] < disarr[j][k])disarr[j][k] = disarr[j][i] + disarr[i][k];
			}
		}
	}



	cin >> M;
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
	
		cout << disarr[c1][c2] << "\n";
	}
	return 0;
}
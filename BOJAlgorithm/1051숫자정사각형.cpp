#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int N, M, A = 1,B; 
	int maxH = -1;
	char squr[53][53];
	memset(squr, ' ', sizeof(squr));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> squr[i][j];
		}
	}
	if (M > N) {
		B = N;
	}
	else {
		B = M;
	}
	while (A <= B) {
		for (int i = 0; i < N - A + 1; i++) {
			for (int j = 0; j < M - A + 1; j++) {
				int aa = squr[i][j] - 48;
				int bb = squr[i][j + A - 1] - 48;
				int cc = squr[i + A - 1][j] - 48;
				int dd = squr[i + A - 1][j + A - 1] - 48;
				if (aa == bb && bb == cc && cc == dd) {
					int sizeSq = A*A;
					if (sizeSq > maxH) {
						maxH = sizeSq;

					}
				}
			}
		}
		A++;
	}
	cout << maxH;
}
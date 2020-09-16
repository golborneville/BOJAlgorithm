#include<iostream>
using namespace std;

int N, M, K;
int NM[103][103];
int MK[103][103];
int answ[103][103];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> NM[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> MK[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int l = 0; l < M; l++) {
				answ[i][j]+= (MK[l][j]* NM[i][l]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout <<  answ[i][j] <<  " ";
		}
		cout <<  "\n";
	}

}
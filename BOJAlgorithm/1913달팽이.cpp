#include<iostream>
#include<cstring>
using namespace std;
int arr[1000][1000];
int main() {
	memset(arr, 0, sizeof(arr));
	int N, x=0,y=0, cntN, inp, rex, rey;
	int ip = -1, jp = 1;
	cin >> N  >> inp; 
	cntN = N*N;
	//	arr[x][y] 
	for (int i = 0; i < N-1; i++) {
		if (inp == cntN) {
			rex = x;
			rey = y;
		}
		arr[x][y] = cntN;
		x++;
		cntN--;
	}
	int total = N; //5
	while (total--) { //4

		for (int j = 0; j < total; j++) { 
			if (inp == cntN) {
				rex = x;
				rey = y;
			}
			arr[x][y] = cntN;
			y += jp;
			cntN--;
		}
		for (int i = 0; i < total; i++) {
			if (inp == cntN) {
				rex = x;
				rey = y;
			}
			arr[x][y] = cntN;
			x += ip;
			cntN--;
		}

		ip *= -1; // -1 -> 1
		jp *= -1; // 1 -> -1
		if (total == 1) {
			if (inp == cntN) {
				rex = x;
				rey = y;
			}
			arr[x][y] = 1;
			break;
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << rex + 1 << " " << rey + 1;
	return 0;
}
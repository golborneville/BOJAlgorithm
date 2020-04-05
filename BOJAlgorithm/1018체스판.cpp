#include<iostream>
#include<cstring>
using namespace std;
char chess[52][52];
int N, M, minCnt = 9876;
//아 한번도 안바뀌어서 0이나오는 경우 ㅅㅂ
int main() {
	memset(chess, 0, sizeof(chess));
	cin >> N >> M;
	//보드 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chess[i][j];
		}
	}
	 //8*8의 체스판으로 자르기
	//모든 경우의 수 체크하기
	for (int i = 0; i + 8 <= N; i++) { //i랑j는 8*8의 [0, 0] 의 좌표값이나 마찬가지
		for (int j = 0; j+8 <= M; j++) {
			int changeCntB = -1;
			int changeCntW = -1;
			//BWBWBWBW인경우로 맞추기
			int fc = 0;
			for (int l = i; l < 8 + i; l++) {
				int kc = 0;
				for (int k = j; k < 8 + j; k++) {
					if (fc % 2 == 0) {  //bwbwbwbw
						if (kc % 2 == 0) { // chess[l][k] = b
							if (chess[l][k] == 'W') {
								changeCntB++;
							}
						}
						else { // chess[l][k] = w
							if (chess[l][k] == 'B') {
								changeCntB++;
							}
						}
					}
					else { //wbwbwbwb
						if (kc % 2 == 0) { // chess[l][k] = w
							if (chess[l][k] == 'B') {
								changeCntB++;
							}
						}
						else { // chess[l][k] = b
							if (chess[l][k] == 'W') {
								changeCntB++;
							}
						}
					}
					kc++;
				}
				fc++;
			}
			

			//WBWBWBWB로 맞추기!
			
			int fec = 0;
			for (int l = i; l < 8 + i; l++) {
				int kc = 0;
				for (int k = j; k < 8 + j; k++) {
					if (fec % 2 != 0) {  //bwbwbwbw
						if (kc % 2 == 0) { // chess[l][k] = b
							if (chess[l][k] == 'W') {
								changeCntW++;
							}
						}
						else { // chess[l][k] = w
							if (chess[l][k] == 'B') {
								changeCntW++;
							}
						}
					}
					else { //wbwbwbwb
						if (kc % 2 == 0) { // chess[l][k] = w
							if (chess[l][k] == 'B') {
								changeCntW++;
							}
						}
						else { // chess[l][k] = b
							if (chess[l][k] == 'W') {
								changeCntW++;
							}
						}
					}
					kc++;
				}
				fec++;
			}
			
			//changeCnt & mincnt 비교! 
			int cntTotal=-1;
			if (changeCntB < changeCntW) { 
					cntTotal = changeCntB;
				
			}
			else {
				cntTotal = changeCntW;
			}
			
			if (minCnt > cntTotal+1) {
				minCnt = cntTotal+1;
				
			}
		}
	}
	cout << minCnt;


}
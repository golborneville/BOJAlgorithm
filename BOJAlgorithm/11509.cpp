#include<stdio.h>
int N, cnt,ind = 0;;
int ball[1000003] = { 0 };
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &ind);

		if (ball[ind + 1] == 0) {
			//윗층에서 화살 내려온거 아니니까 화살 추가 
			cnt++;
			ball[ind]++; // 지금 인덱스 기준으로 하고 잇자너 
		}
		else {
			//하늘에서 화살이 내려와아아
			ball[ind + 1]--;
			ball[ind]++;
		}

	}


	printf("%d",cnt);
}
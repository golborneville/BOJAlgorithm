#include<iostream>
#include<deque>
using namespace std;
deque<int> deq;

int Narr[53]; //i번째 인덱스:숫자   값: 숫자위치
int head = 1; 
int tail; //둘다 인덱스 기준임
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int total = 0;
	int N, M;
	cin >> N >> M;
	tail = N;
	for (int i = 1; i <= N; i++) {
		Narr[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int popNum; //position;
		cin >> popNum;
		//정방향
		int rightway = Narr[popNum] - 1;

		//역방향 (front->tail 1) + tail~popnum //n-i 는 현재 pop이전에 ㅌ총 개수
		int opway = 1 + (N - i - Narr[popNum]);

		if (rightway <= opway) {
			//정방향
			total += rightway;

			//2번 연산
			//int pos = Narr[popNum];
			Narr[popNum] = 0; //pop!

			for (int k = 0; k <= rightway; k++) {
				for (int j = 1; j <= N; j++) {
					if (!Narr[j]) continue; //0이라서 이미 pop된 애들
					Narr[j]--;
					if (!Narr[j]) Narr[j] = N - i; //현재 차례에 pop되는 애 제외
				}
			}


		}
		else {
			//역방향
			total += opway;

			Narr[popNum]=0;
			for (int k = 1; k < opway; k++) {
				for (int j = 1; j <= N; j++) {
					if (!Narr[j]) continue; //0이라서 이미 pop된 애들
					Narr[j]++;
					if (Narr[j]> N-i ) Narr[j] = 1; //현재 차례에 pop되는 애 제외
				}
			}
		}

	}
	cout << total;
	return 0;
}
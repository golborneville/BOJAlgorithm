#include<iostream>
#include<deque>
using namespace std;
deque<int> deq;

int Narr[53]; //i��° �ε���:����   ��: ������ġ
int head = 1; 
int tail; //�Ѵ� �ε��� ������
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
		//������
		int rightway = Narr[popNum] - 1;

		//������ (front->tail 1) + tail~popnum //n-i �� ���� pop������ ���� ����
		int opway = 1 + (N - i - Narr[popNum]);

		if (rightway <= opway) {
			//������
			total += rightway;

			//2�� ����
			//int pos = Narr[popNum];
			Narr[popNum] = 0; //pop!

			for (int k = 0; k <= rightway; k++) {
				for (int j = 1; j <= N; j++) {
					if (!Narr[j]) continue; //0�̶� �̹� pop�� �ֵ�
					Narr[j]--;
					if (!Narr[j]) Narr[j] = N - i; //���� ���ʿ� pop�Ǵ� �� ����
				}
			}


		}
		else {
			//������
			total += opway;

			Narr[popNum]=0;
			for (int k = 1; k < opway; k++) {
				for (int j = 1; j <= N; j++) {
					if (!Narr[j]) continue; //0�̶� �̹� pop�� �ֵ�
					Narr[j]++;
					if (Narr[j]> N-i ) Narr[j] = 1; //���� ���ʿ� pop�Ǵ� �� ����
				}
			}
		}

	}
	cout << total;
	return 0;
}
#include<stdio.h>
int N, cnt,ind = 0;;
int ball[1000003] = { 0 };
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &ind);

		if (ball[ind + 1] == 0) {
			//�������� ȭ�� �����°� �ƴϴϱ� ȭ�� �߰� 
			cnt++;
			ball[ind]++; // ���� �ε��� �������� �ϰ� ���ڳ� 
		}
		else {
			//�ϴÿ��� ȭ���� �����;ƾ�
			ball[ind + 1]--;
			ball[ind]++;
		}

	}


	printf("%d",cnt);
}
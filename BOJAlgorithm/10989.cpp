#include<stdio.h>
int num[10003] = { 0 };
int main() {
	int N;
	scanf_s("%d", &N);
	for(int i=0; i<N; i++) {
		int ind;
		scanf_s("%d", &ind);
		num[ind]++;
	}

	for (int i = 0; i <= 10000; i++) {
		if (num[i] != 0) {
			for (int j = 0; j < num[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;

}
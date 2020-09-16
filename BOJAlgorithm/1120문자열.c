#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char *A = malloc(sizeof(A) * 52);
	char *B = malloc(sizeof(B) * 52);
	int tmp = 0;
	int cnt = 0, maxCnt = 987654321;
	scanf("%s %s", A, B);
	while (tmp + strlen(A) <= strlen(B)) {
		for (int i = 0; i < strlen(A); i++) {
			if (A[i] != B[i+tmp]) cnt++;
		}
		if (cnt < maxCnt)
			maxCnt = cnt;
		cnt = 0;
		tmp++;
	}
	printf("%d", maxCnt);

}
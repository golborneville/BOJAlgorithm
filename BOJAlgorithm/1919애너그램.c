#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int alp[26];
int main() {
	int answer = 0;
	char *A = malloc(sizeof(char) * 1000);
	char *B = malloc(sizeof(char) * 1000);
	scanf("%s %s", A, B);
	for (int i = 0; i < strlen(A); i++) {
		alp[A[i] - 97]+=1;
	}
	for (int i = 0; i < strlen(B); i++) {
		alp[B[i] - 97]-=1;
	}
	for (int i = 0; i < 26; i++) {
		if (alp[i] != 0) {
			if (alp[i] < 0) {
				answer += (alp[i] * -1);
			}
			else {
				answer += alp[i];
			}
		}
	}
	printf("%d", answer);
	return 0;
}
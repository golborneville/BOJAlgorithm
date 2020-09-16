#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int A, B, C, D, E;
int main() {
	int time = 0;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
	if (A < 0) {
		time += A * -1 * C;
		time += D;
		time += B *  E;
	}
	else if (A > 0) {
		time += (B - A) * E;
	}
	else { //A == 0
		time += D + B*E;
	}
	printf("%d", time);

}
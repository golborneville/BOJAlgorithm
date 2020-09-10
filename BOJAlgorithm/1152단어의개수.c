#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main() {
	int ans = 0;
	char *ptr;
	char *sent = malloc(sizeof(char) *1000003);
	gets(sent);
	ptr = strtok(sent, " ");
	while (ptr) {
		if (strlen(ptr) != 0) {
			ans += 1;
		}
		ptr = strtok(NULL, " ");
	}
	printf("%d", ans);
}
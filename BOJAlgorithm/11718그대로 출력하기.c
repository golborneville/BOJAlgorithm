#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main() {
	char word;
	//char *word = malloc(sizeof(char) * 102);
	while ((word = getchar()) != EOF) {
		printf("%c", word);
	}
	return 0;
}
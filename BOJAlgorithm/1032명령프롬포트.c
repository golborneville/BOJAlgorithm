#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char cmpname[55];
int main() {
	int N; //공통이 아니면 ?으로 대체 하기 
	scanf("%d", &N);
	//memset(cmpname, '0', sizeof(cmpname));
	char *filename = malloc(sizeof(char)*52);
	while (N--) {
		scanf("%s", filename);
		for (int i = 0; i < strlen(filename); i++) {
			if (cmpname[i] == '\0' ) {
				cmpname[i] = filename[i];
			}
			else {
				if (cmpname[i] != filename[i]) {
					cmpname[i] = '?';
				}
			}
		}
	}
	printf("%s", cmpname);
	return 0;
}
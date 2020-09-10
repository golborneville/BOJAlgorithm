#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<string.h>

int main() {
	char current[10];
	char bomb[10];
	int time[3], timeto[3],i =0;
	char *ptr, *ptr_b;
	
	scanf("%s %s", current, bomb);
	ptr = strtok(current, ":");
	while (ptr != NULL) {
		char *tt = ptr;
		time[i] = (tt[0] -48)*10 + (tt[1]-48);
		ptr = strtok(NULL, ":");
		i++;
	}
	i = 0;
	ptr = strtok(bomb, ":");
	while (ptr != NULL) {
		char *tt = ptr;
		timeto[i] = (tt[0] - 48) * 10 + (tt[1] - 48);		ptr = strtok(NULL, ":");
		i++;
	}
	if (time[2] > timeto[2]) {
		if (timeto[1] == 0) {
			timeto[0] -= 1;
			timeto[1] += 60;
		}
		timeto[1] -= 1;
		timeto[2] += 60;
	}
	timeto[2] = timeto[2] - time[2];
	if (time[1] > timeto[1]) {
		timeto[0] -= 1;
		timeto[1] += 60;
	}
	timeto[1] = timeto[1] - time[1];
	if (time[0] < timeto[0])
		timeto[0] = timeto[0] - time[0];
	else
		timeto[0] = timeto[0] + (24 - time[0]);

	if (timeto[0] == 24)
		timeto[0] = 0;
	if (timeto[0] == 0 && timeto[1] == 0 && timeto[2] == 0) {
		timeto[0] = 24;
	}
	char *result;
	
	printf("%d%d:%d%d:%d%d", timeto[0]/10, timeto[0] % 10, timeto[1] / 10, timeto[1] % 10, timeto[2] / 10, timeto[2] % 10);
	return 0;
}

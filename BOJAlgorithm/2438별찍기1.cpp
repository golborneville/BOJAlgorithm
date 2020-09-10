#include<iostream>
using namespace std;

int N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j<i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
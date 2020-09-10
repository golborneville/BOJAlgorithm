#include<iostream>
using namespace std;

int N;
int main() {
	cin >> N;
	for (int i = 0; i< N; i++) {
		for (int j = 0; j<N - i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
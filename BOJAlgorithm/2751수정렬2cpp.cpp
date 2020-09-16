#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1000003];
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}
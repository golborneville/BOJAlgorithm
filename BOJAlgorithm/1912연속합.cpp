#include<iostream>
using namespace std;

int arr[100003];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int totalsum = arr[0];
	for (int i = 1; i < N; i++) {
		if(arr[i-1]>0) arr[i] += arr[i-1];
		if (totalsum < arr[i]) totalsum = arr[i];
	}
	cout << totalsum;
}
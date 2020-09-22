#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = N - 1; i >= 1; i--) {
		N *= i;
	}
	if (N == 0) {
		cout << 1;
		return 0;
	}
	cout << N;
	return 0;
}
#include<iostream>

int n, k;
int fib[23];
int main() {
	std::cin >> n >> k;
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= n; i++) {
		fib[i] = fib[i - 1] * i;
	}

	int  re = (fib[n] / fib[k]) / fib[n - k];
	std::cout << re;
	return 0;
}
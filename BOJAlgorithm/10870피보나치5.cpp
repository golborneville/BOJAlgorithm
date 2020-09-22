#include<iostream>

long long int n;
long long int fib[23];
int main() {
	std::cin >> n;
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	std::cout << fib[n];
	return 0;
}
#include<iostream>
#include<cstring>
int n, k;
int fib[1007][1007];
int fibo(int n, int k) {
	if (k == n || k == 0) return 1;

	int &ret = fib[n][k];
	if (ret != -1) return ret;

	ret = fibo(n - 1, k) + fibo(n - 1, k-1);
	return ret % 10007;

}
int main() {
	std::cin >> n >> k;
	/*fib[0][0] = 0;
	fib[0][1] = 0;*/
	memset(fib, -1, sizeof(fib));

	int ans = fibo(n, k);
	//	int  re = (fib[n] / fib[k]) / fib[n-k];
	std::cout << ans;
	return 0;
}

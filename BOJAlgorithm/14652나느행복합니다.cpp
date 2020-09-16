#include<iostream>
using namespace std;

int N, M, K;
int main() {
	cin >> N >> M >> K;
	//K += 1;
	int i = K / M;
	int j = K - M * i;
//	if (j < 0)j += M;
	cout << i << " " << j;
	return 0;
}
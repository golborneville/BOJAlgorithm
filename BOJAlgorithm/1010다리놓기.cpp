#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		unsigned long long int result =1;

		if (N > M / 2) { //##¿©±â°¡ ÇÙ½É##//
			N = M - N;
		}
		for (int i = M; i >= M - N+1; i--) {
			result *= i;
		}
		for (int i = N; i >= 1; i--) {
			result /= i;
		}
		
		cout << result << "\n";
	}
	return 0;
}
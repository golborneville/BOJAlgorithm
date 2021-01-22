#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, res = 0;
		cin >> N; 
		while (N--) {
			int tmp;
			cin >> tmp;
			res += tmp;
		}
		cout << res << "\n";
	}
	return 0;
}
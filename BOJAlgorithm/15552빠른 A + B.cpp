#include<iostream>
using namespace std;
int T, A, B;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
}
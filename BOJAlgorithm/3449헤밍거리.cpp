#include<iostream>
#include<string>
#include<bitset>
using namespace std;
int T;
string a, b;
int main() {
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) cnt++;
		}
		cout << "Hamming distance is " << cnt << ".\n";
	}
	return 0;
}
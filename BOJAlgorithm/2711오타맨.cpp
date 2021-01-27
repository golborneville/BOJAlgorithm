#include<iostream>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string text;
		int missindex;
		cin >> missindex >> text;
		for (int i = 0; i < text.size(); i++) {
			if (i + 1 == missindex)continue;
			cout << text[i];
		}
		cout << "\n";
	}
	return 0;
}
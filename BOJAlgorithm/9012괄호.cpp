#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	string input;
	stack<char> brace;
	cin >> T;
	while (T--) {
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(') {
				brace.push('(');
			}
			else if (input[i] == ')') {
				if (brace.empty()) {
					brace.push(')');
					continue;
				}
				if (brace.top() == '(') {
					brace.pop();
				}
				else if (brace.top() == ')') {
					brace.push(')');
				}
			}
		}

		if (brace.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
			while (!brace.empty()) {
				brace.pop();
			}
		}
	}

}
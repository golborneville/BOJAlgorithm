#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> op; // * + / - (


//A + (B * C) - D/E
// ABC*+DE/-

//re: A B C * + D E / - 
//op(stack):
int main() {
	string state, res = "";

	cin >> state;
	for (int i = 0; i < state.size(); i++) {
		if (state[i] == '(')
			op.push(state[i]);
		else if (state[i] == ')') {
			while (!op.empty() && op.top() != '(') {
				res += op.top();
				op.pop();
			}

			op.pop(); // pop ( 
		}
		else if (state[i] == '*' || state[i] == '/') {
			while (!op.empty() && (op.top() == '*' || op.top() == '/') ) {
				res += op.top();
				op.pop();
			}

			op.push(state[i]);
		}
		else if (state[i] == '+' || state[i] == '-') {
			while (!op.empty() && op.top() != '(') {
				res += op.top();
				op.pop();
			}
			op.push(state[i]);
		}
		else { // A ~ Z
			res+= state[i];
		}
	}
	while (!op.empty()) {
		res += op.top();
		op.pop();
	}
	cout << res;
}
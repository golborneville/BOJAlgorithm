#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<int> num;
	unsigned long long int res = 0;
	int K;  cin >> K;
	while (K--) {
		int val;
		cin >> val;
		if (!val) 
			num.pop();
		else
			num.push(val);
	}
	while (!num.empty()) {
		res += num.top();
		num.pop();
	}
	cout << res;
	return 0;
}
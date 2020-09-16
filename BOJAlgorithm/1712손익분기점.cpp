#include<iostream>
using namespace std;

long long int A, B, C;
int main() {
	cin >> A >> B >> C;
	//int cnt = 0;
	if (B >= C) {
		//손익분기점 발생 X
		cout << -1;
	}
	else {
		long long int result = A / (C - B) + 1;
		cout << result;A
	}
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	string num;
	cin >> num;
	sort(num.begin(), num.end(), greater<>());
	cout << num;
	return 0;
}
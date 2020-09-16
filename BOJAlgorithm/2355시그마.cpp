#include<iostream>
using namespace std;

long long int A, B,C;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;

	
	if (A >= B) {
		C = (A *(A + 1)) / 2 - (B * (B - 1)) / 2;
	}
	else {
		C = (B *(B + 1)) / 2 - (A * (A - 1)) / 2;
	}
	cout << C;
}
#include<iostream>
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C, D;

	cin >> A >> B >> C >> D;
	int h = D / 3600;
	int m = (D % 3600) / 60;
	int s = (D % 3600) % 60;
	C += s;
	while (C >= 60) {
		B += 1;
		C -= 60;
	}
	B += m;
	while (B >= 60) {
		A += 1;
		B -= 60;
	}
	A += h;
	while (A >= 24) {
		A -= 24;
	}

	cout << A << " " << B << " " << C;

}
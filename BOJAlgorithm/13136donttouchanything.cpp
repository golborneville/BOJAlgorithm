#include<iostream>
using namespace std;

unsigned long long int R, C, N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> N;
	unsigned long long int r = 0;
	if (R%N != 0) r += 1;
	r += R / N;

	unsigned long long int c = 0;
	if (C%N != 0) c += 1;
	c += C / N;
	unsigned long long int re= r*c;
	cout << re;

}
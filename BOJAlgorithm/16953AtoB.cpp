#include<iostream>
using namespace std;
int mincnt = 987654321;
//bool cont = true;
void rec(long long int a, long long int b, int cnt) {
	if (a == b) {
		if (cnt < mincnt) mincnt = cnt;
		return;
	}
	if (a > b) return;

	rec(a * 10 + 1, b, cnt+1);

	rec(a * 2, b, cnt + 1);
}

int main() {
	long long int A, B;
	cin >> A >> B;
	rec(A, B, 0);
	if (mincnt == 987654321) cout << -1;
	else 	cout << mincnt + 1;

	return 0;

}
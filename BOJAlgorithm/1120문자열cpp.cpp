#include<iostream>
#include<string>
using namespace std;
string A, B;
int minN = 98765;
int main() {
	cin >> A >> B;
	int as = A.size();
	int bs = B.size();
	for (int i = 0; i < bs - as + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < as; j++) {
			if (A[j] != B[j+i]) cnt++;
		}
		if (cnt < minN) minN = cnt;
	}
	cout << minN;
}
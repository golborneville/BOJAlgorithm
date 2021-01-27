#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmpString(string A, string B) {// is A > B? true of false
	if (A.length() != B.length()) {
		return A.length() > B.length();
	}
	else { //길이 동일
		return A > B;
	}
}

int main() {
	string A, B;
	cin >> A >> B;
	sort(A.begin(), A.end());
	string maxComb = "0";
	do {
		if (A[0] == '0') continue;
		if (cmpString(B,A) && cmpString(A, maxComb)) maxComb = A;

	} while (next_permutation(A.begin(), A.end()));
	if (maxComb == "0")cout << -1;
	else cout << maxComb;
	return 0;
}
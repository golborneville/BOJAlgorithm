#include <iostream>
#include<string>
#include <cstring>
using namespace std;

int N, M;
string S;
int F[1000000];
void FailureFunction(string P) {
	F[0] = 0;
	int i = 1, j = 0;
	int m = P.size();
	while (i < m) {
		if (P[i] == P[j]) {
			//we have match of j+1 chars
			F[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0){
			//use FF to shift P
			j = F[j - 1];
		}
		else {
			//no match
			F[i] = 0; i++;
		}
	}
}
int KMP(string T, string P) {
	FailureFunction(P);
	int i = 0, j = 0;
	int n = T.size();
	int m = P.size();
	int cnt = 0;
	while (i < n) {
		if (T[i] == P[j]) {
			if (j == m - 1) {
				cnt++;
				//return i - j; // match
			}
			//else {
			i++;
			j++;
			//}
		}
		else {
			if (j > 0) {
				j = F[j - 1]; // jump
			}
			else {
				i++;
			}
		}
	}

	return cnt; //no match
}

int main() {
	string p="";
	cin >> N >> M >> S;
	for (int i = 0; i < 2 * N + 1; i++) {
		if (i % 2 == 0)
			p += "I";
		else
			p += "O";
	}
	int result = KMP(S, p);
	cout << result;

}
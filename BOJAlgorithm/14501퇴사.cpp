#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int N, p[17], t[17], most_pay = 0;

int main() {
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf_s("%d %d", &t[i], &p[i]);
	}

	for (int i = N; i > 0; i--) {
		if (i + t[i] > N+1) {
			p[i] = p[i + 1];
		}
		else {
			p[i] = max(p[i] + p[i + t[i]], p[i + 1]);
			most_pay = max(most_pay, p[i]);
		}
	}
	cout << most_pay;

}
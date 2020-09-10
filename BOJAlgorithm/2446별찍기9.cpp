#include<iostream>
using namespace std;
int N;
int main() {
	cin >> N;
	for (int i = 0; i< N; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j<2 * (N - i) - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j<N - i; j++) {
			cout << " ";
		}
		for (int j = 0; j<2 * i - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

}
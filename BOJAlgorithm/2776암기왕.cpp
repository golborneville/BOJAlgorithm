#include<iostream>
#include<set>
using namespace std;

int note[1000003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		set<int> chk;
		int N, M;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			chk.insert(num);

		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			if (chk.find(num) != chk.end()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}

		}
	}
}
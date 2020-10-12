#include<iostream>
#include<map>
using namespace std;

int N, M;
map<int, int> tr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		int tmp;
		cin >> tmp;
		if (tr.find(tmp) == tr.end()) { // 존재 하지 않음
			tr[tmp] = 0;
		}
		tr[tmp] = tr[tmp] + 1;
	}
	cin >> M;
	while (M--) {
		int tmp;
		cin >> tmp;
		auto iter = tr.find(tmp);
		if (iter == tr.end()) {
			cout << 0 << " ";
		}
		else {
			cout << iter->second << " ";
		}
	}
}
#include<iostream>
#include<string>
#include<set>
using namespace std;

int N;
//string arr[20003];
struct ordercm {
	bool operator()(const string& a, const string& b)const {
		if (a.length() != b.length())
			return a.length() < b.length();
		else {
			return a < b;
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	set<string, ordercm> se;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		//cin >> arr[i];
		string in;
		cin >> in;
		se.insert(in);
	}
	for (const auto& str : se) {
		cout << str << "\n";
	}
}
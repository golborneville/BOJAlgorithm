#include<iostream>
using namespace std;
int main() {
	int num=0, ans = 0;
	cin >> num;
	char aa;
	while (num--) {
		cin >> aa;
		ans += (aa - 48);
	}
	cout << ans;
	return 0;
}
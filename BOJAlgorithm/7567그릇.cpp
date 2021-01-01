#include<iostream>
#include<string>
using namespace std;

string dish;

int main() {
	cin >> dish;
	int total = 10;
	for (int i = 1; i < dish.size(); i++) {
		if (dish[i - 1] == dish[i]) {
			//successive
			total+=5;
		}
		else {
			//non-successive
			total += 10;
		}
	}
	cout << total;

	return 0;
}
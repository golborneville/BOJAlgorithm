#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int arr[4];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	sort(arr, arr + 4);
	int diff = (arr[0] + arr[3]) - (arr[2] + arr[1]);
	if (diff < 0)
		diff *= -1;
	cout << diff;
}
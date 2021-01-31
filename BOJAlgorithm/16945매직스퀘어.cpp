#include<iostream>
#include<algorithm>
using namespace std;

int arr[9];//1~9(입력 받는거)
int com[9] = { 1,2,3,4,5,6,7,8,9 };
//인덱스 기준
// 0 1 2
// 3 4 5 
// 6 7 8
int getPrice() {
	int diffSum = 0;
	for (int i = 0; i < 9; i++) {
		diffSum += abs(com[i] - arr[i]);
	}
	return diffSum;

}
bool chkmagic() {
	int stand = com[0] + com[1] + com[2];
	if (stand != com[3] + com[4] + com[5]) return false;
	if (stand != com[6] + com[7] + com[8]) return false;
	if (stand != com[0] + com[3] + com[6]) return false;
	if (stand != com[1] + com[4] + com[7]) return false;
	if (stand != com[2] + com[5] + com[8]) return false;
	if (stand != com[0] + com[4] + com[8]) return false;
	if (stand != com[2] + com[4] + com[6]) return false;
	return true;

}
int main() {
	int minres = 987654321;

	for (int i = 0; i < 9; i++) {
			cin >> arr[i]; //총 8줄이 모두 같은 값이 되어야함
	}
	do {
		if (!chkmagic())continue;
		int cmp = getPrice();
		if (minres > cmp) minres = cmp;

	} while (next_permutation(com, com + 9));

	cout << minres;
	return 0;
}
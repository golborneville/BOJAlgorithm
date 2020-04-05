#include<iostream>
#include<cstring>
using namespace std;
int baseball[11][11][11];
int st, ball, T;
char num[3]; //46빼주는 거 잊지 말기
int main() {
	cin >> T;
	int cnt = T;
	int result = 0;
	memset(baseball, 0, sizeof(baseball));
	while (T--) {
		cin >> num >> st >> ball; //num은 민혁이가 부르는 숫자
		int s = 0, b = 0; 
		//case1 : 3s 0b
		if (st == 3) {
			//num이 정답
			result = 1;
			cout << 1;
			return 0;
		}
		for (int i = 1; i <= 9; i++) { //백의자리
			for (int j = 1; j <= 9; j++) { //십의자리
				for (int k = 1; k <= 9; k++) { //일의자리

					if (i != j && j != k && i != k) {
						//일 십 백의 자리에 스트라이ㅌ크 잇는 경우 각
						if ((num[0] - 48) == i) {
							s++;
						}
						if ((num[1] - 48) == j) {
							s++;
						}
						if ((num[2] - 48) == k) {
							s++;
						}
						//백의 자리 숫자가 십 또는 일의자리에 잇어서 볼인경우
						if ((num[0]) - 48 != i && (num[0]) - 48 == j) {
							b++;
						}
						if ((num[0]) - 48 != i && (num[0]) - 48 == k) {
							b++;
						}
						//십의 자리 숫자가 백 또는 일의자리에 잇어서 볼인경우
						if ((num[1]) - 48 != j && (num[1]) - 48 == i) {
							b++;
						}
						if ((num[1]) - 48 != j && (num[1]) - 48 == k) {
							b++;
						}
						//일의 자리 숫자가 십 또는 백의자리에 잇어서 볼인경우
						if ((num[2]) - 48 != k && (num[2]) - 48 == j) {
							b++;
						}
						if ((num[2]) - 48 != k && (num[2]) - 48 == i) {
							b++;
						}

						if (s == st && b == ball) {
							baseball[i][j][k]++;
							//cout << i << j << k << endl;
						}

						s = 0; b = 0;
					}
				}
			}
		}
	}
	for (int i = 1; i <= 9; i++) { //백의자리
		for (int j = 1; j <= 9; j++) { //십의자리
			for (int k = 1; k <= 9; k++) { //일의자리
				if (baseball[i][j][k] == cnt) {
					result++;
				}
			}
		}
	}
	cout << result;

}
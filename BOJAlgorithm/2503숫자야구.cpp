#include<iostream>
#include<cstring>
using namespace std;
int baseball[11][11][11];
int st, ball, T;
char num[3]; //46���ִ� �� ���� ����
int main() {
	cin >> T;
	int cnt = T;
	int result = 0;
	memset(baseball, 0, sizeof(baseball));
	while (T--) {
		cin >> num >> st >> ball; //num�� �����̰� �θ��� ����
		int s = 0, b = 0; 
		//case1 : 3s 0b
		if (st == 3) {
			//num�� ����
			result = 1;
			cout << 1;
			return 0;
		}
		for (int i = 1; i <= 9; i++) { //�����ڸ�
			for (int j = 1; j <= 9; j++) { //�����ڸ�
				for (int k = 1; k <= 9; k++) { //�����ڸ�

					if (i != j && j != k && i != k) {
						//�� �� ���� �ڸ��� ��Ʈ���̤�ũ �մ� ��� ��
						if ((num[0] - 48) == i) {
							s++;
						}
						if ((num[1] - 48) == j) {
							s++;
						}
						if ((num[2] - 48) == k) {
							s++;
						}
						//���� �ڸ� ���ڰ� �� �Ǵ� �����ڸ��� �վ ���ΰ��
						if ((num[0]) - 48 != i && (num[0]) - 48 == j) {
							b++;
						}
						if ((num[0]) - 48 != i && (num[0]) - 48 == k) {
							b++;
						}
						//���� �ڸ� ���ڰ� �� �Ǵ� �����ڸ��� �վ ���ΰ��
						if ((num[1]) - 48 != j && (num[1]) - 48 == i) {
							b++;
						}
						if ((num[1]) - 48 != j && (num[1]) - 48 == k) {
							b++;
						}
						//���� �ڸ� ���ڰ� �� �Ǵ� �����ڸ��� �վ ���ΰ��
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
	for (int i = 1; i <= 9; i++) { //�����ڸ�
		for (int j = 1; j <= 9; j++) { //�����ڸ�
			for (int k = 1; k <= 9; k++) { //�����ڸ�
				if (baseball[i][j][k] == cnt) {
					result++;
				}
			}
		}
	}
	cout << result;

}
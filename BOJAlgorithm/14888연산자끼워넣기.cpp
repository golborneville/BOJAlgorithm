#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, arr[15], cal[4];
char symbol[15];
int maxSum = -1500000000, minSum = 1500000000;
vector<int>  case_permu;
vector<int> deep_grp[11];

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void calculate_case() {
	int tmp = arr[0];
	for (int i = 0; i < case_permu.size(); i++) {
		switch (case_permu[i]) {
		case 0: // +
			tmp = tmp + arr[i + 1];
			break;
		case 1: // -
			tmp = tmp - arr[i + 1];
			break;
		case 2: // *
			tmp = tmp * arr[i + 1];
			break;
		case 3: // /
			tmp = tmp / arr[i + 1];
			break;
		}
	}
	if (tmp > maxSum) {
		maxSum = tmp;
	}
	if (tmp < minSum) {
		minSum = tmp;
	}
}
void permutation(int n, int r) {

	// Ż���������� r�� 0�� �Ǹ� ������ �� ��찡 �Ϸ�Ǿ����Ƿ� return�մϴ�.
	if (r == 0) {
		calculate_case();
		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(&case_permu[i], &case_permu[n - 1]);
		permutation(n - 1, r - 1);
		// �Ʒ�ó�� �ٽ� swap������� �������� ��� ������ �� arr�� ��ȭ���Ե˴ϴ�.
		swap(&case_permu[i], &case_permu[n - 1]);
	}

}

int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf_s("%d", &cal[i]);
		while (cal[i]--) {
			case_permu.push_back(i);
		}
	}
	//�������� STL �ð� �ʰ� ���� �ȴ뿵
	permutation(case_permu.size(), case_permu.size());

	printf("%d\n%d", maxSum, minSum);
}
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

	// 탈출조건으로 r이 0이 되면 순열의 한 경우가 완료되었으므로 return합니다.
	if (r == 0) {
		calculate_case();
		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(&case_permu[i], &case_permu[n - 1]);
		permutation(n - 1, r - 1);
		// 아래처럼 다시 swap을해줘야 마지막에 모두 끝났을 때 arr가 변화없게됩니다.
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
	//순열조합 STL 시간 초과 나서 안대영
	permutation(case_permu.size(), case_permu.size());

	printf("%d\n%d", maxSum, minSum);
}
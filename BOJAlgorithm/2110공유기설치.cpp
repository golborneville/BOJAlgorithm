#include<iostream>
#include<algorithm>
using namespace std;
int home[200004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> home[i];
	}
	sort(home, home + N);
	
	//##################left = 1, right = home[N-1] - home[0]  �̰� ��������

	int left = 1; //������ ������ �ּ� �Ÿ� 
	//���� ���� �� (����)
	int right = home[N - 1] - home[0];// ������ ���� �� ( ����)
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2; //�̺�Ž�� ���� �߰��� ����-> �� ���� : ���� �ִ밣���� �ɼ� �ִ� �ĺ� 
		int prev_ind = 0; //���� �ֱٿ� ��ġ�� �������� ��ġ
		int cnt = 1; //���� ������ ��ġ �ϰ� ����(�׷��� �񱳱� �����Ⱑ ����)


		for (int ind = 1; ind < N; ind++) {
			if (home[ind] - home[prev_ind] >= mid) {
				cnt++; // ind ��ġ�� ������ �ϳ� �� ��ġ!
				prev_ind = ind;
			}
		}
		// mid ���� �������� ��ġ �� �غ��� ����~ ������ ���� �ּ� ��� ���� �� ä����?
		if (cnt >= C) {
			//ä��! ���� �� �� �־�! -> �� ū���� �ֳ� �� Ȯ������!
			left = mid + 1;
		}
		else {
			//���� ������ ��ġ �� �ؾ��� = ���� �� �ٿ���� �� ( ���� �� �۾��� ��..)
			right = mid - 1;
		}
		if (answer < mid && cnt >= C) { //���� ���ݺ��� ū ��(�ִ� ����) & �ּ� ������ ���� �� ��ġ ���� -> �� �ĺ� ����
			answer = mid;
		}

	}
	cout << answer;
	return 0;
}
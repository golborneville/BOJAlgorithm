#include<iostream> //��ͷ� Ǫ�� ���� + ���ڰ� 1~N�� �ƴ�**
#include<algorithm>
using namespace std;

bool chk[10];
int arr[10];
int ans[10];
int M, N;

void recur(int depth) { // ���̽���DFS��
	if (depth == M) { //m��° ������ ���� �� ��� 
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	//�� �� �� �ܰ辿 ���� ���� �ϴ� ���
	for (int i = 0; i < N; i++) {
		if (chk[i])continue;
		chk[i] = true;
		ans[depth] = arr[i];
		recur(depth + 1); //3 -> 3 �ߺ� ����**�̶� �����ܰ踦 i+1�� �ƴ϶�
		//i �ܰ迡�� �밡����� �� i= m �� �°� ***
		chk[i] = false;

	}




}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M; // nPm
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); //��������
	recur(0);

}
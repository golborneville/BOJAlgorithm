#include<iostream> //��ͷ� Ǫ�� ����
using namespace std;

bool chk[10];
int arr[10];
int M, N;

void recur(int m, int depth) { // ���̽���DFS��
	if (depth == M) { //m��° ������ ���� �� ��� 
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	//�� �� �� �ܰ辿 ���� ���� �ϴ� ���
	for (int i = m; i <= N; i++) { //�ٽ�1
		if (chk[i])continue;
		chk[i] = true;
		arr[depth] = i;
		recur(i+1, depth + 1); // �ٽ�2
		chk[i] = false;

	} 




}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> M; // nCm
	recur(1, 0); // (0, 0)���� �����ϸ� 0~N���� ���� ���ϰ� �� 

}
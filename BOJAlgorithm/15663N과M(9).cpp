#include<iostream> //��ͷ� Ǫ�� ����
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

bool chk[10];
int arr[10];
int M, N;
vector<int> vec;
set<vector<int>> S;
void recur(int depth) { // ���̽���DFS�� //���ʿ� m�� ������ �ʴ� �Ű� ������
	if (depth == M) { //m��° ������ ���� �� ��� 
		S.insert(vec);
		return;
	}
	//�� �� �� �ܰ辿 ���� ���� �ϴ� ���
	for (int i = 0; i < N; i++) {
		if (chk[i])continue;
		chk[i] = true;
		vec.push_back(arr[i]);
		//arr[depth] = i;
		recur(depth + 1);
		vec.pop_back();
		chk[i] = false;

	}




}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> M; // nPm
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); //��������
	recur(0);

	for (auto iter = S.begin(); iter != S.end(); iter++) {
		for (size_t i = 0; i < iter->size(); i++)
		{
			cout << iter->at(i) << " ";
		}
		cout << '\n';
	}

}
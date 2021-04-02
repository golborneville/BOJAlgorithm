#include<iostream>
#include<algorithm>
using namespace std;

int N;
pair<int, int> egg[10]; // ������, ����
int comb[8] = { 0,1,2,3,4,5,6,7 };
int res = 0;
void DFS(int idx)
{
	if (idx >= N)
	{	
		//�� �̻� Ž�� X -> need counting
		int cnt = 0;
		for (int i = 0; i < N; i++)
			if (egg[i].first <= 0) cnt++;
		if (res < cnt) res = cnt;
		return;
	}
	if (egg[idx].first <= 0) DFS(idx + 1);
	else
	{//���� ���� ��� ������ ���Ƽ� ���� ���� ���� 
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			if (egg[i].first <= 0  || i == idx) continue;
			egg[i].first -= egg[idx].second;
			egg[idx].first -= egg[i].second;
			flag = true;
			DFS(idx + 1);
			egg[i].first += egg[idx].second;
			egg[idx].first += egg[i].second;
		}
		if (!flag) DFS(N);

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> egg[i].first >> egg[i].second;
	if (N == 1)
	{
		cout << 0; 
		return 0;
	}
	DFS(0);
	cout << res;
	return 0;
}
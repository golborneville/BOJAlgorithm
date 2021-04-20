#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int, int>> ls;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int str, end;
		cin >> str >> end;
		ls.push_back({ end, str });
	}
	sort(ls.begin(), ls.end());
	int cmp = ls[0].first;
	int res = 1;
	for (int i = 1; i < ls.size(); i++)
	{
		if (ls[i].second >= cmp)
		{
			res++;
			cmp = ls[i].first;
		}
	}
	cout << res;
	return 0;
}
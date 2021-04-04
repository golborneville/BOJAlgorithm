#include<iostream>
#include <map>
#include <cstring>
#include <vector>
#include<algorithm>
using namespace std;

int r, c, k;
int arr[102][102];
int rowL = 3, colL = 3; //길이 기준이라서 rowL -> 열의 개수임;;;
bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

void atR()
{
	int maxrow = 0;
	for (int i = 0; i < colL; i++)
	{
		map<int, int> cur; //숫자, 횟수
		vector<pair<int, int>> cop;
		for (int j = 0; j < rowL; j++)
		{
			if (arr[i][j] == 0)continue;
			if (cur.find(arr[i][j]) == cur.end())
			{
				cur.insert({ arr[i][j], 0 });
			}
			cur[arr[i][j]] = cur[arr[i][j]] + 1;
		}
		for (auto iter = cur.begin(); iter != cur.end(); iter++)
		{
			cop.push_back({ iter->first, iter->second });
		}
		sort(cop.begin(), cop.end(), cmp);
		memset(arr[i], 0, sizeof(arr[i]));
		int ind = 0;
		for(auto iter = cop.begin(); iter != cop.end(); iter++)
		{
			arr[i][ind++] = iter->first; //숫자
			arr[i][ind++] = iter->second; //횟수
			if (ind == 100) break;
		}
		if (maxrow < ind) maxrow = ind;
	}
	rowL = maxrow;
}
void atC()
{
	int maxcol = 0;
	for (int i = 0; i < rowL; i++)
	{
		map<int, int> cur; //숫자, 횟수
		vector<pair<int, int>> cop;
		for (int j = 0; j < colL; j++)
		{
			if (arr[j][i] == 0)continue;
			if (cur.find(arr[j][i]) == cur.end())
			{
				cur.insert({ arr[j][i], 0 });
			}
			cur[arr[j][i]] = cur[arr[j][i]] + 1;
			arr[j][i] = 0;
		}

		for (auto iter = cur.begin(); iter != cur.end(); iter++)
		{
			cop.push_back({ iter->first, iter->second });
		}
		sort(cop.begin(), cop.end(), cmp);
		int ind = 0;
		for (auto iter = cop.begin(); iter != cop.end(); iter++)
		{
			arr[ind++][i] = iter->first; //숫자
			arr[ind++][i] = iter->second; //횟수
			if (ind == 100) break;
		}
		if (maxcol < ind) maxcol = ind;
	}
	colL = maxcol;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	if (arr[r - 1][c - 1] == k)
	{
		cout << 0;
		return 0;
	}
	for (int t = 1; t <= 100; t++)
	{
		if (colL >= rowL)
			atR();
		else
			atC();
		if (arr[r-1][c-1] == k)
		{
			cout << t;
			return 0;
		}
	}
	
	cout << -1; 
	return 0;
}
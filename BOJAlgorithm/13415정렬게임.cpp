#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int N, K;
int arr[100003], res[1000003];
deque<int> dq; // inc dec 도 같이 비교해주기
int main()
{
	int tmpmax = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int inc, dec;
		cin >> inc >> dec;
		//if (tmpmax < max(inc, dec)) tmpmax = max(inc, dec);
		//inc
		while (!dq.empty() && abs(dq.back()) <= inc)
			dq.pop_back();
		dq.push_back(inc); //inc num insert
		//dec 
		while (!dq.empty() && abs(dq.back()) <= dec)
			dq.pop_back();
		dq.push_back(dec * -1); //dec num insert -> to cmp index , mul -1;

	}
	dq.push_back(0);
	int val = dq.front();
	int order = val < 0 ? -1 : 1;
	val = abs(val);
	int decind = 1;
	int incind = tmpmax = val, sortind = tmpmax;
	dq.pop_front();

	sort(arr + 1, arr + tmpmax + 1);
	for (int i = tmpmax + 1; i <= N; i++)
		res[i] = arr[i];


	while (!dq.empty())
	{
		int indval = abs(dq.front());
		//dq.pop_front();
		if (order == 1)
		{
			//inc
			for (int i = sortind; i > indval; i--)
			{
				res[i] = arr[incind--];
			}
		}
		else
		{
			//dec
			for (int i = sortind; i > indval; i--)
			{
				res[i] = arr[decind++];
			}
		}
		order = dq.front() < 0 ? -1 : 1;
		sortind = indval;
		dq.pop_front();
	}
	for (int i = 1; i <= N; i++)
		cout << res[i] << " ";

	return 0;

}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N, M, res;
int broke[12];
int chk_poss(string str) //O(6)
{ //if fail -> 0
	
	for (int i = 0; i < str.size(); i++)
	{
		if (broke[str[i] - '0'] == 1)
			return 0;
	}
	return 1;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int ind;
		cin >> ind;
		broke[ind] = 1;
		//1이면 사용 X

	}
	/*if (N == 100)
	{
		cout << 0;
		return 0;
	}*/
	if (M == 10) //버튼이 다 망가진 경우
	{
		res = abs(N - 100);
		cout << res; 
		return 0;
	}

	//최소 한개 이상 제대로 된 버튼이 존재 ㅇㅇ

	string str = to_string(N);
	bool fl1 = false, fl2 = false;
	int up, down, diff = abs(N-100);
	int tmp = N;
	//up
	while (tmp <= 999999)
	{
		string cmp = to_string(tmp);
		int ret = chk_poss(cmp);
		if (!ret)
			tmp++;
		else
		{
			fl1 = true;
			up = abs(N - tmp) + cmp.size();
			break;
		}
	}

	tmp = N;
	//down
	while (tmp >= 0)
	{
		string cmp = to_string(tmp);
		int ret = chk_poss(cmp);
		if (!ret)
			tmp--;
		else
		{
			fl2 = true;
			down = abs(tmp - N) + cmp.size();
			break;
		}
	}
	if (!fl1)
		res = down;
	else if (!fl2)
		res = up;
	else
		res = min(up, down);
	res = min(diff, res);
	cout << res;
	return 0;

}
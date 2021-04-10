#include<iostream>
#include<string>
using namespace std;

int N;
int poss_num[2000005];
void isPrime()
{
	for (int i = 2; i <= 2000000; i++)
		poss_num[i] = 1;

	for (int i = 2; i * i <= 2000000; i++)
	{
		if(poss_num[i])
			for (int j = i * i; j <= 2000000; j += i)
				poss_num[j] = 0;
	}
}
void isPelindrop()
{
	for (int i = N; i < 2000000; i++)
	{
		if (poss_num[i])
		{
			string str = to_string(i);
			bool flag = true;
			for (int j = 0; j < str.size()/2; j++)
			{
				if (str[j] != str[str.size() - 1 - j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				cout << i;
				return;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	isPrime();
	isPelindrop();
	return 0;
}
#include<iostream>
#include <string>
#include<queue>
using namespace std;
int res = 0;
queue<int> ind;

int failArr[1000003];

void failureFuction(string P)
{
	failArr[0] = 0;
	int i = 1, j = 0;
	while (P.size() > i)
	{
		if (P[i] == P[j])
		{ // we have matched j+1 chars
			failArr[i] = j + 1;
			i++; j++;
		}
		else if(j > 0)
		{
			j = failArr[j - 1]; // use tha failure function to shift to P
		}
		else
		{
			failArr[i] = 0; //no match at all
			i++;
		}
	}
}
void KMP(string T, string P)
{
	//init
	failureFuction(P);
	int i = 0, j = 0;
	while (i < T.size()) //n is T.size(), m is P.size()
	{
		if (T[i] == P[j])
		{ // keep goin'
			if (j == P.size() - 1) // 마지막 문자 까지 일치 -> FOUND!
			{ 
				res++;
				ind.push(i - j + 1); // 기존엔return i - j;임
			}
			// keep goin' the cmp
			i++; j++;
		}
		else
		{ // not a math at all-> need to jump
			if (j > 0)
				j = failArr[j - 1]; // jump!
			else
				i++;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string text, pattern;
	getline(cin, text);
	getline(cin, pattern);
	KMP(text, pattern);
	cout << res << "\n";
	while (!ind.empty())
	{
		cout << ind.front() << " ";
		ind.pop();
	}
}
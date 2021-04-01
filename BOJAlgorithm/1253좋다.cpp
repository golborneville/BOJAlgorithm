#include<iostream>
#include<algorithm>
using namespace std;


int N;
long long int numArr[2003];
bool findSum(int idx)
{
	int left = 0; int right = N - 1; //이분 탐색 시간 복잡도 가능
	int val = numArr[idx];
	while (left < right)
	{
		int sumtmp = numArr[left] + numArr[right];
		if (sumtmp < val)
			left++;
		else if (sumtmp > val)
			right--;
		else if (sumtmp == val)
		{
			if(left != idx && right != idx)
				return true;
			else if (left == idx || right == idx)
			{
				if (left == idx) left++;
				if (right == idx) right--;
			}
		}
	}
	return false;
}
int main()
{
	
	int totalcnt = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; 
	for (int i = 0; i < N; i++)
		cin >> numArr[i];
	sort(numArr, numArr + N);
	for (int i = 0; i < N; i++)
	{
		bool res = findSum(i);
		if (res) totalcnt++;
	}
	cout << totalcnt;
	return 0;
}
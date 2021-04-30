#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int chk_succ_zero(int mid, vector<int>& stones)
{
	int zz = 0;
	int mx = 0;
	for (int i = 0; i<stones.size(); i++)
	{
		if (mid >= stones[i])
			zz++;
		else
		{
			if (mx < zz) mx = zz;
			zz = 0;
		}
	}
	if (mx < zz) mx = zz;
	return mx;
}
int solution(vector<int> stones, int k) {
	int answer = 0;
	int lf = 1;
	int rt = *max_element(stones.begin(), stones.end());
	while (lf < rt)
	{
		int mid = (lf + rt) / 2;
		int res = chk_succ_zero(mid, stones);
		if (res >= k)//여기 부등호 등호 유무랑 
			rt = mid; //여기 -1 에서 
		else
			lf = mid + 1; //+1 로 바꿈 차이..?
	}
	answer = lf;
	return answer;
}
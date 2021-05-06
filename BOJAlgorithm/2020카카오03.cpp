#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int cnt[100003];
int current = 0;
map<string, int> jw; //cnt 에서 인덱스 값...
struct info
{
	int len;
	int src, dst;
};
vector<info> cand;
bool cmp(info a, info b)
{
	if (a.len != b.len) return a.len < b.len;
	return a.src < b.src;
}
vector<int> solution(vector<string> gems) {
	vector<int> answer;
	for (int i = 0; i<gems.size(); i++)
	{
		if (jw[gems[i]] == 0)
			jw[gems[i]] = i;
	}
	int ind = 0;
	for (int i = 0; i<gems.size(); i++)
	{
		if (!cnt[jw[gems[i]]])
		{
			//first time 
			current++;
			cnt[jw[gems[i]]]++;
			while (current >= jw.size() && ind <= i)
			{
				if (current == jw.size())
					cand.push_back({ i - ind, ind + 1, i + 1 });
				cnt[jw[gems[ind]]]--;
				if (!cnt[jw[gems[ind]]])
					current--;
				ind++;
			}
		}
		else
		{
			cnt[jw[gems[i]]]++;
		}
	}
	sort(cand.begin(), cand.end(), cmp);
	answer.push_back(cand.front().src);
	answer.push_back(cand.front().dst);
	return answer;
}
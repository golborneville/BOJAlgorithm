#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int BN, UN;
//int res = 0;
int indexarr[9];
bool chk[9];
set<set<string>> result;
vector<string> g_user_id;
vector<string> g_banned_id;
bool compareID(string usr, string ban)
{
	int p1 = 0;
	if (usr.size() != ban.size()) return false;
	for (int p2 = 0; p2<ban.size(); p2++)
	{
		if (usr[p1] == ban[p2] || ban[p2] == '*')
		{
			p1++;
			continue;
		}
		else
			return false;
	}
	return true;
}
void rec(int depth, int ind)
{
	if (depth == BN)
	{
		//end condition
		//chk possibility & res++;
		bool flag = true;
		for (int i = 0; i<BN; i++)
		{
			bool rt = compareID(g_user_id[indexarr[i]], g_banned_id[i]);
			if (!rt)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
			return;
		else
		{
			set<string> tmpvec;
			for (int i = 0; i<BN; i++)
			{
				tmpvec.insert(g_user_id[indexarr[i]]);
			}
			result.insert(tmpvec);
		}
		return;
	}
	for (int i = 0; i<UN; i++)
	{
		if (chk[i])continue;
		chk[i] = true;
		indexarr[depth] = i;
		rec(depth + 1, i + 1);
		chk[i] = false;
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	BN = banned_id.size();
	UN = user_id.size();
	g_user_id = user_id;
	g_banned_id = banned_id;
	rec(0, 0);
	answer = result.size();
	return answer;
}
int main() {
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
	solution(user_id, banned_id);

	return 0;
}
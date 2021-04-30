#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int N = 0;
vector<int> arr[502];
bool chk[100002];
void split_str(string s)
{
	string tmpstr = "";
	//vector<int> arr[502]; //사이즈로 인덱스 구할것
	vector<int> tmp;
	bool in = false;

	for (int i = 1; i<s.size() - 1; i++)
	{
		if (s[i] == '{')
		{
			in = true;
		}
		else if (s[i] == ',')
		{
			if (in)
			{
				tmp.push_back(stoi(tmpstr));
				tmpstr = "";
			}
		}
		else if (s[i] == '}')
		{
			tmp.push_back(stoi(tmpstr));
			tmpstr = "";
			in = false;
			// sort(tmp.begin(), tmp.end());
			if (N <tmp.size()) N = tmp.size();
			for (int j = 0; j<tmp.size(); j++)
				arr[tmp.size()].push_back(tmp[j]);
			tmp.clear();
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			tmpstr += s[i];
		}
	}
	//return arr;
}
vector<int> solution(string s) {
	vector<int> answer;
	split_str(s);
	int ind = 0;
	for (int i = 1; i <= N; i++)
	{
		//answer.push_back(arr[i][ind++]);
		for (int j = 0; j<arr[i].size(); j++)
		{
			// cout << arr[i][j] << " "; 
			if (!chk[arr[i][j]])
			{
				answer.push_back(arr[i][j]);
				chk[arr[i][j]] = true;
				break;
			}
		}
		// cout << "\n";
	}
	return answer;
}
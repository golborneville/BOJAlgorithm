#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	pair<int, int> rt = { 3,2 }, lf = { 3,0 };
	for (int i = 0; i<numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer += "L";
			lf = { numbers[i] / 3, 0 };
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer += "R";
			rt = { numbers[i] / 4, 2 };
		}
		else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0)
		{
			if (numbers[i] == 0) numbers[i] = 10;
			pair<int, int> tmp = { numbers[i] / 3, 1 };
			if (abs(lf.first - tmp.first) + abs(lf.second - tmp.second) < abs(rt.first - tmp.first) + abs(rt.second - tmp.second))
			{
				answer += "L";
				lf = tmp;
			}
			else if (abs(lf.first - tmp.first) + abs(lf.second - tmp.second) > abs(rt.first - tmp.first) + abs(rt.second - tmp.second))
			{
				answer += "R";
				rt = tmp;
			}
			else
			{
				if (hand == "left")
				{
					answer += "L";
					lf = tmp;
				}
				else if (hand == "right")
				{
					answer += "R";
					rt = tmp;
				}
			}
		}
	}
	return answer;
}
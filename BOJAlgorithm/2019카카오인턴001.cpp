#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> st;

	for (int i = 0; i<moves.size(); i++)
	{
		bool flag = false;
		int outnum;
		int line = moves[i] - 1;
		for (int j = 0; j<board.size(); j++)
		{
			if (board[j][line])
			{
				flag = true;
				outnum = board[j][line];
				board[j][line] = 0;
				break;
			}
		}
		if (flag)
		{
			if (!st.empty())
			{
				if (st.top() == outnum)
				{
					answer += 2;
					st.pop();
				}
				else
				{
					st.push(outnum);
				}
			}
			else
				st.push(outnum);

		}
	}

	return answer;
}
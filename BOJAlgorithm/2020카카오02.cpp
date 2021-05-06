#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

long long solution(string expression) {
	long long answer = 0;
	vector<long long> origin;
	vector<char> op;
	string num = "";
	for (int i = 0; i<expression.size(); i++)
	{
		if (!(expression[i] == '+' || expression[i] == '*' || expression[i] == '-'))
		{
			num += expression[i];
		}
		else
		{
			long long val = stoi(num);
			num = "";
			//val로 뭐하냐
			origin.push_back(val);
			op.push_back(expression[i]);
		}
	}
	long long val = stoi(num);
	//val로 뭐하냐
	origin.push_back(val);
	int order[3] = { 1,2,3 };
	do {
		deque<long long> operand;
		deque<char> opst;

		deque<long long> operand2;
		deque<char> opst2;

		deque<long long> operand3;
		deque<char> opst3;

		operand.push_back(origin[0]);
		for (int j = 0; j<op.size(); j++)
		{//연산자 기준 (사이즈 하나 작음)
			long long n2 = origin[j + 1];
			char pp = op[j];
			long long n1 = operand.back();
			if (pp == '+' && order[0] == 1)
			{
				operand.pop_back();
				operand.push_back(n1 + n2);
			}
			else if (pp == '-' && order[0] == 2)
			{
				operand.pop_back();
				operand.push_back(n1 - n2);
			}
			else if (pp == '*' && order[0] == 3)
			{
				operand.pop_back();
				operand.push_back(n1 * n2);
			}
			else
			{
				operand.push_back(n2);
				opst.push_back(pp);
			}
		}
		operand2.push_back(operand.front());
		operand.pop_front();
		while (!opst.empty())
		{
			long long n1 = operand2.back();
			//operand.pop();
			char pp = opst.front();
			opst.pop_front();
			long long n2 = operand.front();
			operand.pop_front();
			if (pp == '+' && order[1] == 1)
			{
				operand2.pop_back();
				operand2.push_back(n1 + n2);
			}
			else if (pp == '-' && order[1] == 2)
			{
				operand2.pop_back();
				operand2.push_back(n1 - n2);
			}
			else if (pp == '*' && order[1] == 3)
			{
				operand2.pop_back();
				operand2.push_back(n1 * n2);
			}
			else
			{
				operand2.push_back(n2);
				opst2.push_back(pp);
			}
		}

		operand3.push_back(operand2.front());
		operand2.pop_front();
		while (!opst2.empty())
		{
			long long n1 = operand3.back();
			//operand.pop();
			char pp = opst2.front();
			opst2.pop_front();
			long long n2 = operand2.front();
			operand2.pop_front();
			if (pp == '+' && order[2] == 1)
			{
				operand3.pop_back();
				operand3.push_back(n1 + n2);
			}
			else if (pp == '-' && order[2] == 2)
			{
				operand3.pop_back();
				operand3.push_back(n1 - n2);
			}
			else if (pp == '*' && order[2] == 3)
			{
				operand3.pop_back();
				operand3.push_back(n1 * n2);
			}
			else
			{
				operand3.push_back(n2);
				opst3.push_back(pp);
			}
		}
		long long tmpres = abs(operand3.front());
		if (answer < tmpres) answer = tmpres;

	} while (next_permutation(order, order + 3));

	return answer;
}

int main()
{
	cout << solution("100-200*300-500+20") << "\n";
	cout << solution("50 * 6 - 3 * 2") << "\n";

}
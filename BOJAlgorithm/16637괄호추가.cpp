#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

vector<char> num;
vector<char> oper;
bool choose[12];
bool usednum[12];
int main() {

	deque<long long int> qunum;
	queue<char> quop;
	string ea;
	int len, T;

	cin >> T >> ea;
	long long int result = 0, finalresult = 0;
	for (int i = 0; i < T; i++) {
		if (i % 2 == 0) {
			num.push_back(ea[i]);
		}
		else
		{
			oper.push_back(ea[i]);
		}
	}
	len = oper.size();
	//int choicelist[12];
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j < i; j++) {
			choose[len - j-1] = true;// 연산자 선택(괄호 할 애들)
		}
		do {
			//연속된 연산자 아닌지 체크 
			bool chkcon = false;
			for (int j = 1; j < len; j++) {
				if (choose[j-1] == true && choose[j] == true) {
					chkcon = true;
				}
				if (choose[j + 1] == true && choose[j] == true) {
					chkcon = true;
				}
			}
			if (chkcon) continue; // 연속된 연산자 (중첩 괄호)
			
			//선택된 괄호에 대해 미리 계산 해서 큐에 넣기
			for (int j = 0; j < len; j++) {
				int re;
				if (choose[j]) {
					//연산자 기준 괄호 ->우선 계산 (j, j+1)
					switch (oper[j])
					{
					case '+' :
						re = (num[j] - '0') + (num[j + 1] - '0');
						
						break;
					case '-':
						re = (num[j] - '0') - (num[j + 1] - '0');
						break;
					case '*':
						re = (num[j] - '0') * (num[j + 1] - '0');
						break;
					}
					qunum.push_back(re);
					usednum[j] = true;
					usednum[j + 1] = true;
					
				}
				else {
					//그냥 (괄호X)
					if (!usednum[j]) {
						qunum.push_back(num[j] - '0');
						usednum[j] = true;
					}
					quop.push(oper[j]);
				}

			}
			if (!usednum[len]) {
				//마지막에 괄호 아니여서 마지막 숫자 가 덩그러니...버려짐...
				usednum[len] = true;
				qunum.push_back(num[len] - '0');
			}
			//순차적으로 계산만 해주면 끝!
			while (!quop.empty()) {
				int n1 = qunum.front();
				qunum.pop_front();
				int n2 = qunum.front();
				qunum.pop_front();
				char op = quop.front();
				quop.pop();
				
				switch (op)
				{
				case '+':
					result = (n1 + n2);
					break;
				case '-':
					result = (n1 - n2);
					break;
				case '*':
					result = (n1 * n2);
					break;
				}
				qunum.push_front(result);

			}
			if (finalresult < qunum.front()) {
				finalresult = qunum.front();
			}
			qunum.pop_front();

			//초기화,.....잊지말자...
			memset(usednum, false, sizeof(usednum));

		} while (next_permutation(choose, choose + len));
		
		memset(choose, false, sizeof(choose));


	}
	cout << finalresult;
	return 0;



}
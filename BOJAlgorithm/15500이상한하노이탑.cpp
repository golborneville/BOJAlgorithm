#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
//솔직히 하노이 탑은 잘 모르곘네요;ㅁ;

int chk1[125], chk2[125]; //3번째는 순차적으로 쌓일 예정이라 따로 체크 할 필요 X
stack<int> t1, t2;
vector<string> res;
int numres = 0;
void hanoi(int num, int stdN)
{
	int move_val;
	switch (num)
	{
	case 1: //1 to (2 or 3)
		while (t1.top() < stdN)
		{	//1 to 2(not target)
			move_val = t1.top();
			t1.pop();
			chk1[move_val] = 0;
			t2.push(move_val);
			chk2[move_val] = 1;
			numres++;
			res.push_back("1 2");
		} 
		//top == N
		move_val = t1.top();
		t1.pop();
		chk1[move_val] = 0;
		numres++;
		res.push_back("1 3");
		//N--;
		break;
	case 2: //2 to (1 or 3)
		while (t2.top() < stdN)
		{	//2 to 1(not target)
			move_val = t2.top();
			t2.pop();
			chk2[move_val] = 0;
			t1.push(move_val);
			chk1[move_val] = 1;
			numres++;
			res.push_back("2 1");
		}
		//top == N
		move_val = t2.top();
		t2.pop();
		chk2[move_val] = 0;
		numres++;
		res.push_back("2 3");
		//N--;
		break;
	}

}
int main() {
	int ind;
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ind;
		chk1[ind] = 1;
		t1.push(ind);
	}

	//while (N)
	for(int i=N; i>0; i--)
	{
		if (chk1[i])
			hanoi(1, i);
		else if (chk2[i])
			hanoi(2, i);
	}
	cout << numres << "\n";
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << "\n";
	return 0;
}

//#include <iostream>
//#include <stack>
//#include <vector>
//#include <bitset>
//using namespace std;
//
//stack<int> l1, l2;
//bitset<12346> b1, b2;
//vector<string> answer;
//int cnt;
//int N;
//
//void find(int i) {
//	int move;
//	switch (i) {
//	case 1:
//		while ((move = l1.top()) < N)
//		{
//			l1.pop();
//			l2.push(move);
//			b1.reset(move);
//			b2.set(move);
//			answer.push_back("1 2\n");
//			cnt++;
//		}
//		l1.pop();
//		b1.reset(move);
//		N--;
//		answer.push_back("1 3\n");
//		cnt++;
//		break;
//	case 2:
//		while ((move = l2.top()) < N)
//		{
//			l2.pop();
//			l1.push(move);
//			b1.set(move);
//			b2.reset(move);
//			answer.push_back("2 1\n");
//			cnt++;
//		}
//		l2.pop();
//		b2.reset(move);
//		N--;
//		answer.push_back("2 3\n");
//		cnt++;
//		break;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int n;
//		cin >> n;
//		l1.push(n);
//		b1.set(n);
//	}
//	while (N > 0)
//		if (b1[N])
//			find(1);
//		else if (b2[N])
//			find(2);
//	cout << cnt << endl;
//	for (int i = 0; i < cnt; i++)
//		cout << answer[i];
//}
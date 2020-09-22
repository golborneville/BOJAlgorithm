#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<char> survive;
	stack<char> prebomb; // ㅠㅗㄱ발인지 확인용 스택
	string sent, bomb;
	string total = "";
	cin >> sent >> bomb;
	bool explode = false;
	int into = 0;
	int bomb_ind = bomb.size() - 2; // start as second to last index 
	if (bomb.size() < 2) {
		//bobm size 1
		bomb_ind = 0;
	}
	for (int i = 0; i < sent.size(); i++) {
		if (sent[i] != bomb[bomb.size() - 1]) {
			//폭발 문자의 마지막 char과 일치하지 않을 경우 스택에 해당 인덱스 push
			survive.push(sent[i]);
		}
		else {
			if (bomb.size() != 1) {
				prebomb.push(sent[i]);
				into++;
			}
			//마지막 문자랑 일치해서 이전꺼를 확인 하는 작업 필요
			//while (survive.top() == bomb[bomb_ind]) {
			while (true) {
				if(!survive.empty()){
					if (survive.top() == bomb[bomb_ind]) {
						prebomb.push(survive.top());
						survive.pop();
						into++;
						if (bomb_ind == 0) {
							explode = true;
							break;
						}
						bomb_ind--;
					}
					else {
						break;
					}
				}
				else {
					//survive empty
					break;
				}

			}
			if (explode) {
				//bomb! 
				explode = false;
				bomb_ind = bomb.size() - 2;
				if (bomb.size() < 2) {
					//bobm size 1
					bomb_ind = 0;
				}
				into = 0;

			}
			else {
				//not a match -> recover
				//int epoc = (bomb.size() - 1) - bomb_ind;
				while (into--) {
					//if (!prebomb.empty()) {
						survive.push(prebomb.top());
						prebomb.pop();
					//}
				}
				into = 0;
				bomb_ind = bomb.size() - 2;
				if (bomb.size() < 2) {
					//bobm size 1
					bomb_ind = 0;
				}
			}
			
		}
	}

	
	while (!survive.empty()) {
		total += survive.top();
		survive.pop();
	}
	if (total == "") {
		cout << "FRULA";
		return 0;
	}
	for (int i = total.size() - 1; i >= 0; i--) {
		cout << total[i];
	}
	return 0;
}
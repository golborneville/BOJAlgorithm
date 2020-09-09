#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, string>> history; // userid - state(enter, leave, change)
	map<string, string> nick; // usrid - nickname
	for (int i = 0; i < record.size(); i++) {
		string state = record[i];
		vector<string> split_string; // enter/leave/change - usrid - nickname
		string tmp = "";
		for (int j = 0; j<state.size(); j++) { //문장 단어별로 잘라서 벡터에 넣기
			if (state[j] != ' ') {
				tmp += state[j];
			}
			else {
				split_string.push_back(tmp);
				tmp = "";
			}
		}
		split_string.push_back(tmp); //nickname 추가 과정
		history.push_back(make_pair(split_string[1], split_string[0])); //userid - state
		if (split_string[0] == "Enter") {
			nick[split_string[1]] = split_string[2]; //map[key] =value;
		}
		else if (split_string[0] == "Change") {
			nick[split_string[1]] = split_string[2];
		}

	}
	for (int i = 0; i < history.size(); i++) {
		string usrid = history[i].first;
		string usrstate = history[i].second;
		string usrname = nick[usrid];
		if (usrstate == "Enter") {
			string final_state = usrname + "님이 들어왔습니다.";
			answer.push_back(final_state);
		}
		else if (usrstate == "Leave") {
			string final_state = usrname + "님이 나갔습니다.";
			answer.push_back(final_state);
		}
	}

	return answer;
}
int main() {
	vector<string> rec;
	rec.push_back("Enter uid1234 Muzi");
	rec.push_back("Enter uid4567 Prodo");
	rec.push_back("Leave uid1234");
	rec.push_back("Enter uid1234 Prodo");
	rec.push_back("Change uid4567 Ryan");
	solution(rec);
}
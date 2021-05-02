#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<long long, long long> room_map;
long long findNextRoom(long long num)
{
	cout << num << '\n';
	if (room_map[num] == 0)
		return num;
	else
	{
		room_map[num] = findNextRoom(room_map[num]);
		return room_map[num];
	}

}
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (int i = 0; i<room_number.size(); i++)
	{
		if (room_map[room_number[i]] == 0)
		{//first time
			answer.push_back(room_number[i]);
			cout << "firsttime: \n";
			room_map[room_number[i]] = findNextRoom(room_number[i] + 1);
			cout << "ENDfirsttime\n";
		}
		else
		{
			cout << "DUPtime: \n";
			long long resval = findNextRoom(room_number[i]);
			cout << "ENDDUPtime\n\n UDPATE: \n\n";
			answer.push_back(resval);
			room_map[resval] = findNextRoom(resval + 1);
			cout << "ENDUPDATEtime\n";
		}
	}
	return answer;
}

int main()
{
	vector<long long> rn = { 1,3,4,1,3,1 };
	vector<long long> sss = solution(10, rn);
}
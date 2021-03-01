#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

string arr[12];
int prio[26];//A ~ Z
int val_char[26]; //�� ĳ���Ϳ� ���� �Ǵ� ������ �� 0~ 9 -> ���� �ִ� 10���� ����
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	
	int maxsum = -987654321;
	map<char, int> alphabet;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < arr[i].length(); j++) {
			prio[arr[i][j] - 'A'] += pow(10, arr[i].length() - j - 1);
		}
	}
	vector<pair<int, int>> line; //�켱���� ,  ���� �ε��� 0~25
	for (int i = 0; i < 26; i++) {
		if (prio[i] != 0) {
			line.push_back({ prio[i], i});
		}
	}
	sort(line.begin(), line.end(), cmp);
	int res = 0;
	int cp = 9;
	for (int i = 0; i < line.size(); i++) {
		val_char[line[i].second] = cp--;
	}
	for (int i = 0; i < N; i++) {
		string tmp = "";
		for (int j = 0; j < arr[i].length(); j++) {
			tmp += val_char[arr[i][j] - 'A'] + '0';
		}
		res += stoi(tmp);
	}
	cout << res;
	return 0;
}
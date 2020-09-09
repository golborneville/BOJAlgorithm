#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;


int stage_cnt[2][505];
bool cmpFunc(const pair<int, float> &a, const pair<int, float> &b)
{
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, float>> cmp;
	memset(stage_cnt, 0, sizeof(stage_cnt));
	for (int i = 0; i < stages.size(); i++) {
		stage_cnt[0][stages[i]] += 1;
	}
	stage_cnt[1][1] = stages.size();
	for (int i = 2; i <= N; i++) {
		stage_cnt[1][i] = stage_cnt[1][i - 1] - stage_cnt[0][i - 1];
	}
	for (int i = 1; i < N; i++) {
		cmp.push_back({ i,float(stage_cnt[0][i]) / float(stage_cnt[1][i]) });
	}
	cmp.push_back({ N, 0 });
	sort(cmp.begin(), cmp.end(), cmpFunc);
	for (int i = 0; i < N; i++) {
		answer.push_back(cmp[i].first);
	}
	return answer;
}
int main() {
	vector<int> a;
	int aa[5] = { 4,4,4,4,4 };
	for(int i = 0; i < 5; i++){
		a.push_back(aa[i]);
	}
	solution(4, a);
}
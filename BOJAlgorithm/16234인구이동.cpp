#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, L, R;
int nation[53][53];
bool chk[53][53];
int popMov = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> unionNation[2502];
queue<pair<int, int>> qu;
int get_union_area(int x, int y, int ind) { //매개변수는 벡터 인덱스임
	int ff = 0;
	qu.push({ x,y });
	chk[x][y] = true;
	unionNation[ind].push_back({ x,y });
	while (!qu.empty()) {
		pair<int, int> node = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nx = node.first + dx[i]; int ny = node.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			int diff = abs(nation[node.first][node.second] - nation[nx][ny]);
			if (!chk[nx][ny] && diff >= L && diff <= R) {
				ff = 1;
				qu.push({ nx,ny });
				chk[nx][ny] = true;
				unionNation[ind].push_back({ nx,ny });
			}
		}
	}
	return ff;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> nation[i][j];
	while (true)
	{
		bool flag = 0; //인구이동이 일어나는지 안일어나는지 플래그
		int ind = 0;
		//1. 국경선 공유하는 국가끼리 인구수 차이 구하고 -> L R 에 비교하기
		//2. 범위 이내면 국경선열기 
		//3. 모든 국경선 여는거 끝난 뒤에 인구이동하기
		
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			if (!chk[i][j]) {
				bool tmp = get_union_area(i, j, ind);
				ind++;
				if (tmp) flag = 1;
			}
		}
		//	3-1) 열린 국경선 있으면 인구이동 횟수 popMov++; 해주기
		if (flag) popMov++;
		//	3-2) 열린 국경선이 없으면 while문 벗어나기 
		else break;
		//4. 같은 연합군 내에 (인구수 총합) / (연합군 내 국가 개수) 해서 분배하기
		for (int i = 0; i < ind; i++) {
			int sumPOP = 0;
			for (int j = 0; j < unionNation[i].size(); j++) {
				sumPOP += nation[unionNation[i][j].first][unionNation[i][j].second];
			}
			sumPOP /= unionNation[i].size();
			for (int j = 0; j < unionNation[i].size(); j++) {
				nation[unionNation[i][j].first][unionNation[i][j].second] = sumPOP;
			}
		}
		//5. 국경선 닫기
		//##벡터 초기화 필요##
		for (int i = 0; i < ind; i++) {
			unionNation[i].clear();
		}
		memset(chk, false, sizeof(chk));
	}
	cout << popMov;
	
}
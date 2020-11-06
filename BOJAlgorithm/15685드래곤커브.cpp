#include<iostream>
#include<vector>
using namespace std;
int N, x, y, d, g;
bool arr[103][103];
//vector<pair<int, int>> pos;
pair<int, int> stand;
pair<int, int> rotate(pair<int, int> com, pair<int, int> standard) { //회전 되는 좌표, 기준 좌표 매개변수 통해 회전 이후 좌표 반환
	pair<int, int> parr = { standard.first * -1, standard.second*-1 }; //평행이동 변환
	pair<int, int> comTMP = { com.first + parr.first, com.second + parr.second }; // 회전 좌표 ( 평행 이동 이후)
	comTMP = { comTMP.second * -1, comTMP.first }; //회전 변환( 시계방향 90도)
	comTMP = { comTMP.first - parr.first, comTMP.second - parr.second };
	return comTMP;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> x >> y >> d >> g; // 시작점(x,y) / 시작방향 / 세대
		vector<pair<int, int>> pos;
		stand = { x,y };
		pos.push_back(stand);
		switch (d)
		{
		case 0:
			pos.push_back({ stand.first + 1 , stand.second });
			break;
		case 1:
			pos.push_back({ stand.first  , stand.second - 1 });
			break;
		case 2:
			pos.push_back({ stand.first - 1 , stand.second });
			break;
		case 3:
			pos.push_back({ stand.first , stand.second + 1 });
			break;
		} //0세대 까지 완료 (무조건 사이즈 2)
		for (int i = 0; i < g; i++) {
			//세대수 만큼 반복작업
			int st_ind = pos.size() - 1;
			for (int i = pos.size() - 2; i >= 0; i--) {
				pos.push_back(rotate(pos[i], pos[st_ind]));  //회전 - 기준점(가장 마지막)
			}
		}
		while (!pos.empty()) {
			arr[pos.back().first][pos.back().second] = true;
			pos.pop_back();
		}

	}
	int answer = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) answer++;
		}
	}
	cout << answer;
	return 0;
}
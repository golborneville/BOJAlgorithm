#include<iostream> //15683 감시 임 파일 이름 나중에 바꿀것
#include<vector>
using namespace std;

#define INF 987654321
int N, M;
int resMin = INF;
vector<pair<int, pair<int, int>>> cctvs; // {type, {pos x, pos y}};
int room[66][66];
int chk[66][66];
//int num_cctvCnt[6]; // 1~5
vector<pair<int, int>> one[4] = { {{1,0}}, {{0,-1}}, {{-1,0}}, {{0,1}} };
vector<pair<int, int>> two[2] = { {{-1,0}, {1,0}}, {{0,1}, {0,-1}} };
vector<pair<int, int>> three[4] = { {{-1,0},{0,1}} , { {0,1}, {1,0} }, { {1,0}, {0,-1} }, { {0,-1}, {-1,0 } } };
vector<pair<int, int>> four[4] = { { { -1,0 },{ 0,1 },{0,-1} } ,{ { 0,1 },{ 1,0 },{-1,0} },{ { 1,0 },{ 0,-1 },{0,1} },{ { 0,-1 },{ -1,0 }, {1,0} } };
vector<pair<int, int>> five = {{ -1,0 },{ 1,0 },{ 0,-1 }, {0,1}};
bool chk_as_seen(int tvnum, int casenum, pair<int,int> pos) {
	int nx, ny;
	switch (tvnum)
	{
	case 1:
		nx = pos.first; ny = pos.second;
		while (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			if (chk[nx][ny]!=6)
			{
				chk[nx][ny] = 1;
				nx += one[casenum][0].first;
				ny += one[casenum][0].second;
			}
			else {
				break;
			}
		}
		break;
	case 2:
		if (casenum > 1) return false;
		for (int k = 0; k < 2; k++) {
			nx = pos.first; ny = pos.second;
			while (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{ 
				if (chk[nx][ny]!=6 || ((nx == pos.first) &&(ny == pos.second)))
				{
					chk[nx][ny] = 1;
					nx += two[casenum][k].first;
					ny += two[casenum][k].second;
				}
				else {
					break;
				}
			}

		}
		break;
	case 3:
		for (int k = 0; k < 2; k++) {
			nx = pos.first; ny = pos.second;
			while (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (chk[nx][ny]!=6 || ((nx == pos.first) && (ny == pos.second)))
				{
					chk[nx][ny] = 1;
					nx += three[casenum][k].first;
					ny += three[casenum][k].second;
				}
				else {
					break;
				}
			}
		}
		break;
	case 4:
		for (int k = 0; k < 3; k++) {
			nx = pos.first; ny = pos.second;
			while (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (chk[nx][ny]!=6 || ((nx == pos.first) && (ny == pos.second)))
				{
					chk[nx][ny] = 1;
					nx += four[casenum][k].first;
					ny += four[casenum][k].second;
				}
				else {
					break;
				}
			}
		}
		break;
	case 5:
		if (casenum > 0) return false;
		for (int k = 0; k < 4; k++) {
			nx = pos.first; ny = pos.second;
			while (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (chk[nx][ny]!=6 || ((nx == pos.first) && (ny == pos.second)))
				{
					chk[nx][ny] = 1;
					nx += five[k].first;
					ny += five[k].second;
				}
				else {
					break;
				}
			}
		}
		break;
	}
	return true;
}
int  chkCCTVArea(int *arr) {
	//해당 경우에
	//1. 씨씨티비 관측 경우 체크
	//cctv num val is in cctvs(vec)
	//each case is in arr (same index)
	for (int i = 0; i < cctvs.size(); i++) {
		int tvnum = cctvs[i].first;
		int casenum = arr[i];
		bool res = chk_as_seen(tvnum, casenum, cctvs[i].second);
		if (!res) {
			//not appropriate
			return INF; //return FAILURE
		}
	}
	//2. 사각지대 크기 구하기 // 1로 된건 체크(씨씨티비 포함) , 6으로 된건 벽
	int cnt_non = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!chk[i][j]) cnt_non++;
		}
	}
	return cnt_non;

}
void allCaseRec(int *arr, int nth) { // 8개중 몇번째 씨씨티비인지, 0~3 중에 (4ㄱ지중에) 몇번째인지 
	if (nth == cctvs.size()) {
		//종료조건
		//init chk[]
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (room[i][j] == 6) chk[i][j] = 6;
				else chk[i][j] = 0;
			}
		}
		//use array and cal
		int tmpMin = chkCCTVArea(arr);

		//update min val
		if (resMin > tmpMin) resMin = tmpMin;
		return;
	}

	//cctvs
	for (int c = 0; c < 4; c++) {
		arr[nth] = c;
		allCaseRec(arr, nth + 1);
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[9];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
			if (room[i][j] > 0 && room[i][j] < 6) { 
				cctvs.push_back({ room[i][j], {i, j} }); 
				//num_cctvCnt[room[i][j]]++;
			}
			//if (room[i][j] != 0) chk[i][j] = 1;
		}
	}
	allCaseRec(arr, 0);
	//모든 경우의 수 
	//1번 : 4가지  && 2번 : 2가지 && 3번: 4가지 && 4번 : 4가지 && 5번 : 1가지
	cout << resMin;
	return 0;
}

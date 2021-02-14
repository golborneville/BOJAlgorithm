#include<iostream>
using namespace std;

int sand[502][502];
int N;
pair<int, int> curr; //current position
int pmx[4] = { 0,1,0,-1 };
int pmy[4] = { -1,0,1,0 };
int side = 1;
int pmind = 0; // 0 left  1 down  2 right  3 up 
pair<int, int> leftpos[10] = { {-2,0},{-1,-1},{-1,0}, {-1,1}, {0,-2},{1,-1},{1,0}, {1,1}, {2,0}, {0,-1} };//y기준 상대좌표      마지막은알파 좌표자리
pair<int, int> rightpos[10] = { { -2,0 },{ -1,-1 },{ -1,0 },{ -1,1 },{ 0,2 },{ 1,-1 },{ 1,0 },{ 1,1 },{ 2,0 },{ 0,1 } };
pair<int, int> uppos[10] = { {-2,0},{ -1,-1 },{ -1,1 },{ 0,-2 },{0,-1}, {0,1}, {0,2}, {1,-1}, {1,1}, {-1,0} };
pair<int, int> downpos[10] = { { -1,-1 },{ -1,1 },{ 0,-2 },{ 0,-1 },{ 0,1 },{ 0,2 },{ 1,-1 },{ 1,1 },{ 2,0 },{1,0} };

//각자 인덱스에 맞게 퍼센트
int leftper[9] = {2,10,7,1,5,10,7,1,2};
int rightper[9] = {2,1,7,10,5,1,7,10,2};
int upper[9] = {5,10,10,2,7,7,2,1,1};
int downper[9] = {1,1,2,7,7,2,10,10,5};

int boundaryover = 0;
int cntside = 0;
void spreadSand(int move, int direction) {
	int alpha = 0;
	int nx, ny, caltmp;

	switch (direction)
	{
	case 0:
		//left
		for (int i = 0; i < 9; i++) {
			caltmp = leftper[i] * move / 100;
			alpha += caltmp;
			nx = curr.first + leftpos[i].first; ny = curr.second + leftpos[i].second;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				boundaryover += caltmp;

			}
			else {
				sand[nx][ny] += caltmp;
			}
		}
		//alpha calculate
		nx = curr.first + leftpos[9].first; ny = curr.second + leftpos[9].second;
		caltmp = move - alpha;
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
			boundaryover += caltmp;
		}
		else {
			sand[nx][ny] += caltmp;
		}
		break;
	case 1:
		//down
		for (int i = 0; i < 9; i++) {
			caltmp = downper[i] * move / 100;
			alpha += caltmp;
			nx = curr.first + downpos[i].first; ny = curr.second + downpos[i].second;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				boundaryover += caltmp;

			}
			else {
				sand[nx][ny] += caltmp;
			}
		}
		//alpha calculate
		nx = curr.first + downpos[9].first; ny = curr.second + downpos[9].second;
		caltmp = move - alpha;
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
			boundaryover += caltmp;
		}
		else {
			sand[nx][ny] += caltmp;
		}
		break;
	case 2: 
		//right
		for (int i = 0; i < 9; i++) {
			caltmp = rightper[i] * move / 100;
			alpha += caltmp;
			nx = curr.first + rightpos[i].first; ny = curr.second + rightpos[i].second;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				boundaryover += caltmp;

			}
			else {
				sand[nx][ny] += caltmp;
			}
		}
		//alpha calculate
		nx = curr.first + rightpos[9].first; ny = curr.second + rightpos[9].second;
		caltmp = move - alpha;
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
			boundaryover += caltmp;
		}
		else {
			sand[nx][ny] += caltmp;
		}
		break;
	case 3:
		//up
		for (int i = 0; i < 9; i++) {
			caltmp = upper[i] * move / 100;
			alpha += caltmp;
			nx = curr.first + uppos[i].first; ny = curr.second + uppos[i].second;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				boundaryover += caltmp;

			}
			else {
				sand[nx][ny] += caltmp;
			}
		}
		//alpha calculate
		nx = curr.first + uppos[9].first; ny = curr.second + uppos[9].second;
		caltmp = move - alpha;
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
			boundaryover += caltmp;
		}
		else {
			sand[nx][ny] += caltmp;
		}
		break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sand[i][j];
		}
	}
	curr = { N / 2, N / 2 };
	while (curr.first != 0 || curr.second != 0) {
		for (int i = 0; i < side; i++) {
			//curr 한칸 이동
			curr = { curr.first + pmx[pmind], curr.second + pmy[pmind] };
			//curr 0으로 세팅
			int movem = sand[curr.first][curr.second];
			sand[curr.first][curr.second] = 0;
			
			//이동하면서 흩날려라 모래앵 계산
			spreadSand(movem, pmind);

			//손꾸락으로 모래 이동 다 하고 계산 다 하고 나서~ 0,0 이면 break해주자
			if (curr.first == 0 && curr.second == 0)break;
		}
		cntside++; pmind++;
		if (pmind == 4)pmind = 0;
		if (cntside == 2) { cntside = 0; side++; }
	}

	cout << boundaryover;
	return 0;
}
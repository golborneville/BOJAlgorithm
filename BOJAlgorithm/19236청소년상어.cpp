#include<iostream>
#include<queue>
#include<tuple>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

int toot = 0;
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1 }; //index 0 is not used
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1 };
pair<int, int> sea[5][5]; // {fish number, direction}
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> xy;
pair<int, int> xy[17]; //1~16 => (x , y)
//tuple<int, int, int> shark; // (x,y), direction
//use by: get<0~2>(shark);

void move_fish(tuple<int, int, int> shark) {
	//1. fish moving  
	for (int i = 1; i <= 16; i++) {
		bool fail = false;
		int fish_indx = xy[i].first;
		int fish_indy = xy[i].second;
		if (fish_indx == -1 && fish_indy == -1)continue;
		//cases fish cant move
		//1. when shark exists
		//2. position where cant be moved to 
		int move_ind = sea[fish_indx][fish_indy].second;
		int newx = fish_indx + dx[move_ind];
		int newy = fish_indy + dy[move_ind];
		while (true) {
			if (newx >= 0 && newy >= 0 && newx < 4 && newy < 4) {
				// proper position
				if (newx != get<0>(shark) || newy != get<1>(shark)) {
					break; // move to current newx, newy
				}
			}
			move_ind++;
			if (move_ind == 9) move_ind = 1;

			newx = fish_indx + dx[move_ind];
			newy = fish_indy + dy[move_ind];
			if (move_ind == sea[fish_indx][fish_indy].second) {
				//한바퀴 돌았는데 갈 수 있는 방향이 없음. 
				//체크 변수 하고 break
				fail = true;
				break;
			}

		}
		//swap two fishes(or move through blank space )
		if (!fail) { //여기도 수정
			pair<int, int> tmpOrig = sea[fish_indx][fish_indy]; //origin
			tmpOrig.second = move_ind;
			//newx newy is -1,-1
			sea[fish_indx][fish_indy] = sea[newx][newy];
			sea[newx][newy] = tmpOrig;
			xy[tmpOrig.first] = { newx, newy };
			if (sea[fish_indx][fish_indy].second == -1) {
				xy[sea[fish_indx][fish_indy].first] = { -1,-1 };
			}
			else {
				xy[sea[fish_indx][fish_indy].first] = { fish_indx, fish_indy };
			}
		}
	}
}
void shark_eat(tuple<int, int, int> shark, int fish) { //해당 턴에서 상어 위지 및 방향,/그리고 여태 생선 합
	int sx = get<0>(shark);
	int sy = get<1>(shark);
	int sdir = get<2>(shark);

	int nsx = sx + dx[sdir];
	int nsy = sy + dy[sdir];
	//최대합 갱신
	if (fish > toot)toot = fish;

	//복원용 배열 저장
	pair<int, int> seacopy[5][5];
	pair<int, int> xycpy[17];
	memcpy(seacopy, sea, sizeof(sea));
	memcpy(xycpy, xy, sizeof(xy));

	while ((nsx >= 0 && nsy >= 0 && nsx < 4 && nsy < 4)) {
		//제대로 된 범위 내에 존재 할때 상어가. 
		if (sea[nsx][nsy].second != -1) {
			//비어있는 칸 이 아니라면! 해당 물고기 먹고 나서 그 경우 가장 깊이까지
			//2. shark eating time
			tuple<int, int, int> shark_tmp = { nsx, nsy, sea[nsx][nsy].second }; //initialize
			xy[sea[nsx][nsy].first] = { -1,-1 };
			sea[nsx][nsy] = { sea[nsx][nsy].first, -1 };
			
			move_fish(shark_tmp);
			
			shark_eat(shark_tmp, sea[nsx][nsy].first + fish);

			//recover
			memcpy(sea, seacopy, sizeof(sea));
			memcpy(xy, xycpy, sizeof(xy));
			//sea[nsx][nsy] = { sea[nsx][nsy].first, get<2>(shark_tmp) }; //recover
		}
		nsx = nsx + dx[sdir];
		nsy = nsy + dy[sdir];
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> sea[i][j].first >> sea[i][j].second;
			xy[sea[i][j].first] = { i,j }; //keep track of each positions
		}
	}
	//fish eaten by shark is defined {fishnumber,-1}
	tuple<int, int, int> shark = { 0, 0, sea[0][0].second }; //initialize
	//toot += sea[0][0].first;
	xy[sea[0][0].first] = { -1,-1 };
	sea[0][0] = { sea[0][0].first,-1 };

	//while (true) { // if shark cant move anymore, break out of while {}
		
		//1. fish moving time
		move_fish(shark);

		//2. shark eating time
		//shark = { 2, 2, sea[2][2].second }; //initialize
		//toot += sea[2][2].first;
		//xy[sea[2][2].first] = { -1,-1 };
		//sea[2][2] = { sea[2][2].first,-1 };
		shark_eat(shark, sea[0][0].first);
		cout << toot;
	//}
}

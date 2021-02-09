#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

int N; //한변 타일 개수
struct tile {
	int tileNum;
	int left;
	int right;
	int prev; //이전에 있던 타일의 번호
};
int maxtileNum = 1;
vector<int> tilenum[502];
tile arr[250003];
bool chk[250003]; //tile chk 
int resnum[250003]; //경로....최소 횟수
queue<pair<int, pair<int, int>>> qu; //타일 번호, {타일이 벡터 안에서i,j 값}
stack<int> road; //경로 타일 번호!
void BFS() {
	//1번 타일부터 탐색 시작 할 예정임.
	chk[1] = true;
	//chk[1].second = true;

	while (!qu.empty()) {
		int tileN = qu.front().first;
		int vecx = qu.front().second.first;
		int vecy = qu.front().second.second;
		qu.pop();

		//오른쪽 왼쪽 체크!
		//현재 기준 왼쪽 체크
		if (vecy - 1 >= 0) {
			if (arr[tilenum[vecx][vecy-1]].right == arr[tileN].left && !chk[tilenum[vecx][vecy-1]]) {
				//현재 오른쪽 -> 아래 타일의 왼쪽 이랑 비교 (같은 숫자면 이동가능)
				chk[tilenum[vecx][vecy - 1]] = true;
				arr[tilenum[vecx][vecy - 1]].prev = tileN;
				qu.push({ tilenum[vecx][vecy - 1],{ vecx, vecy - 1} });
				if (maxtileNum < tilenum[vecx][vecy - 1])maxtileNum = tilenum[vecx][vecy - 1];
			}
		}
		

		//위 아래 탐색
		if (vecx % 2 == 0) {
			//짝수층? 0 2 4...
			//새 타일은 홀수 층 (N-1개 있음 타일)
			//현재 타일의 오른쪽체크!-> 홀수 줄 짝수 줄에 따라 달라짐 
			if (vecy + 1 < N) {
				if (arr[tilenum[vecx][vecy + 1]].left == arr[tileN].right && !chk[tilenum[vecx][vecy + 1]]) {
					//현재 오른쪽 -> 아래 타일의 왼쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx][vecy + 1]] = true;
					arr[tilenum[vecx][vecy + 1]].prev = tileN;
					qu.push({ tilenum[vecx][vecy + 1],{ vecx, vecy + 1 } });
					if (maxtileNum < tilenum[vecx][vecy + 1])maxtileNum = tilenum[vecx][vecy + 1];
				}
			}

			//오른쪽 기준 탐색 추가 
			if (vecx + 1 < N && vecy  < N - 1 ){
				if (arr[tilenum[vecx + 1][vecy]].left == arr[tileN].right && !chk[tilenum[vecx + 1][vecy]]) {
					//현재 오른쪽 -> 아래 타일의 왼쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx + 1][vecy]] = true;
					arr[tilenum[vecx + 1][vecy]].prev = tileN;
					qu.push({ tilenum[vecx + 1][vecy],{vecx +1, vecy} });
					if (maxtileNum < tilenum[vecx + 1][vecy])maxtileNum = tilenum[vecx + 1][vecy];
				}
				
			}
			if (vecx - 1 >=0 && vecy  < N - 1) {
				if (arr[tilenum[vecx -1][vecy]].left == arr[tileN].right && !chk[tilenum[vecx - 1][vecy]]) {
					//현재 오른쪽 -> 위 타일의 왼쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx - 1][vecy]] = true;
					arr[tilenum[vecx - 1][vecy]].prev = tileN;
					qu.push({ tilenum[vecx - 1][vecy],{ vecx - 1, vecy } });
					if (maxtileNum < tilenum[vecx - 1][vecy])maxtileNum = tilenum[vecx - 1][vecy];
				}

			}
			//왼쪽 기준 탐색 추가
			if (vecx + 1 < N && vecy-1 >=0 && vecy  < N) {
				if (arr[tilenum[vecx + 1][vecy - 1]].right == arr[tileN].left && !chk[tilenum[vecx + 1][vecy - 1]]) {
					//현재 왼쪽 -> 아래 타일의 오른쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx + 1][vecy - 1]] = true;
					arr[tilenum[vecx + 1][vecy - 1]].prev = tileN;
					qu.push({ tilenum[vecx + 1][vecy-1],{ vecx + 1, vecy-1 } });
					if (maxtileNum < tilenum[vecx + 1][vecy - 1])maxtileNum = tilenum[vecx + 1][vecy - 1];
				}
			}
			if (vecx - 1 >= 0 && vecy - 1 >= 0 && vecy < N) {
				if (arr[tilenum[vecx - 1][vecy - 1]].right == arr[tileN].left && !chk[tilenum[vecx - 1][vecy - 1]]) {
					//현재 왼쪽 -> 위 타일의 오른쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx - 1][vecy - 1]] = true;
					arr[tilenum[vecx - 1][vecy - 1]].prev = tileN;
					qu.push({ tilenum[vecx - 1][vecy-1],{ vecx - 1, vecy-1 } });
					if (maxtileNum < tilenum[vecx - 1][vecy - 1])maxtileNum = tilenum[vecx - 1][vecy - 1];
				}
			}
		}
		//홀수층
		else if (vecx % 2 != 0) {

			//현재 타일의 오른쪽체크!-> 홀수 줄 짝수 줄에 따라 달라짐 
			if (vecy + 1 < N-1) {
				if (arr[tilenum[vecx][vecy + 1]].left == arr[tileN].right && !chk[tilenum[vecx][vecy + 1]]) {
					//현재 오른쪽 -> 아래 타일의 왼쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx][vecy + 1]] = true;
					arr[tilenum[vecx][vecy + 1]].prev = tileN;
					qu.push({ tilenum[vecx][vecy + 1],{ vecx, vecy + 1 } });
					if (maxtileNum < tilenum[vecx][vecy + 1])maxtileNum = tilenum[vecx][vecy + 1];
				}
			}

			//오른쪽 기준 탐색 추가 
			if (vecx + 1 < N) {
				if (arr[tilenum[vecx + 1][vecy]].right == arr[tileN].left && !chk[tilenum[vecx + 1][vecy]]) {
					//현재 왼쪽 -> 아래 타일의 오른쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx + 1][vecy]] = true;
					arr[tilenum[vecx + 1][vecy]].prev = tileN;
					qu.push({ tilenum[vecx + 1][vecy],{ vecx + 1, vecy } });
					if (maxtileNum < tilenum[vecx + 1][vecy])maxtileNum = tilenum[vecx + 1][vecy];
				}

			}
			if (vecx - 1 >= 0) {
				if (arr[tilenum[vecx - 1][vecy]].right == arr[tileN].left && !chk[tilenum[vecx - 1][vecy]]) {
					//현재 왼쪽 -> 위 타일의 오른쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx - 1][vecy]] = true;
					arr[tilenum[vecx - 1][vecy]].prev = tileN;
					qu.push({ tilenum[vecx - 1][vecy],{ vecx - 1, vecy } });
					if (maxtileNum < tilenum[vecx - 1][vecy])maxtileNum = tilenum[vecx - 1][vecy];
				}

			}
			//왼쪽 기준 탐색 추가
			if (vecx - 1 >=0 && vecy + 1 <N) {
				if (arr[tilenum[vecx - 1][vecy + 1]].left == arr[tileN].right && !chk[tilenum[vecx - 1][vecy + 1]]) {
					//현재 오른쪽 -> 위 타일의 왼쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx - 1][vecy + 1]] = true;
					arr[tilenum[vecx - 1][vecy + 1]].prev = tileN;
					qu.push({ tilenum[vecx - 1][vecy + 1],{ vecx - 1, vecy + 1 } });
					if (maxtileNum < tilenum[vecx - 1][vecy + 1])maxtileNum = tilenum[vecx - 1][vecy + 1];
				}
			}
			if (vecx + 1 <N && vecy + 1 <N) {
				if (arr[tilenum[vecx + 1][vecy + 1]].left == arr[tileN].right && !chk[tilenum[vecx + 1][vecy + 1]]) {
					//현재 오른쪽 -> 아래 타일의 왼쪽 이랑 비교 (같은 숫자면 이동가능)
					chk[tilenum[vecx + 1][vecy + 1]] = true;
					arr[tilenum[vecx + 1][vecy + 1]].prev = tileN;
					qu.push({ tilenum[vecx + 1][vecy + 1],{ vecx + 1, vecy + 1 } });
					if (maxtileNum < tilenum[vecx + 1][vecy + 1])maxtileNum = tilenum[vecx + 1][vecy + 1];
				}
			}
		}

	}
}

int getWay() {
	int tile = arr[maxtileNum].tileNum;
	int cnt = 0;
	while (arr[tile].tileNum != 0) {
		road.push(tile);
		cnt++;
		tile = arr[tile].prev;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	//index 1~ N*N - N/2
	for (int i = 1; i <= N*N - N/2; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		arr[i] = { i, num1, num2, 0 }; // 일차원 배열로 입력
	}
	int ind = 1;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				tilenum[i].push_back(arr[ind].tileNum);
				ind++;
			}
		}
		else if (i % 2 != 0) {
			for (int j = 0; j < N-1; j++) {
				tilenum[i].push_back(arr[ind].tileNum);
				ind++;
			}
		}
	}
	qu.push({ 1,{0,0} });
	BFS();
	int numtile = getWay(); //타일 개수 
	cout << numtile << "\n";
	while (!road.empty()) {
		cout << road.top() << " ";
		road.pop();
	}

	return 0;
}
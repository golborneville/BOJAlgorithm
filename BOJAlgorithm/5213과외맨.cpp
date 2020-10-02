#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
//#define INF 987654321 //-> -1로 바꾸자 어차피 +1이니까
int N;
int area[505][505];
pair<int,pair<int,int>> before[505][505];
int chk[505][505];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1,0, -1,0 };
queue <pair<int, int>> q;
stack <int> st; // tile number!!!!!!!
void getRoad(int x, int y) {
	int tileNumb = before[x][y].first;
	int da = x;
	int db = y;
	while (tileNumb != 0) {
		//cout << tileNumb << " ";
		st.push(tileNumb);
		int da2 = before[da][db].second.first;
		int db2 = before[da][db].second.second;
		tileNumb = before[da2][db2].first;
		da = da2;
		db = db2;
	}
}
void BFS(int n1, int n2) {
	//before[n1][n2] = 1; // 이전단계에 몇번째 타일에서 왔는지 저장
	chk[n1][n2] = 1;
	q.push({ n1,n2 });
	int keep_track = 0;
	int cnt = 0;
	int row_before = q.front().first;
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int xx = tmp.first +dx[i];
			int yy = tmp.second + dy[i];
			if (xx >= 0 && yy >= 0 && xx < N && yy < 2 * N) {
				//tmp's tile num == xx yy 's tile num?
				int tmpTile, xytile;
				if (tmp.first % 2 == 0) {
					tmpTile = (tmp.first / 2)*(2 * N - 1) + (tmp.second / 2) + 1;
				}
				else {
					tmpTile = (tmp.first / 2) * (2 * N - 1) + N + ((tmp.second + 1) / 2);
				}

				if (xx % 2 == 0) {
					xytile = (xx / 2)*(2 * N - 1) + (yy / 2) + 1;
				}
				else {
					xytile = (xx / 2) * (2 * N - 1) + N + ((yy + 1) / 2);
				}
				if ((area[tmp.first][tmp.second] == area[xx][yy] || tmpTile == xytile) && chk[xx][yy]==0) {
					if (tmpTile != xytile) {
						chk[xx][yy] = chk[tmp.first][tmp.second] + 1;
						before[xx][yy] = { tmpTile ,{ tmp.first ,tmp.second } };
					}
					else {
						chk[xx][yy] = chk[tmp.first][tmp.second];
						before[xx][yy] = { before[tmp.first][tmp.second].first ,{ before[tmp.first][tmp.second].second.first, before[tmp.first][tmp.second].second.second } };

					}
					q.push({ xx, yy });
					//마지막 줄 마지막 타일 도착 
					if (xx == N - 1 && yy == 2 * N - 2) {
						return;
					}
				}

			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(area, -1, sizeof(area));
	memset(chk, 0, sizeof(chk));
	
	cin >> N;
	int row = N*N - N / 2;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				cin >> area[i][2*j] >> area[i][2 * j +1];
			}
		}
		else {
			//area[i][0] = INF;
			//area[i][2*N - 1] = INF;
			for (int j = 0; j < N-1; j++) {
				cin >> area[i][2 * j +1] >> area[i][2 * j + 2];
			}
		}
	}
	BFS(0, 1);
	int inx = N - 1;
	int iny = 2 * N - 2;  // 마지막 타일의  첫번째 기준으로 탐색하며서 짝 홀 경우 고려X
	while (chk[inx][iny] == 0) {
		iny--;
		if (iny == -1) {
			iny = 2 * N - 1;
			inx--;
		}
		//if (area[inx][iny] == -1) {
			//짝수줄이라 옳지못한 접근이라는 의미
		//	iny = 2 * N - 2;
		//	inx--;
		//}
	}
	//최대값 최대 타일 번호 지닌 x y 값 나옴
	//해당 좌표에 대해 이제 경로 추적
	int sumd;
	if (inx % 2 == 0) {
		sumd = (inx / 2)*(2 * N - 1) + (iny / 2) + 1;
	}
	else {
		sumd = (inx / 2) * (2 * N - 1) + N + ((iny + 1) / 2);
	}

	cout << chk[inx][iny] << "\n";
	st.push(sumd);
	getRoad(inx, iny);



	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;


}
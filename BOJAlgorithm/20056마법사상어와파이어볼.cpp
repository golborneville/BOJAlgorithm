#include<iostream>
#include<vector>
using namespace std;

struct fire {
	int m; //질량
	int s; //속력 
	int d; //방향(0~7)
};
vector<fire> sea[53][53]; //이거 원통마냥 돈다는 소리임;
vector<fire> moveTMP[53][53]; //이동할떄 쓰는 임의 자료구조
int N, M, K; //격자 크기, 파이어볼 개수 발사한거 , 상어 이동 횟수
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0, 1,1,1,0,-1,-1,-1 };

void moveball(fire st, int x, int y) {
	//속도와 방향 계산
	int nx = x + (dx[st.d] * st.s) % N;
	int ny = y + (dy[st.d] * st.s) % N;

	//이어진거 처리(outofbound)
	if (nx > N) nx -= N;
	if (nx <= 0) nx += N;
	if (ny > N) ny -= N;
	if (ny <= 0) ny += N;


	//좌표 얻엇으니 불공 옮기자 
	moveTMP[nx][ny].push_back(st);


}

void sharkStep() {
	//1. move all the fireballs 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < sea[i][j].size(); k++) { //뒤에서부터^^..
				moveball(sea[i][j][k], i, j);
			}
			//이동 다 끝나고 기존에 있던 자리는 clear해주기
			sea[i][j].clear();
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (moveTMP[i][j].size() > 0) {
				sea[i][j] = moveTMP[i][j]; //copy
				moveTMP[i][j].clear();
			}
		}
	}

	//2.check where there are more than 2 fireballs
	  //2-2. 합친 불공 4개로 나누기
	  //2-3. 질량 나누기 / 속력 나누기 / 방향 결정하기(dir: sum all odd:서로 다름 1357/ even: 모두 홀or짝:0246
	  //2-4. 계산 끝난 파이어볼 이동!(속력만큼 중요)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (sea[i][j].size() > 1) {
				fire sumtmp = { 0,0,0 };
				int fallnum = sea[i][j].size();
				bool even = false, odd = false;
				for (int k = 0; k < sea[i][j].size(); k++) {
				//2-1. 같은 칸 불공 하나로 합치기
					sumtmp.m += sea[i][j][k].m;
					sumtmp.s += sea[i][j][k].s;
					//sumtmp.d += sea[i][j][k].d;
					if (sea[i][j][k].d % 2 == 0) even = true;
					else odd = true;
				}
				sea[i][j].clear();
				sumtmp.m = sumtmp.m / 5;
				if (sumtmp.m == 0) continue;//3. 질량 0인 불공없애기 
				
				sumtmp.s = sumtmp.s / fallnum;
				if ((even && !odd) || (!even && odd)) {
					//even: 0246
					for (int ind = 0; ind < 8; ind += 2) {
						sumtmp.d = ind;
						sea[i][j].push_back(sumtmp);
	
					}
				}
				else if(even && odd){
					//odd: 1357
					for (int ind = 1; ind < 8; ind += 2) {
						sumtmp.d = ind;
						sea[i][j].push_back(sumtmp);
					}
				}
				
			}

		}
	}
}

int getRemainM() {
	int sumM = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < sea[i][j].size(); k++) {
				//2-1. 같은 칸 불공 하나로 합치기
				sumM += sea[i][j][k].m;
			}
		}
	}
	return sumM;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;//행,렬, 질량,속력,방향
		cin >> r >> c >> m >> s >> d;
		sea[r][c].push_back({m,s,d});
	
	}
	while (K--) {
		sharkStep();
	}
	cout << getRemainM(); //남아있는 불공 질량 합 
	return 0;
}
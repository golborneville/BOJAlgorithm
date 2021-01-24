#include<iostream>
#include<algorithm>
using namespace std;
int H, W, N;
int paper[105][105];
pair<int, int> stickersize[105];
int resmax = 0;
bool chk[105];
int compair[2]; // 0,1 에 선택한 두개(번호(0~N-1)) 있음

void simulation(int pr1, int pc1,int pr2, int pc2) {
	//첫번째 종이 가로 , 세로 , 두번재  종이 가로, 세로
	//case1 . 좌우에 붙이기
	int sumrow = pr1 + pr2;
	int sumcol = max(pc1, pc2);
	int tmpArea = pr1*pc1 + pr2*pc2;
	if (resmax < tmpArea && sumrow <= H && sumcol <= W) {
		resmax = tmpArea;
	}
	//case2. 상하에 붙이기
	sumrow = max(pr1,pr2);
	sumcol = pc1 + pc2;
	tmpArea = pr1*pc1 + pr2*pc2;
	if (resmax < tmpArea && sumrow <= H && sumcol <= W) {
		resmax = tmpArea;
	}
}
void combination(int m, int depth) {
	if (depth == 2) {
		int pr1 = stickersize[compair[0]].first;
		int pc1 = stickersize[compair[0]].second;

		int pr2 = stickersize[compair[1]].first;
		int pc2 = stickersize[compair[1]].second;

		simulation(pr1, pc1, pr2, pc2);
		simulation(pc1, pr1, pr2, pc2);
		simulation(pr1, pc1, pc2, pr2);
		simulation(pc1, pr1, pc2, pr2);

		return;
	}

	for (int i = m; i < N; i++) {
		if (chk[i])continue;
		chk[i] = true;
		compair[depth] = i;
		combination(i + 1, depth + 1);
		chk[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		cin >> stickersize[i].first >> stickersize[i].second;
		
	}
	combination(0, 0);
	cout << resmax;
	return 0;
}
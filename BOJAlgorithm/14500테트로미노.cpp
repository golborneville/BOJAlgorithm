#include<iostream>
#include<vector>
using namespace std;

//1차로틀린이유: 대칭 안시켜줌.
int paper[502][502];
vector<pair<int, int>> bag[19];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//테트로미노 좌표 (상대적)
	pair<int, int> blue[4] = { {0,0},{0,1}, {0,2}, {0,3} };
	pair<int, int> blue2[4] = { { 0,0 },{ 1,0 },{ 2, 0 },{ 3, 0 } };

	pair<int, int> yellow[4] = { {0,0},{0,1}, {1,0},{1,1} };

	pair<int, int> orange1[4] = { {0,0}, {1,0}, {2,0},{2,1} }; //기존 모양 시계 방향회전
	pair<int, int> orange2[4] = { { 0,0 },{ 0,1 },{ 0,2 },{ 1,0 } };
	pair<int, int> orange3[4] = { { 0,0 },{ 0,1 },{1,1 },{ 2,1 } };
	pair<int, int> orange4[4] = { { 0,0 },{ 1,0 },{ 1,-1 },{ 1,-2 } };

	//대칭
	pair<int, int> orange5[4] = { { 0,0 },{ 1,0 },{ 2,0 },{ 2,-1 } }; //기존 모양 시계 방향회전
	pair<int, int> orange6[4] = { { 0,0 },{ 1,1 },{ 1,2 },{ 1,0 } };
	pair<int, int> orange7[4] = { { 0,0 },{ 0,1 },{ 1,0 },{ 2,0 } };
	pair<int, int> orange8[4] = { { 0,0 },{ 1,2 },{ 0,1 },{ 0,2 } };

	pair<int, int> green1[4] = { {0,0},{1,0},{1,1},{2,1} };
	pair<int, int> green2[4] = { { 0,0 },{ 1,0 },{ 0,1 },{ 1,-1 } };
	//대칭 
	pair<int, int> green3[4] = { { 0,0 },{ 1,0 },{ 1,-1 },{ 2,-1 } };
	pair<int, int> green4[4] = { { 0,0 },{ 1,1 },{ 0,1 },{ 1,2 } };

	pair<int, int> pink1[4] = { { 0,0 },{ 0,1 },{ 0,2 },{ 1,1 } };
	pair<int, int> pink2[4] = { { 0,0 },{ 1,0 },{ 2,0 },{ 1,-1 } };
	pair<int, int> pink3[4] = { { 0,0 },{ 1,0 },{ 1,-1 },{ 1,1 } };
	pair<int, int> pink4[4] = { { 0,0 },{ 1,0 },{ 2,0 },{ 1,1 } };

	for (int i = 0; i < 4; i++) {
		bag[0].push_back(blue[i]);
		bag[1].push_back(blue2[i]);

		bag[2].push_back(yellow[i]);

		bag[3].push_back(orange1[i]);
		bag[4].push_back(orange2[i]);
		bag[5].push_back(orange3[i]);
		bag[6].push_back(orange4[i]);

		bag[7].push_back(green1[i]);
		bag[8].push_back(green2[i]);

		bag[9].push_back(pink1[i]);
		bag[10].push_back(pink2[i]);
		bag[11].push_back(pink3[i]);
		bag[12].push_back(pink4[i]);

		bag[13].push_back(orange5[i]);
		bag[14].push_back(orange6[i]);
		bag[15].push_back(orange7[i]);
		bag[16].push_back(orange8[i]);

		bag[17].push_back(green3[i]);
		bag[18].push_back(green4[i]);
	}
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}
	int maxSum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				bool pass = false;
				for (int l = 0; l < 4; l++) {
					if (bag[k][l].first + i < 0 || bag[k][l].second + j < 0
						|| bag[k][l].first + i >= N || bag[k][l].second + j >= M)  pass = true;
				}
				if (pass) continue; //테트로미노가 범위 밖에 위치한게 있음
				int sumeach = 0;
				for (int l = 0; l < 4; l++) {
					sumeach += paper[bag[k][l].first + i][bag[k][l].second + j];
				}
				if (sumeach > maxSum) maxSum = sumeach;
			}
		}
	}
	cout << maxSum;
	return 0;

}
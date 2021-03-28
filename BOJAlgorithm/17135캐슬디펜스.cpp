#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N, M, D;
int castle[17][17];
int recover[17][17];
int comb[15];
struct info {
	int x;
	int y;
	int dis;
};
pair<int, int> archer[3]; //궁수 3명 좌표값
info enemy[3]; //죽인 적 3명
int res = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> castle[i][j];
			recover[i][j] = castle[i][j];
			
		}
	}
	comb[M - 1] = 1; comb[M - 2] = 1; comb[M - 3] = 1;
	do {
		int kill = 0;
		int ind = 0;
		
		memset(archer, 0, sizeof(archer));
		
		for (int i = 0; i < M; i++)
		{
			if (comb[i] == 1) 
				archer[ind++] = { N, i };
		}
		//N회 만큼 반복
		//1. 궁수와 거리 가장 가까운(D이하) 적 선택-> 없앤 적++;
		for (int f = 0; f < N; f++) {
			for (int i =archer[0].first-1; i >= 0; i--)
			{//맨 아래 행서부터 시작 

				for (int j = 0; j < M; j++)
				{

					if (castle[i][j]) // if enemy YES
					{
						for (int a = 0; a < 3; a++)
						{
							int cmpdis = abs(archer[a].first - i) + abs(archer[a].second - j);
							if (cmpdis > D) continue;
							if (!enemy[a].dis)
							{//처음 마주하느 ㄴ적이니 그냥 삽입
								enemy[a] = { i,j,cmpdis };
							}
							else
							{
								if (cmpdis < enemy[a].dis) enemy[a] = { i, j, cmpdis };
								if (cmpdis == enemy[a].dis)
								{
									if(j < enemy[a].y) enemy[a] = { i, j, cmpdis };
								}
							}
						}
					}
				}

			}
			//2. 한줄 내려오면서맵 상태(궁수와 적 거리 ) 업데이트-> 궁수를 한줄 위로 올려버림
			for (int a = 0; a < 3; a++)
			{
				archer[a] = { archer[a].first - 1, archer[a].second }; //이동 해주고 나서는 꼭 바로 윗줄부터 탐색 필ㅇ요
				if (enemy[a].dis && castle[enemy[a].x][enemy[a].y])
				{
					castle[enemy[a].x][enemy[a].y] = 0;
					kill++; 
				}
			}
			memset(enemy, 0, sizeof(enemy));
		}

		//없앤적 vs 기존 최댓값 비교 & 업데이트
		if (res < kill) res = kill;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				castle[i][j] = recover[i][j];

			}
		}

	}while(next_permutation(comb, comb + M));

	cout << res;
	return 0;
}
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;


int city[23][23];
int area[23][23];
bool chk[23][23];
int N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1, -1 };

int popval[6] = { 0,0,0,0,0,0 };
int res = 987654321;
void fill_area(int x, int y, int area_val)
{
	//5를 채우는 경우 만약 내부가 대각선으로만 접근가능한 경우???-> 이것만 처리 필요 & 시간복잡도 계산다시하기
	queue<pair<int, int>> qu;
	qu.push({ x, y });
	area[x][y] = area_val;
	while (!qu.empty()) {
		pair<int, int> node = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int nx = node.first + dx[i]; int ny = node.second + dy[i];
			if (nx<=0 || ny <= 0 || nx >N || ny > N)continue;
			if (!area[nx][ny]) {
				area[nx][ny] = area_val;
				qu.push({ nx,ny });
				
			}
		}
	}
}

void get_each_pop(int x, int y, int num)
{
	queue<pair<int, int>> qu;
	qu.push({ x, y });
	chk[x][y] = true;
	if (area[x][y] == num) popval[num] += city[x][y];
	while (!qu.empty()) {
		pair<int, int> node = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int nx = node.first + dx[i]; int ny = node.second + dy[i];
			if (nx <= 0 || ny <= 0 || nx >N || ny > N)continue;
			if (!chk[nx][ny] && area[nx][ny] == num) {
				chk[nx][ny] = true;
				qu.push({ nx,ny });
				popval[num] += city[nx][ny];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> city[i][j];
		}
	}
	//1. x y d1 d2 에 대해 모든 경우의 수 조합 돌리기 
	for (int d1 = 1; d1 <= N; d1++) {
		for (int d2 = 1; d2 <= N; d2++) {
			for (int x = 1; x <= N; x++){
				for (int y = 1; y <= N; y++) {
					if (x + d1 + d2 > N)continue;
					if (y - d1 < 1) continue;
					if (y + d2 > N) continue;

					memset(chk, false, sizeof(chk));
					memset(area, 0, sizeof(area)); //init
					memset(popval, 0, sizeof(popval));
					//area border 5
					for (int a1x = x,a1y = y; a1x <= x + d1 && a1y >= y - d1; a1x++, a1y--) 
						area[a1x][a1y] = 5;
					for (int a1x = x, a1y = y; a1x <= x + d2 && a1y <= y + d2; a1x++, a1y++) 
						area[a1x][a1y] = 5;
					for (int a1x = x + d1, a1y = y - d1; a1x <= x + d1 +d2 && a1y <= y - d1 + d2; a1x++, a1y++) 
						area[a1x][a1y] = 5;
					for (int a1x = x + d2, a1y = y + d2; a1x <= x + d1 + d2 && a1y >= y - d1 + d2; a1x++, a1y--) 
						area[a1x][a1y] = 5;
					
					for (int a1x = x + 1, a1y = y -1; a1x <= x + d1 && a1y >= y - d1; a1x++, a1y--)
						if(!area[a1x][a1y+1])
							fill_area(a1x, a1y + 1, 5);
					for (int a1x = x + d1, a1y = y - d1; a1x < x + d1 + d2 && a1y < y - d1 + d2; a1x++, a1y++)
						if (!area[a1x][a1y + 1])
							fill_area(a1x, a1y + 1, 5);
				

					//x, y 위로 1
					for (int ax = x - 1, ay = y; ax > 0; ax--)
						area[ax][ay] = 1;
					//x+d1, y -d1 왼쪽으로 3
					for (int ax = x + d1, ay = y - d1 - 1; ay > 0; ay--) 
						area[ax][ay] = 3;
					//x+d2, y+d2  오른쪽으로 2
					for (int ax = x +d2, ay = y + d2 + 1; ay <= N; ay++) 
						area[ax][ay] = 2;
					//x+d1+d2, y -d1 +d2 아래로 4
					for (int ax = x  + d1 + d2 + 1, ay = y +d2 - d1; ax <= N; ax++) 
						area[ax][ay] = 4;

					
					//area 1
					fill_area(1, 1, 1);
					//area 2
					fill_area(1, N, 2);
					//area 3
					fill_area(N, 1, 3);
					//area 4
					fill_area(N, N, 4);


					get_each_pop(x, y, 5);
					get_each_pop(1, 1, 1);
					get_each_pop(1, N, 2);
					get_each_pop(N, 1, 3);
					get_each_pop(N, N, 4);

					sort(popval + 1, popval + 6);
					
					if (res > popval[5] - popval[1]) res = popval[5] - popval[1];
					//구역 나누기는 정상
					//인구수 합하는 과정에서 중복+ 좌표 틀림-> 인구수만 구하는 함수 따로 뺄것********
				}
			}
		}
	}

	//2. 해당 경우에 대해 5구역 번저 처리 하고(area)
	//3. x y d1 d2 값에 따라 1 2 3 4 구역 처리
	//4. 인구 최저와 최대 값 간 차이 구하고 -> (전역)최대와 비교해서 업데이트

	cout << res;
	return 0;

}
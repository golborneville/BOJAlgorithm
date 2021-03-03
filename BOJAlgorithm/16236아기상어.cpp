#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int sea[23][23];
int chk[23][23];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
struct fish {
	int size;
	int x; 
	int y;
	int dis;
};
struct shark {
	int size;
	int x;
	int y;
	int eaten;
};
bool cmp(const fish &a, const fish &b) {
	//if (a.dis > b.dis) return true;
	//else if(a.dis == b.dis){
	if (a.x > b.x) {
		return true;
	}
	else if (a.x == b.x) {
		return a.y > b.y;
	}
	else
		return false;
//	}
//	return false;
}

vector<fish> mob;
shark baby;
vector<fish> appl;
void BFS( ) {
	//�Ʊ� �����ġ �������� ����� ���� �ִ� �ֵ� ���� ����
	//baby �� target���� �̵� + �� �ڸ��� �մ� ����� �Դ� ���� �� ���� 
	//����� �Ծ����� ������ ���� �����ϸ� ������ �����ֱ� (���̺� ������)
	queue<pair<int, int>> qu;
	int lval = 987654321;
	chk[baby.x][baby.y] = 0;
	qu.push({ baby.x, baby.y });
	sea[baby.x][baby.y] = 0;
	while (!qu.empty()) {
		pair<int, int> nd = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nd.first + dx[i]; int ny = nd.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (chk[nx][ny] == -1 && sea[nx][ny] >= 0 && sea[nx][ny] <= baby.size) {
				chk[nx][ny] = chk[nd.first][nd.second] + 1;
				qu.push({ nx,ny });

				if (sea[nx][ny] > 0 && sea[nx][ny] < baby.size) {
					if (lval > chk[nx][ny]) lval = chk[nx][ny];
					if (lval == chk[nx][ny]) appl.push_back({ sea[nx][ny], nx,ny, chk[nx][ny] });
					/*sea[nx][ny] = 9;
					baby.eaten = baby.eaten + 1;
					if (baby.size == baby.eaten) {
						baby.eaten = 0;
						baby.size = baby.size + 1;
					}
					baby.x = nx; baby.y = ny;
					return chk[nx][ny]; //���⼭ ������ �ִ� �Ÿ��� ��ġ �� �ֵ� ����Ʈ ������ x y �켱���� �ΰ� �������ֱ�
				*/
				}

				/*if (nx == target.x && ny == target.y) {
					sea[nx][ny] = 9;
					baby.eaten = baby.eaten + 1;
					if (baby.size == baby.eaten) {
						baby.eaten = 0;
						baby.size = baby.size + 1;
					}
					return chk[nx][ny];
				}*/

			}
		}
	}
	//return 0;

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int helpday = 0;


	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> sea[i][j];
			if (sea[i][j] >= 1 && sea[i][j] <= 6) {
				fish tmp = { sea[i][j], i,j, 0 };
				mob.push_back(tmp);
			}
			if (sea[i][j] == 9) baby = { 2, i,j ,0};
		}

	while (mob.size() > 0) {
		//���⼭ ���� 
		/*for (int i = 0; i < mob.size(); i++) {
			mob[i].dis = abs(mob[i].x - baby.x) + abs(mob[i].y - baby.y);
		}
		sort(mob.begin(), mob.end(), cmp);
		vector<fish> overb;
		for (int i = mob.size() - 1; i >= 0; i--) {
			if (mob[i].size >= baby.size) {
				overb.push_back(mob[i]);
				mob.pop_back();
			}
			else break;
		}
		if (mob.size() == 0) break;
		fish target = mob[mob.size()-1];
		mob.pop_back();

		for (int i = 0; i < overb.size(); i++) {
			mob.push_back(overb[i]);
		}*/
		//������� ���� �����ϴ°ſ��� ������� ����ؼ� -> �ϴ� ���ƾƾ�����Ѵٴ� �Ҹ�=^.^=

		//(����) �ִ� �Ÿ� �� ��� �ĺ� => appl�� ����
		memset(chk, -1, sizeof(chk));
		BFS();
		if (!appl.size()) break;
		sort(appl.begin(), appl.end(), cmp);
		fish target = appl[appl.size() - 1];
		appl.clear();

		helpday += target.dis;
		sea[target.x][target.y] = 9;
		baby.eaten = baby.eaten + 1;
		if (baby.size == baby.eaten) {
			baby.eaten = 0;
			baby.size = baby.size + 1;
		}
		baby.x = target.x; baby.y = target.y;


		//if (!rs) break;
		//helpday += rs;
		//baby.x = target.x; baby.y = target.y; //��� ��ġ ����

	}
	cout << helpday;
	return 0;
}
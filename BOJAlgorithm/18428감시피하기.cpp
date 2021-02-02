#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int N;
vector<pair<int, int>> student;
vector<pair<int, int>> tech;
char classroom[8][8];
 //원래 6*6 까지
bool checkteacher(int x1, int y1, int x2, int y2, int x3, int y3) {
	int tmpx[3] = { x1,x2,x3 };
	int tmpy[3] = { y1,y2,y3 };
	bool tmpret = true;
	for (int i = 0; i < student.size(); i++) {
		int sx = student[i].first;
		int sy = student[i].second;
		for (int j = 0; j < tech.size(); j++) {
			if (tech[j].first != sx && tech[j].second != sy) continue;
			tmpret = true;
			if (tech[j].first == sx) {
				tmpret = false;
				//같은 행에 위치  ----
				for (int k = 0; k < 3; k++) {
					if (tech[j].second < tmpy[k] && sy > tmpy[k] && tmpx[k] == sx) tmpret = true;
					if (tech[j].second > tmpy[k] && sy < tmpy[k] && tmpx[k] == sx) tmpret = true;
				}
			}
			else if (tech[j].second == sy) {
				tmpret = false;
				//같은 열  ㅣ 
				for (int k = 0; k < 3; k++) {
					if (tech[j].first < tmpx[k] && sx > tmpx[k] && tmpy[k] == sy) tmpret = true;
					if (tech[j].first > tmpx[k] && sx < tmpx[k] && tmpy[k] == sy) tmpret = true;
				}
			}
			if (!tmpret) {
				//선생이 학생 발견 ㅇㅇ 성립X 케이스
				return false;
			}
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> classroom[i][j];
			if (classroom[i][j] == 'S') {
				student.push_back({ i,j });
			}
			else if (classroom[i][j] == 'T') {
				tech.push_back({ i,j });
			}
		}
	}
	bool res = false;
	//setting 3 obsticles (choose position)
	for (int x1 = 0; x1 < N; x1++) {
		for (int y1 = 0; y1 < N; y1++) {
			if (classroom[x1][y1] != 'X')continue;

			for (int x2 = x1; x2 < N; x2++) {
				for (int y2 = 0; y2 < N; y2++) {
					if (classroom[x2][y2] != 'X')continue;

					for (int x3 = x2; x3 < N; x3++) {
						for (int y3 = 0; y3 < N; y3++) {
							if (classroom[x3][y3] != 'X')continue;

							//전부 다 'X'
							classroom[x1][y1] = 'O';
							classroom[x2][y2] = 'O';
							classroom[x3][y3] = 'O';

							res = checkteacher(x1,y1,x2,y2,x3,y3);
							
							classroom[x1][y1] = 'X';
							classroom[x2][y2] = 'X';
							classroom[x3][y3] = 'X';

							if (res) break;
						}
						if (res) break;
					}
					if (res) break;
				}
				if (res) break;
			}
			if (res) break;
		}
		if (res) break;
	}
	res ? cout << "YES" : cout << "NO";
	return 0;


}
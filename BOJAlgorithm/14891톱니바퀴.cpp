#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string r1, r2, r3, r4;
int K, direc, rnum;
bool turn[2][4]; //0:  1 2 3 4 //[2] [6] 비교& 회전 가능true?
				 //1:  1 2 3 4 // 각 톱니바퀴가 회전을 헀는지 확인 
string RR(string ro) { // 시계방향 회전
	char tmp = ro[7];
	for (int i = 6; i >=0; i--) {
		ro[i+1] = ro[i];
	}
	ro[0] = tmp;
	return ro;
}
string RL(string ro) { // 반시계 방향 회전
	char tmp = ro[0];
	for (int i = 0; i < 7; i++) {
		ro[i] = ro[i+1];
	}
	ro[7] = tmp;
	return ro;
}
int main() {
	ios_base::sync_with_stdio(false);
	int points = 0;
	cin.tie(NULL);
	cin >> r1 >> r2 >> r3 >> r4; // 0  1  2  3  4  5  6  7 배열
								 // 12    3     6     9  
	cin >> K;
	while (K--) { 
		memset(turn, false, sizeof(turn));
		cin >> rnum >> direc; //1 시게 방향  & -1 반시계방향
		//4times of rotation 
		switch (rnum)
		{
		case 1:
			//2->3->4
			//회전유무 먼저 판단
			turn[0][0] = true;
			if (r1[2] != r2[6]) {
				turn[0][1] = true;
			}
			if (r2[2] != r3[6]) {
				turn[0][2] = true;
			}
			if (r3[2] != r4[6]) {
				turn[0][3] = true;
			}
			if (direc == 1) {				
				//시계방향 회전
				r1 = RR(r1);
				turn[1][0] = true;
				if (turn[0][1] == true && turn[1][0] == true) {
					r2 = RL(r2);
					turn[1][1] = true;
				}
				if (turn[0][2] == true && turn[1][1] == true) {
					r3 = RR(r3);
					turn[1][2] = true;
				}
				if (turn[0][3] == true && turn[1][2] == true) {
					r4 = RL(r4);
					turn[1][3] = true;
				}
			}
			else if(direc == -1) {
				//반시계방향회전
				r1 = RL(r1);
				turn[1][0] = true;
				if (turn[0][1] == true && turn[1][0] == true) {
					r2 = RR(r2);
					turn[1][1] = true;
				}
				if (turn[0][2] == true && turn[1][1] == true) {
					r3 = RL(r3);
					turn[1][2] = true;
				}
				if (turn[0][3] == true && turn[1][2] == true) {
					r4 = RR(r4);
					turn[1][3] = true;
				}
			}
			break;

		case 2:
			//2->(1 -> 3) -> 4
			//회전유무 먼저 판단
			turn[0][1] = true;
			if (r1[2] != r2[6]) {
				turn[0][0] = true;
			}
			if (r2[2] != r3[6]) {
				turn[0][2] = true;
			}
			if (r3[2] != r4[6]) {
				turn[0][3] = true;
			}
			if (direc == 1) {
				//시계방향 회전
				r2 = RR(r2);
				turn[1][1] = true;
				if (turn[0][0] == true && turn[1][1] == true) {
					r1 = RL(r1);
					turn[1][0] = true;
				}
				if (turn[0][2] == true && turn[1][1] == true) {
					r3 = RL(r3);
					turn[1][2] = true;
				}
				if (turn[0][3] == true && turn[1][2] == true) {
					r4 = RR(r4);
					turn[1][3] = true;
				}
			}
			else if (direc == -1) {
				//반시계방향회전
				r2 = RL(r2);
				turn[1][1] = true;
				if (turn[0][0] == true && turn[1][1] == true) {
					r1 = RR(r1);
					turn[1][0] = true;
				}
				if (turn[0][2] == true && turn[1][1] == true) {
					r3 = RR(r3);
					turn[1][2] = true;
				}
				if (turn[0][3] == true && turn[1][2] == true) {
					r4 = RL(r4);
					turn[1][3] = true;
				}
			}
			break;

		case 3:
			//3 -> (4->2) ->1
			//회전유무 먼저 판단
			turn[0][2] = true;
			if (r1[2] != r2[6]) {
				turn[0][0] = true;
			}
			if (r2[2] != r3[6]) {
				turn[0][1] = true;
			}
			if (r3[2] != r4[6]) {
				turn[0][3] = true;
			}
			if (direc == 1) {
				//시계방향 회전
				r3 = RR(r3);
				turn[1][2] = true;
				if (turn[0][3] == true && turn[1][2] == true) {
					r4 = RL(r4);
					turn[1][3] = true;
				}
				if (turn[0][1] == true && turn[1][2] == true) {
					r2 = RL(r2);
					turn[1][1] = true;
				}
				if (turn[0][0] == true && turn[1][1] == true) {
					r1 = RR(r1);
					turn[1][0] = true;
				}
			}
			else if (direc == -1) {
				//반시계방향회전
				r3 = RL(r3);
				turn[1][2] = true;
				if (turn[0][3] == true && turn[1][2] == true) {
					r4 = RR(r4);
					turn[1][3] = true;
				}
				if (turn[0][1] == true && turn[1][2] == true) {
					r2 = RR(r2);
					turn[1][1] = true;
				}
				if (turn[0][0] == true && turn[1][1] == true) {
					r1 = RL(r1);
					turn[1][0] = true;
				}
			}
			break;

		case 4:
			//4->3->2->1
			//회전유무 먼저 판단
			turn[0][3] = true;
			if (r1[2] != r2[6]) {
				turn[0][0] = true;
			}
			if (r2[2] != r3[6]) {
				turn[0][1] = true;
			}
			if (r3[2] != r4[6]) {
				turn[0][2] = true;
			}
			if (direc == 1) {
				//시계방향 회전
				r4 = RR(r4);
				turn[1][3] = true;
				if (turn[0][2] == true && turn[1][3] == true) {
					r3 = RL(r3);
					turn[1][2] = true;
				}
				if (turn[0][1] == true && turn[1][2] == true) {
					r2 = RR(r2);
					turn[1][1] = true;
				}
				if (turn[0][0] == true && turn[1][1] == true) {
					r1 = RL(r1);
					turn[1][0] = true;
				}
			}
			else if (direc == -1) {
				//반시계방향회전
				r4 = RL(r4);
				turn[1][3] = true;
				if (turn[0][2] == true && turn[1][3] == true) {
					r3 = RR(r3);
					turn[1][2] = true;
				}
				if (turn[0][1] == true && turn[1][2] == true) {
					r2 = RL(r2);
					turn[1][1] = true;
				}
				if (turn[0][0] == true && turn[1][1] == true) {
					r1 = RR(r1);
					turn[1][0] = true;
				}
			}
			break;
		}

	}
	//calculate points
	if (r1[0] == '1')
		points += 1;
	if (r2[0] == '1')
		points += 2;
	if (r3[0] == '1')
		points += 4;
	if (r4[0] == '1')
		points += 8;

	cout << points;


}
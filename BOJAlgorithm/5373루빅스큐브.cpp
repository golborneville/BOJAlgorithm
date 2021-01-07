#include<iostream>
#include<string>
using namespace std;
//0:red - 앞(F)  1:orange - 뒷(B) 
//2:green - 왼쪽(L)  3:blue - 오른쪽(R)  
//4:yellow- 아래(D)   5:white - 위(U)

int cube[6][9];
//init: 0:0(r) 1;! 2:2 3:3 4:4 5:5 
void rotateClockwise(int side) { //매개변수 면 번호
	//시계방향
	int tmp[9];
	for (int i = 0; i < 9; i++) {
		tmp[i] = cube[side][i]; //temp copy
	}
	cube[side][0] = tmp[6];
	cube[side][1] = tmp[3];
	cube[side][2] = tmp[0];
	cube[side][3] = tmp[7];
	cube[side][4] = tmp[4];
	cube[side][5] = tmp[1];
	cube[side][6] = tmp[8];
	cube[side][7] = tmp[5];
	cube[side][8] = tmp[2];

}
void rotateCounterClock(int side) {
	//시계 반대 방향
	int tmp[9];
	for (int i = 0; i < 9; i++) {
		tmp[i] = cube[side][i]; //temp copy
	}
	cube[side][0] = tmp[2];
	cube[side][1] = tmp[5];
	cube[side][2] = tmp[8];
	cube[side][3] = tmp[1];
	cube[side][4] = tmp[4];
	cube[side][5] = tmp[7];
	cube[side][6] = tmp[0];
	cube[side][7] = tmp[3];
	cube[side][8] = tmp[6];

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, T;
	string rot;

	cin >> T;//testcase number
	while (T--) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 9; j++) {
				cube[i][j] = i;
			}
		}

		cin >> N; //회전 횟수
		for (int i = 0; i < N; i++) {
			cin >> rot; // 회전면 & 방향
			char side = rot[0];
			char dir = rot[1];
			switch (side)
			{
			case 'U'://윗면   5
				if (dir == '+') { //시계방향
					rotateClockwise(5);
					int tmp[3];
					//side 0 temp save
					tmp[0] = cube[0][0];
					tmp[1] = cube[0][1];
					tmp[2] = cube[0][2];

					//3->0
					cube[0][0] = cube[3][0];
					cube[0][1] = cube[3][1];
					cube[0][2] = cube[3][2];

					//1->3
					cube[3][0] = cube[1][0];
					cube[3][1] = cube[1][1];
					cube[3][2] = cube[1][2];

					//2->1
					cube[1][0] = cube[2][0];
					cube[1][1] = cube[2][1];
					cube[1][2] = cube[2][2];

					//0->2
					cube[2][0] = tmp[0];
					cube[2][1] = tmp[1];
					cube[2][2] = tmp[2];

				}
				else if (dir == '-') { //시계반대방향
					rotateCounterClock(5);
					int tmp[3];
					//side 1 temp save
					tmp[0] = cube[1][0];
					tmp[1] = cube[1][1];
					tmp[2] = cube[1][2];

					//3->1
					cube[1][0] = cube[3][0];
					cube[1][1] = cube[3][1];
					cube[1][2] = cube[3][2];

					//0->3
					cube[3][0] = cube[0][0];
					cube[3][1] = cube[0][1];
					cube[3][2] = cube[0][2];

					//2->0
					cube[0][0] = cube[2][0];
					cube[0][1] = cube[2][1];
					cube[0][2] = cube[2][2];

					//1->2
					cube[2][0] = tmp[0];
					cube[2][1] = tmp[1];
					cube[2][2] = tmp[2];
				}
				break;
			case 'D': // 아랫면   4
				if (dir == '+') { //시계방향
					rotateClockwise(4);
					int tmp[3];
					//side 3 temp save
					tmp[0] = cube[3][6];
					tmp[1] = cube[3][7];
					tmp[2] = cube[3][8];

					//0->3
					cube[3][6] = cube[0][6];
					cube[3][7] = cube[0][7];
					cube[3][8] = cube[0][8];

					//2->0
					cube[0][6] = cube[2][6];
					cube[0][7] = cube[2][7];
					cube[0][8] = cube[2][8];

					//1->2
					cube[2][6] = cube[1][6];
					cube[2][7] = cube[1][7];
					cube[2][8] = cube[1][8];

					//3->1
					cube[1][6] = tmp[0];
					cube[1][7] = tmp[1];
					cube[1][8] = tmp[2];



				}
				else if (dir == '-') { //시계반대방향
					rotateCounterClock(4);
					int tmp[3];
					//side 3 temp save
					tmp[0] = cube[3][6];
					tmp[1] = cube[3][7];
					tmp[2] = cube[3][8];

					//1->3
					cube[3][6] = cube[1][6];
					cube[3][7] = cube[1][7];
					cube[3][8] = cube[1][8];

					//2->1
					cube[1][6] = cube[2][6];
					cube[1][7] = cube[2][7];
					cube[1][8] = cube[2][8];

					//0->2
					cube[2][6] = cube[0][6];
					cube[2][7] = cube[0][7];
					cube[2][8] = cube[0][8];

					//3->0
					cube[0][6] = tmp[0];
					cube[0][7] = tmp[1];
					cube[0][8] = tmp[2];
				}
				break;
			case 'F': // 앞면 0 
				if (dir == '+') { //시계방향
					rotateClockwise(0);
					int tmp[3];
					//side 2 temp save
					tmp[0] = cube[2][2];
					tmp[1] = cube[2][5];
					tmp[2] = cube[2][8];

					//4->2
					cube[2][2] = cube[4][0];
					cube[2][5] = cube[4][1];
					cube[2][8] = cube[4][2];

					//3->4
					cube[4][0] = cube[3][6];
					cube[4][1] = cube[3][3];
					cube[4][2] = cube[3][0];

					//5->3
					cube[3][0] = cube[5][6];
					cube[3][3] = cube[5][7];
					cube[3][6] = cube[5][8];

					//2->5
					cube[5][8] = tmp[0];
					cube[5][7] = tmp[1];
					cube[5][6] = tmp[2];

				}
				else if (dir == '-') { //시계반대방향
					rotateCounterClock(0);
					int tmp[3];
					//side 2 temp save
					tmp[0] = cube[2][2];
					tmp[1] = cube[2][5];
					tmp[2] = cube[2][8];

					//5->2
					cube[2][2] = cube[5][8];
					cube[2][5] = cube[5][7];
					cube[2][8] = cube[5][6];

					//3->5
					cube[5][6] = cube[3][0];
					cube[5][7] = cube[3][3];
					cube[5][8] = cube[3][6];

					//4->3
					cube[3][0] = cube[4][2];
					cube[3][3] = cube[4][1];
					cube[3][6] = cube[4][0];

					//2->4
					cube[4][0] = tmp[0];
					cube[4][1] = tmp[1];
					cube[4][2] = tmp[2];
				}
				break;
			case 'B': //뒷면 1
				if (dir == '+') { //시계방향
					rotateClockwise(1);
					int tmp[3];
					//side 2 temp save
					tmp[0] = cube[2][0];
					tmp[1] = cube[2][3];
					tmp[2] = cube[2][6];

					//5->2
					cube[2][0] = cube[5][2];
					cube[2][3] = cube[5][1];
					cube[2][6] = cube[5][0];

					//3->5
					cube[5][0] = cube[3][2];
					cube[5][1] = cube[3][5];
					cube[5][2] = cube[3][8];

					//4->3
					cube[3][2] = cube[4][8];
					cube[3][5] = cube[4][7];
					cube[3][8] = cube[4][6];

					//2->4
					cube[4][6] = tmp[0];
					cube[4][7] = tmp[1];
					cube[4][8] = tmp[2];
				}
				else if (dir == '-') { //시계반대방향
					rotateCounterClock(1);
					int tmp[3];
					//side 2 temp save
					tmp[0] = cube[2][0];
					tmp[1] = cube[2][3];
					tmp[2] = cube[2][6];

					//4->2
					cube[2][0] = cube[4][6];
					cube[2][3] = cube[4][7];
					cube[2][6] = cube[4][8];

					//3->4
					cube[4][6] = cube[3][8];
					cube[4][7] = cube[3][5];
					cube[4][8] = cube[3][2];

					//5->3
					cube[3][2] = cube[5][0];
					cube[3][5] = cube[5][1];
					cube[3][8] = cube[5][2];

					//2->5
					cube[5][2] = tmp[0];
					cube[5][1] = tmp[1];
					cube[5][0] = tmp[2];
				}
				break;
			case 'L': // 왼쪽면 2 
				if (dir == '+') { //시계방향
					rotateClockwise(2);
					int tmp[3];
					//side 1 temp save
					tmp[0] = cube[1][2];
					tmp[1] = cube[1][5];
					tmp[2] = cube[1][8];

					//4->1
					cube[1][2] = cube[4][6];
					cube[1][5] = cube[4][3];
					cube[1][8] = cube[4][0];

					//0->4
					cube[4][0] = cube[0][0];
					cube[4][3] = cube[0][3];
					cube[4][6] = cube[0][6];

					//5->0
					cube[0][0] = cube[5][0];
					cube[0][3] = cube[5][3];
					cube[0][6] = cube[5][6];

					//1->5
					cube[5][6] = tmp[0];
					cube[5][3] = tmp[1];
					cube[5][0] = tmp[2];
				}
				else if (dir == '-') { //시계반대방향
					rotateCounterClock(2);
					int tmp[3];
					//side 1 temp save
					tmp[0] = cube[1][2];
					tmp[1] = cube[1][5];
					tmp[2] = cube[1][8];

					//5->1
					cube[1][2] = cube[5][6];
					cube[1][5] = cube[5][3];
					cube[1][8] = cube[5][0];

					//0->5
					cube[5][0] = cube[0][0];
					cube[5][3] = cube[0][3];
					cube[5][6] = cube[0][6];

					//4->0
					cube[0][0] = cube[4][0];
					cube[0][3] = cube[4][3];
					cube[0][6] = cube[4][6];

					//1->4
					cube[4][6] = tmp[0];
					cube[4][3] = tmp[1];
					cube[4][0] = tmp[2];
				}
				break;
			case 'R': //오른쪽 면   3
				if (dir == '+') { //시계방향
					rotateClockwise(3);
					int tmp[3];
					//side 0 temp save
					tmp[0] = cube[0][2];
					tmp[1] = cube[0][5];
					tmp[2] = cube[0][8];

					//4->0
					cube[0][2] = cube[4][2];
					cube[0][5] = cube[4][5];
					cube[0][8] = cube[4][8];

					//1->4
					cube[4][8] = cube[1][0];
					cube[4][5] = cube[1][3];
					cube[4][2] = cube[1][6];

					//5->1
					cube[1][0] = cube[5][8];
					cube[1][3] = cube[5][5];
					cube[1][6] = cube[5][2];

					//0->5
					cube[5][2] = tmp[0];
					cube[5][5] = tmp[1];
					cube[5][8] = tmp[2];
				}
				else if (dir == '-') { //시계반대방향
					rotateCounterClock(3);
					int tmp[3];
					//side 0 temp save
					tmp[0] = cube[0][2];
					tmp[1] = cube[0][5];
					tmp[2] = cube[0][8];

					//5->0
					cube[0][2] = cube[5][2];
					cube[0][5] = cube[5][5];
					cube[0][8] = cube[5][8];

					//1->5
					cube[5][8] = cube[1][0];
					cube[5][5] = cube[1][3];
					cube[5][2] = cube[1][6];

					//4->1
					cube[1][0] = cube[4][8];
					cube[1][3] = cube[4][5];
					cube[1][6] = cube[4][2];

					//0->4
					cube[4][2] = tmp[0];
					cube[4][5] = tmp[1];
					cube[4][8] = tmp[2];
				}
				break;
			}
		}
		for (int i = 0; i < 9; i++) {
			int n = cube[5][i];
			char an;
			if (n == 0) {
				an ='r';
			}
			else if (n == 1) {
				an = 'o';
			}
			else if (n == 2) {
				an = 'g';
			}
			else if (n == 3) {
				an = 'b';
			}
			else if (n == 4) {
				an = 'y';
			}
			else if (n == 5) {
				an = 'w';
			}
			cout << an;
			if ((i + 1) % 3 == 0) cout << "\n";
		}


	}
	return 0;
}
#include<iostream>
using namespace std;

int color[25]; //1~24 사용
int tmp[25]; //이동후 기준
bool chk() {
	//tmp 기준 체크
	for (int i = 1; i <= 24; i += 4) {
		if (!(tmp[i] == tmp[i + 1] && tmp[i] == tmp[i + 2] && tmp[i] == tmp[i + 3])) {
			return false;
		}

	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool result;
	bool flag = true;
	for (int i = 1; i <= 24; i++) {
		cin >> color[i];
		tmp[i] = color[i];
	}
	//5678  을 앞면 기준으로 총 8가지 경우 
	//UP(LEFT)
	//1->2
	tmp[1] = color[5];
	tmp[3] = color[7];
	//2->3
	tmp[22] = color[1];
	tmp[24] = color[3];
	//3->4
	tmp[11] = color[22];
	tmp[9] = color[24];
	//4->1
	tmp[5] = color[11];
	tmp[7] = color[9];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}


	//UP(right)
	//1->2
	tmp[2] = color[6];
	tmp[4] = color[8];
	//2->3
	tmp[21] = color[2];
	tmp[23] = color[4];
	//3->4
	tmp[12] = color[21];
	tmp[10] = color[23];
	//4->1
	tmp[6] = color[12];
	tmp[8] = color[10];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}


	//DOWN(LEFT)
	//1->4
	tmp[11] = color[5];
	tmp[9] = color[7];
	//4->3
	tmp[22] = color[11];
	tmp[24] = color[9];
	//3->2
	tmp[1] = color[22];
	tmp[3] = color[24];
	//2->1
	tmp[5] = color[1];
	tmp[7] = color[3];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}


	//DOWN(RIGHT)
	//1->4
	tmp[12] = color[6];
	tmp[10] = color[8];
	//4->3
	tmp[21] = color[12];
	tmp[23] = color[10];
	//3->2
	tmp[2] = color[21];
	tmp[4] = color[23];
	//2->1
	tmp[6] = color[2];
	tmp[8] = color[4];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}


	//RIGHT(TOP)
	//1->6
	tmp[17] = color[5];
	tmp[18] = color[6];
	//6->3
	tmp[22] = color[17];
	tmp[21] = color[18];
	//3->5
	tmp[13] = color[22];
	tmp[14] = color[21];
	//5->1
	tmp[5] = color[13];
	tmp[6] = color[14];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}

	//RIGHT(BOTTOM)
	//1->6
	tmp[19] = color[7];
	tmp[20] = color[8];
	//6->3
	tmp[24] = color[19];
	tmp[23] = color[20];
	//3->5
	tmp[15] = color[24];
	tmp[16] = color[23];
	//5->1
	tmp[7] = color[15];
	tmp[8] = color[16];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}

	//LEFT(TOP)
	//1->5
	tmp[13] = color[5];
	tmp[14] = color[6];
	//5->3
	tmp[22] = color[13];
	tmp[21] = color[14];
	//3->6
	tmp[17] = color[22];
	tmp[18] = color[21];
	//6->1
	tmp[5] = color[17];
	tmp[6] = color[18];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}

	//LEFT(BOTTOM)
	//1->5
	tmp[15] = color[7];
	tmp[16] = color[8];
	//5->3
	tmp[24] = color[15];
	tmp[23] = color[16];
	//3->6
	tmp[19] = color[24];
	tmp[20] = color[23];
	//6->1
	tmp[7] = color[19];
	tmp[8] = color[20];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}


	//6기준 UP/DOWN

	//UP(LEFT)
	//6->2
	tmp[3] = color[17];
	tmp[4] = color[19];
	//2->5
	tmp[16] = color[3];
	tmp[14] = color[4];
	//5->4
	tmp[9] = color[14];
	tmp[10] = color[16];
	//4->6
	tmp[19] = color[9];
	tmp[17] = color[10];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}

	//UP(RIGHT)
	//6->2
	tmp[1] = color[18];
	tmp[2] = color[20];
	//2->5
	tmp[15] = color[1];
	tmp[13] = color[2];
	//5->4
	tmp[11] = color[13];
	tmp[12] = color[15];
	//4->6
	tmp[20] = color[11];
	tmp[18] = color[12];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}


	//DOWN(LEFT)
	//6->4
	tmp[10] = color[17];
	tmp[9] = color[19];
	//4->5
	tmp[14] = color[9];
	tmp[16] = color[10];
	//5->2
	tmp[4] = color[14];
	tmp[3] = color[16];
	//2->6
	tmp[17] = color[3];
	tmp[19] = color[4];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= 24; i++) {
		tmp[i] = color[i];
	}


	//DOWN(RIGHT)
	//6->4
	tmp[12] = color[18];
	tmp[11] = color[20];
	//4->5
	tmp[13] = color[11];
	tmp[15] = color[12];
	//5->2
	tmp[2] = color[13];
	tmp[1] = color[15];
	//2->6
	tmp[18] = color[1];
	tmp[20] = color[2];
	result = chk();
	if (result) {
		cout << 1;
		return 0;
	}
	


	cout << 0;
	return 0;

}
#include<iostream>
#include<cstring>
using namespace std;

int wincnt[6]; //A ~ F 0~ 5
int drawcnt[6];
int losecnt[6];
bool result = false;

void tournament(int ind) {
	int n1list[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
	int n2list[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
	if (ind >= 15) {
		result = true;
		return;
	}
	if (result) return;


	//win
	if (wincnt[n1list[ind]] > 0 && losecnt[n2list[ind]] > 0) {
		wincnt[n1list[ind]]--;
		losecnt[n2list[ind]]--;
		tournament(ind + 1);
		wincnt[n1list[ind]]++;
		losecnt[n2list[ind]]++;
	}

	if (drawcnt[n1list[ind]] > 0 && drawcnt[n2list[ind]] > 0){
		//draw
		drawcnt[n1list[ind]]--;
		drawcnt[n2list[ind]]--;
		tournament(ind + 1);
		drawcnt[n1list[ind]]++;
		drawcnt[n2list[ind]]++;
	}
	if (wincnt[n2list[ind]] > 0 && losecnt[n1list[ind]] > 0) {
		//lose
		wincnt[n2list[ind]]--;
		losecnt[n1list[ind]]--;
		tournament(ind + 1);
		wincnt[n2list[ind]]++;
		losecnt[n1list[ind]]++;
	}
}
int main() {
	int T = 4;
	
	while (T--) {
		int sw = 0, sd = 0, sl = 0;
		result = false;


		for (int i = 0; i < 6; i++) {
			cin >> wincnt[i];
			sw += wincnt[i];
			cin >> drawcnt[i];
			sd += drawcnt[i];
			cin >> losecnt[i];
			sl += losecnt[i];

		}
		if (sw + sd + sl != 30) {
			cout << 0 << " ";
			//return 0;
			continue;
		}
		tournament(0);
		
		if (result) cout << 1 << " ";
		else cout << 0 << " ";
		
		memset(wincnt, 0, sizeof(wincnt));
		memset(drawcnt, 0, sizeof(drawcnt));
		memset(losecnt, 0, sizeof(losecnt));
	}
}
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N, K;
int inn[203]; //up and down
//vector<int> robo; //robot 위치 인덱스 값
map<int, int> robo; //order , robo existing index
int Rorder = 0;
bool chkrobo[103];
int cur0 = 0;
void takeStage() {
	//1.step1-1 ; rotate belt
	int tmp = inn[2*N];
	for (int i = 2*N; i > 1; i--) {
		inn[i] = inn[i-1];
	}
	inn[1] = tmp;


	vector<int> tmperase; //map's keyvalue
	//1. step1-2 move robo val-> 땅에 내려가는 로봇들 처리 (inval 변화X)
	for (auto i = robo.begin(); i != robo.end(); i++) {
		if ( i->second < N) {
			chkrobo[i->second] = false;
			chkrobo[i->second + 1 ] = true;
			i->second = i->second + 1;//위에서 다음 칸으로 벨트랑 같이 이동
		}
		else if (i->second == N) { // go to ground
			//로봇 사라짐.....vector쟈 나이?O(N) 은 투머치 시간
			chkrobo[i->second] = false;
			//robo.erase(i);
			tmperase.push_back(i->first);
		}
	}
	for (int i = 0; i < tmperase.size(); i++) {
		robo.erase(tmperase[i]);
	}
	tmperase.clear();


	//2.step : move available robots (in val 변화 OOOOO)
	//cond: 1. inn[i] val >= 1 && no robot there (로봇 탐색 순서는 벨트에 올라간 순서대로) 
	//동시에 ##move and inn[i] val--;

	
	for (auto i = robo.begin(); i != robo.end(); i++) {
		if (i->second < N) {
			//벨트 위 로봇들
			if (inn[i->second + 1] >= 1 && chkrobo[i->second + 1] == false) {//위에서 다음 칸으로 벨트랑 같이 이동
				chkrobo[i->second] = false;
				chkrobo[i->second + 1] = true;
				i->second = i->second + 1;//위에서 다음 칸으로 벨트랑 같이 이동
				if (--inn[i->second] == 0) cur0++;
			}
		}
		else if (i->second == N) {
			chkrobo[i->second] = false;
			//robo.erase(i);
			tmperase.push_back(i->first);
		}
	}
	for (int i = 0; i < tmperase.size(); i++) {
		robo.erase(tmperase[i]);
	}
	tmperase.clear();


	//3.step : add robo on belt
	if (!chkrobo[1] && inn[1] >= 1) {
		//add robo on [1]
		robo.insert({ Rorder++, 1 });
		chkrobo[1] = true;
		if (--inn[1] == 0) cur0++;
	}


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int stage = 0;
	cin >> N >> K;
	for (int i = 1; i <= 2*N; i++) {
		cin >> inn[i]; //1~N
	}
	while (cur0 < K) {
		stage++;
		takeStage();
	}
	cout << stage;
	return 0;
}
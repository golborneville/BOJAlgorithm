#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

int N; //�Ѻ� Ÿ�� ����
struct tile {
	int tileNum;
	int left;
	int right;
	int prev; //������ �ִ� Ÿ���� ��ȣ
};
int maxtileNum = 1;
vector<int> tilenum[502];
tile arr[250003];
bool chk[250003]; //tile chk 
int resnum[250003]; //���....�ּ� Ƚ��
queue<pair<int, pair<int, int>>> qu; //Ÿ�� ��ȣ, {Ÿ���� ���� �ȿ���i,j ��}
stack<int> road; //��� Ÿ�� ��ȣ!
void BFS() {
	//1�� Ÿ�Ϻ��� Ž�� ���� �� ������.
	chk[1] = true;
	//chk[1].second = true;

	while (!qu.empty()) {
		int tileN = qu.front().first;
		int vecx = qu.front().second.first;
		int vecy = qu.front().second.second;
		qu.pop();

		//������ ���� üũ!
		//���� ���� ���� üũ
		if (vecy - 1 >= 0) {
			if (arr[tilenum[vecx][vecy-1]].right == arr[tileN].left && !chk[tilenum[vecx][vecy-1]]) {
				//���� ������ -> �Ʒ� Ÿ���� ���� �̶� �� (���� ���ڸ� �̵�����)
				chk[tilenum[vecx][vecy - 1]] = true;
				arr[tilenum[vecx][vecy - 1]].prev = tileN;
				qu.push({ tilenum[vecx][vecy - 1],{ vecx, vecy - 1} });
				if (maxtileNum < tilenum[vecx][vecy - 1])maxtileNum = tilenum[vecx][vecy - 1];
			}
		}
		

		//�� �Ʒ� Ž��
		if (vecx % 2 == 0) {
			//¦����? 0 2 4...
			//�� Ÿ���� Ȧ�� �� (N-1�� ���� Ÿ��)
			//���� Ÿ���� ������üũ!-> Ȧ�� �� ¦�� �ٿ� ���� �޶��� 
			if (vecy + 1 < N) {
				if (arr[tilenum[vecx][vecy + 1]].left == arr[tileN].right && !chk[tilenum[vecx][vecy + 1]]) {
					//���� ������ -> �Ʒ� Ÿ���� ���� �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx][vecy + 1]] = true;
					arr[tilenum[vecx][vecy + 1]].prev = tileN;
					qu.push({ tilenum[vecx][vecy + 1],{ vecx, vecy + 1 } });
					if (maxtileNum < tilenum[vecx][vecy + 1])maxtileNum = tilenum[vecx][vecy + 1];
				}
			}

			//������ ���� Ž�� �߰� 
			if (vecx + 1 < N && vecy  < N - 1 ){
				if (arr[tilenum[vecx + 1][vecy]].left == arr[tileN].right && !chk[tilenum[vecx + 1][vecy]]) {
					//���� ������ -> �Ʒ� Ÿ���� ���� �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx + 1][vecy]] = true;
					arr[tilenum[vecx + 1][vecy]].prev = tileN;
					qu.push({ tilenum[vecx + 1][vecy],{vecx +1, vecy} });
					if (maxtileNum < tilenum[vecx + 1][vecy])maxtileNum = tilenum[vecx + 1][vecy];
				}
				
			}
			if (vecx - 1 >=0 && vecy  < N - 1) {
				if (arr[tilenum[vecx -1][vecy]].left == arr[tileN].right && !chk[tilenum[vecx - 1][vecy]]) {
					//���� ������ -> �� Ÿ���� ���� �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx - 1][vecy]] = true;
					arr[tilenum[vecx - 1][vecy]].prev = tileN;
					qu.push({ tilenum[vecx - 1][vecy],{ vecx - 1, vecy } });
					if (maxtileNum < tilenum[vecx - 1][vecy])maxtileNum = tilenum[vecx - 1][vecy];
				}

			}
			//���� ���� Ž�� �߰�
			if (vecx + 1 < N && vecy-1 >=0 && vecy  < N) {
				if (arr[tilenum[vecx + 1][vecy - 1]].right == arr[tileN].left && !chk[tilenum[vecx + 1][vecy - 1]]) {
					//���� ���� -> �Ʒ� Ÿ���� ������ �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx + 1][vecy - 1]] = true;
					arr[tilenum[vecx + 1][vecy - 1]].prev = tileN;
					qu.push({ tilenum[vecx + 1][vecy-1],{ vecx + 1, vecy-1 } });
					if (maxtileNum < tilenum[vecx + 1][vecy - 1])maxtileNum = tilenum[vecx + 1][vecy - 1];
				}
			}
			if (vecx - 1 >= 0 && vecy - 1 >= 0 && vecy < N) {
				if (arr[tilenum[vecx - 1][vecy - 1]].right == arr[tileN].left && !chk[tilenum[vecx - 1][vecy - 1]]) {
					//���� ���� -> �� Ÿ���� ������ �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx - 1][vecy - 1]] = true;
					arr[tilenum[vecx - 1][vecy - 1]].prev = tileN;
					qu.push({ tilenum[vecx - 1][vecy-1],{ vecx - 1, vecy-1 } });
					if (maxtileNum < tilenum[vecx - 1][vecy - 1])maxtileNum = tilenum[vecx - 1][vecy - 1];
				}
			}
		}
		//Ȧ����
		else if (vecx % 2 != 0) {

			//���� Ÿ���� ������üũ!-> Ȧ�� �� ¦�� �ٿ� ���� �޶��� 
			if (vecy + 1 < N-1) {
				if (arr[tilenum[vecx][vecy + 1]].left == arr[tileN].right && !chk[tilenum[vecx][vecy + 1]]) {
					//���� ������ -> �Ʒ� Ÿ���� ���� �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx][vecy + 1]] = true;
					arr[tilenum[vecx][vecy + 1]].prev = tileN;
					qu.push({ tilenum[vecx][vecy + 1],{ vecx, vecy + 1 } });
					if (maxtileNum < tilenum[vecx][vecy + 1])maxtileNum = tilenum[vecx][vecy + 1];
				}
			}

			//������ ���� Ž�� �߰� 
			if (vecx + 1 < N) {
				if (arr[tilenum[vecx + 1][vecy]].right == arr[tileN].left && !chk[tilenum[vecx + 1][vecy]]) {
					//���� ���� -> �Ʒ� Ÿ���� ������ �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx + 1][vecy]] = true;
					arr[tilenum[vecx + 1][vecy]].prev = tileN;
					qu.push({ tilenum[vecx + 1][vecy],{ vecx + 1, vecy } });
					if (maxtileNum < tilenum[vecx + 1][vecy])maxtileNum = tilenum[vecx + 1][vecy];
				}

			}
			if (vecx - 1 >= 0) {
				if (arr[tilenum[vecx - 1][vecy]].right == arr[tileN].left && !chk[tilenum[vecx - 1][vecy]]) {
					//���� ���� -> �� Ÿ���� ������ �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx - 1][vecy]] = true;
					arr[tilenum[vecx - 1][vecy]].prev = tileN;
					qu.push({ tilenum[vecx - 1][vecy],{ vecx - 1, vecy } });
					if (maxtileNum < tilenum[vecx - 1][vecy])maxtileNum = tilenum[vecx - 1][vecy];
				}

			}
			//���� ���� Ž�� �߰�
			if (vecx - 1 >=0 && vecy + 1 <N) {
				if (arr[tilenum[vecx - 1][vecy + 1]].left == arr[tileN].right && !chk[tilenum[vecx - 1][vecy + 1]]) {
					//���� ������ -> �� Ÿ���� ���� �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx - 1][vecy + 1]] = true;
					arr[tilenum[vecx - 1][vecy + 1]].prev = tileN;
					qu.push({ tilenum[vecx - 1][vecy + 1],{ vecx - 1, vecy + 1 } });
					if (maxtileNum < tilenum[vecx - 1][vecy + 1])maxtileNum = tilenum[vecx - 1][vecy + 1];
				}
			}
			if (vecx + 1 <N && vecy + 1 <N) {
				if (arr[tilenum[vecx + 1][vecy + 1]].left == arr[tileN].right && !chk[tilenum[vecx + 1][vecy + 1]]) {
					//���� ������ -> �Ʒ� Ÿ���� ���� �̶� �� (���� ���ڸ� �̵�����)
					chk[tilenum[vecx + 1][vecy + 1]] = true;
					arr[tilenum[vecx + 1][vecy + 1]].prev = tileN;
					qu.push({ tilenum[vecx + 1][vecy + 1],{ vecx + 1, vecy + 1 } });
					if (maxtileNum < tilenum[vecx + 1][vecy + 1])maxtileNum = tilenum[vecx + 1][vecy + 1];
				}
			}
		}

	}
}

int getWay() {
	int tile = arr[maxtileNum].tileNum;
	int cnt = 0;
	while (arr[tile].tileNum != 0) {
		road.push(tile);
		cnt++;
		tile = arr[tile].prev;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	//index 1~ N*N - N/2
	for (int i = 1; i <= N*N - N/2; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		arr[i] = { i, num1, num2, 0 }; // ������ �迭�� �Է�
	}
	int ind = 1;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				tilenum[i].push_back(arr[ind].tileNum);
				ind++;
			}
		}
		else if (i % 2 != 0) {
			for (int j = 0; j < N-1; j++) {
				tilenum[i].push_back(arr[ind].tileNum);
				ind++;
			}
		}
	}
	qu.push({ 1,{0,0} });
	BFS();
	int numtile = getWay(); //Ÿ�� ���� 
	cout << numtile << "\n";
	while (!road.empty()) {
		cout << road.top() << " ";
		road.pop();
	}

	return 0;
}
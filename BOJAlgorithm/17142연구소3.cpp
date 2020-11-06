#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int turntovirus = 0;
int virus;
int lab[53][53];
int chk[53][53];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int minumun = 987654321; //��ü �ּ� �ð�
bool possible = false;
queue<pair<int, int>> q;
vector<pair<int, int>> bb; //��ü ���̷��� ���°� ���� �ð�
int BFS() {
	int maxtime = 1;
	
	
	//ó�� ���� ��ǥ�� �Ѱ��� �ƴ϶� ������ �ϼ� ���� ���ľ���
	//chk[x][y] = 1; //total -1 ������� (������ 1�̶�)
	//q.push({ x,y });
	//turntovirus++;
 	while (!q.empty()) {
		pair<int, int> node = q.front();
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (!chk[nx][ny] && lab[nx][ny] != 1 ) {
				//if (lab[nx][ny] == 2) chk[nx][ny] = chk[node.first][node.second];
				chk[nx][ny] = chk[node.first][node.second] + 1;
				if (lab[nx][ny] != 2)
				{
					turntovirus++;
				}
				if (lab[nx][ny] == 2)
				{
					int cnt = 0;
					for (int b = 0; b < 4; b++) {
						int nnx = nx + dx[b];
						int nny = ny + dy[b];
						if (nnx < 0 || nny < 0 || nnx >= N || nny >= N)continue;
						if (!chk[nnx][nny] && lab[nnx][nny] != 1) cnt++;

					}
					if (!cnt) {
						chk[nx][ny]--;
						
					}
				}
				if (chk[nx][ny] > maxtime) maxtime = chk[nx][ny];
				if(turntovirus == virus) return maxtime - 1;
				//lab[nx][ny] = 2; 
				q.push({ nx, ny });

			}
		}
	}
	return maxtime - 1;


}
void makeGroup(int k) {
	//NCk
	//bb is �������� ���� ������ ������ ��������
	int ind_arr[10] = { 0, 1,2,3,4,5,6,7,8,9}; //bb�� �ε���!!!!) �� k���� ���õȾֵ�
	int indindarr[10] = { 0, 0,0,0,0,0,0,0,0,0 };
	for (int f = bb.size()-k; f < bb.size(); f++) {
		if(f)
		indindarr[f] = 1;
	}
	
	do { //�� �ù� �� ������ �ƴ϶� ������ ���������

		/*for (int f = 0; f < k; f++) {
			q.push(bb[ind_arr[f]]);
			chk[bb[ind_arr[f]].first][bb[ind_arr[f]].second] = 1;
		}
		for (int f = k; f < bb.size(); f++) {
			chk[bb[ind_arr[f]].first][bb[ind_arr[f]].second] = 1;
			turntovirus++;
		}
		*/
		//for (int f = 0; f < bb.size(); f++) {
		//	if(indindarr[f] == 1)
		//		cout << f << " ";
		//}
		//cout << "\n";
		for (int f = 0; f < bb.size(); f++) {
			//if (indindarr[f] == 0) {
				//chk[bb[ind_arr[f]].first][bb[ind_arr[f]].second] = 1;
				//turntovirus++;
			//}
			//else {
			if (indindarr[f] == 1) {
				q.push(bb[ind_arr[f]]);
				chk[bb[ind_arr[f]].first][bb[ind_arr[f]].second] = 1;
				//}
			}
		}
		int xxmin = BFS();
		if (turntovirus == virus) {
			possible = true; //true �ѹ��̶� ������ ���� 
			if (xxmin < minumun) minumun = xxmin;
		
		}
		turntovirus = 0;
		memset(chk, 0, sizeof(chk));
		while (!q.empty()) { q.pop(); }
	} while (next_permutation(indindarr, indindarr + bb.size()));

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	virus = N*N; //���� ������ ��� ĭ

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 1) virus--;
			if (lab[i][j] == 2) 
			{ 
				bb.push_back({ i,j }); 
				virus--;
			}

		}
	}
	if (virus == 0) {
		cout << 0; 
		return 0;
	}
	//for (int i = M; i >0; i--) {
	makeGroup(M);
	//}
	if(possible)cout << minumun;
	else cout << -1;
}
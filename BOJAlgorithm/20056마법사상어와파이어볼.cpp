#include<iostream>
#include<vector>
using namespace std;

struct fire {
	int m; //����
	int s; //�ӷ� 
	int d; //����(0~7)
};
vector<fire> sea[53][53]; //�̰� ���븶�� ���ٴ� �Ҹ���;
vector<fire> moveTMP[53][53]; //�̵��ҋ� ���� ���� �ڷᱸ��
int N, M, K; //���� ũ��, ���̾ ���� �߻��Ѱ� , ��� �̵� Ƚ��
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0, 1,1,1,0,-1,-1,-1 };

void moveball(fire st, int x, int y) {
	//�ӵ��� ���� ���
	int nx = x + (dx[st.d] * st.s) % N;
	int ny = y + (dy[st.d] * st.s) % N;

	//�̾����� ó��(outofbound)
	if (nx > N) nx -= N;
	if (nx <= 0) nx += N;
	if (ny > N) ny -= N;
	if (ny <= 0) ny += N;


	//��ǥ ������� �Ұ� �ű��� 
	moveTMP[nx][ny].push_back(st);


}

void sharkStep() {
	//1. move all the fireballs 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < sea[i][j].size(); k++) { //�ڿ�������^^..
				moveball(sea[i][j][k], i, j);
			}
			//�̵� �� ������ ������ �ִ� �ڸ��� clear���ֱ�
			sea[i][j].clear();
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (moveTMP[i][j].size() > 0) {
				sea[i][j] = moveTMP[i][j]; //copy
				moveTMP[i][j].clear();
			}
		}
	}

	//2.check where there are more than 2 fireballs
	  //2-2. ��ģ �Ұ� 4���� ������
	  //2-3. ���� ������ / �ӷ� ������ / ���� �����ϱ�(dir: sum all odd:���� �ٸ� 1357/ even: ��� Ȧor¦:0246
	  //2-4. ��� ���� ���̾ �̵�!(�ӷ¸�ŭ �߿�)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (sea[i][j].size() > 1) {
				fire sumtmp = { 0,0,0 };
				int fallnum = sea[i][j].size();
				bool even = false, odd = false;
				for (int k = 0; k < sea[i][j].size(); k++) {
				//2-1. ���� ĭ �Ұ� �ϳ��� ��ġ��
					sumtmp.m += sea[i][j][k].m;
					sumtmp.s += sea[i][j][k].s;
					//sumtmp.d += sea[i][j][k].d;
					if (sea[i][j][k].d % 2 == 0) even = true;
					else odd = true;
				}
				sea[i][j].clear();
				sumtmp.m = sumtmp.m / 5;
				if (sumtmp.m == 0) continue;//3. ���� 0�� �Ұ����ֱ� 
				
				sumtmp.s = sumtmp.s / fallnum;
				if ((even && !odd) || (!even && odd)) {
					//even: 0246
					for (int ind = 0; ind < 8; ind += 2) {
						sumtmp.d = ind;
						sea[i][j].push_back(sumtmp);
	
					}
				}
				else if(even && odd){
					//odd: 1357
					for (int ind = 1; ind < 8; ind += 2) {
						sumtmp.d = ind;
						sea[i][j].push_back(sumtmp);
					}
				}
				
			}

		}
	}
}

int getRemainM() {
	int sumM = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < sea[i][j].size(); k++) {
				//2-1. ���� ĭ �Ұ� �ϳ��� ��ġ��
				sumM += sea[i][j][k].m;
			}
		}
	}
	return sumM;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;//��,��, ����,�ӷ�,����
		cin >> r >> c >> m >> s >> d;
		sea[r][c].push_back({m,s,d});
	
	}
	while (K--) {
		sharkStep();
	}
	cout << getRemainM(); //�����ִ� �Ұ� ���� �� 
	return 0;
}
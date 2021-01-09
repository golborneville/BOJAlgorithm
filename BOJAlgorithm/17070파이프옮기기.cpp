#include<iostream>
#include<stack>
//bool chk[20][20];
using namespace std;
int home[20][20];
int total = 0;
int N;
pair<int,int> pipe[2];//start, end psir(x,y)
void nextPipe(int state, pair<int,int> pos) { //DFS implement
	//pos�� ������ ����
	//state���� ���� �����ϼ� �ִ� ��찡 ���� �ٸ�
	int x = pos.first;
	int y = pos.second;

	if (x == N && y == N) {
		total++;
		return;
	}
	//chk[x][y] = true;
	//�� ������Ʈ���� �̵��ϴ� ��� �� ��쿡 ���� ĭ�� ����ִ���**
	//�̹� �湮�� ��ΰ� �ƴ���?-> ��� ������ ���ư��� ���ѵ� �����̶� ����  �ʿ�X

	//state 0 ����
	if (state == 0) {
		//1) ���� 

		if (!home[x][y + 1]&&(N >= x && N >= y + 1)) { //����־�� ��������
			nextPipe(0, { x , y + 1 });
		}
		//2) �밢��
		if (!(home[x + 1][y + 1]|| home[x + 1][y] || home[x][y+1]) && (N >= x + 1 && N >= y + 1)) {
			nextPipe(2, { x + 1, y+1 });	
		}
	}
	//state 1 ����
	else if (state == 1) {
		//1)����
		if (!home[x+1][y] && (N >= x + 1 && N >= y)) { //����־�� ��������
			nextPipe(1, { x + 1, y});
		}
		//2) �밢��
		if (!(home[x + 1][y + 1] || home[x + 1][y] || home[x][y + 1]) && (N >= x + 1 && N >= y + 1)) {
			nextPipe(2, { x + 1, y + 1 });
		}
	}
	//state 2 �밢��
	else if (state == 2) {
		//1) ���� 
		if (!home[x][y + 1] && (N >= x && N >= y + 1)) { //����־�� ��������
			nextPipe(0, { x , y + 1 });
		}
		//2)����
		if (!home[x + 1][y] && (N >= x + 1 && N >= y)) { //����־�� ��������
			nextPipe(1, { x + 1, y });
		}
		//3)�밢��
		if (!(home[x + 1][y + 1] || home[x + 1][y] || home[x][y + 1]) && (N >= x + 1 && N >= y + 1)) {
			nextPipe(2, { x + 1, y + 1 });
		}
	}
	
	


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int pipeState = 0; //0 ����, 1 ����, 2 �밢��
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> home[i][j];
		}
	}
	//chk[1][1] = true;
	//chk[1][2] = true;
	//pipe[0] = { 1,1 };
	//pipe[1] = { 1,2 };
	nextPipe(0, { 1,2 });
	cout << total;
	return 0;
}
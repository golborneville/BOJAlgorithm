#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N, M, D;
int castle[17][17];
int recover[17][17];
int comb[15];
struct info {
	int x;
	int y;
	int dis;
};
pair<int, int> archer[3]; //�ü� 3�� ��ǥ��
info enemy[3]; //���� �� 3��
int res = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> castle[i][j];
			recover[i][j] = castle[i][j];
			
		}
	}
	comb[M - 1] = 1; comb[M - 2] = 1; comb[M - 3] = 1;
	do {
		int kill = 0;
		int ind = 0;
		
		memset(archer, 0, sizeof(archer));
		
		for (int i = 0; i < M; i++)
		{
			if (comb[i] == 1) 
				archer[ind++] = { N, i };
		}
		//Nȸ ��ŭ �ݺ�
		//1. �ü��� �Ÿ� ���� �����(D����) �� ����-> ���� ��++;
		for (int f = 0; f < N; f++) {
			for (int i =archer[0].first-1; i >= 0; i--)
			{//�� �Ʒ� �༭���� ���� 

				for (int j = 0; j < M; j++)
				{

					if (castle[i][j]) // if enemy YES
					{
						for (int a = 0; a < 3; a++)
						{
							int cmpdis = abs(archer[a].first - i) + abs(archer[a].second - j);
							if (cmpdis > D) continue;
							if (!enemy[a].dis)
							{//ó�� �����ϴ� �����̴� �׳� ����
								enemy[a] = { i,j,cmpdis };
							}
							else
							{
								if (cmpdis < enemy[a].dis) enemy[a] = { i, j, cmpdis };
								if (cmpdis == enemy[a].dis)
								{
									if(j < enemy[a].y) enemy[a] = { i, j, cmpdis };
								}
							}
						}
					}
				}

			}
			//2. ���� �������鼭�� ����(�ü��� �� �Ÿ� ) ������Ʈ-> �ü��� ���� ���� �÷�����
			for (int a = 0; a < 3; a++)
			{
				archer[a] = { archer[a].first - 1, archer[a].second }; //�̵� ���ְ� ������ �� �ٷ� ���ٺ��� Ž�� �ʤ���
				if (enemy[a].dis && castle[enemy[a].x][enemy[a].y])
				{
					castle[enemy[a].x][enemy[a].y] = 0;
					kill++; 
				}
			}
			memset(enemy, 0, sizeof(enemy));
		}

		//������ vs ���� �ִ� �� & ������Ʈ
		if (res < kill) res = kill;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				castle[i][j] = recover[i][j];

			}
		}

	}while(next_permutation(comb, comb + M));

	cout << res;
	return 0;
}
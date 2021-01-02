#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K;
//int r, c;
int arr[12][12];
int robo[12][12];
int soil[12][12];
int dx[8] = { 1,-1,0,0,1,-1, 1,-1 };
int dy[8] = { 0,0,1,-1,1,1,-1,-1 };
vector<int> treemap[12][12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, z; //tree pos x, y, & age

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> robo[i][j]; //[1,100]
			arr[i][j] = 5;
			
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;

		treemap[x][y].push_back(z);

	}

	while (K--) {
		
		//�� - ���� �߰� ���� �ʿ�
		
		//####���� ������ ��� �԰� ���� �԰� �ϴ� ���κе� �̿ϼ�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!treemap[i][j].size()) continue;

				sort(treemap[i][j].begin(), treemap[i][j].end());
				vector<int> tmp; //��Ƴ��� ������
				for (int l = 0; l < treemap[i][j].size(); l++) {
					if (arr[i][j] < treemap[i][j][l]) {
						//���� ��� & ����/2 ��ŭ ������� ���ư�(������ ���ư����� �ȵ��ư�)
						soil[i][j] += treemap[i][j][l] / 2; //������ �߰� ���ٰŶ� �ӽ÷� soil�迭�� �߰�
					
						//���� �״� �κ� ��� �������� �Ф���#####
						//�׾����ϱ� NOTHING
					}
					else {
						//������� �԰� ���� +1
						arr[i][j] -= treemap[i][j][l]; //��� �Ϸη�
						tmp.push_back(treemap[i][j][l]+1);
					}
				}
				treemap[i][j].clear(); //O(M)
				treemap[i][j]=tmp; //O(M)
			}
		}





		
		//���� - ���!
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j]+=soil[i][j]; 
				soil[i][j] = 0;
			}
		}
		//����
		//1.�������� ~ 5�� ���, ���� 8ĭ�� ���� 1 �� �ֵ� ����
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!treemap[i][j].size()) continue;
				for (int l = 0; l < treemap[i][j].size(); l++) {//

					if (treemap[i][j][l] % 5 != 0) continue;
					for (int k = 0; k < 8; k++) {
						//out of range
						if (i + dx[k] <= 0 || j + dy[k] <= 0 ||
							i + dx[k] > N || j + dy[k] > N)continue;
						
						//���� ���� �°� ���� �߰�??????
						treemap[i + dx[k]][j + dy[k]].push_back(1);
					}
				}
			}
		}
		//�ܿ�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] += robo[i][j];
			}
		}
		
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += treemap[i][j].size();
		}
	}
	cout << answer;
	return 0;
}
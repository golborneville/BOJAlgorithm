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
		
		//봄 - 아직 추가 구현 필요
		
		//####여기 나무가 양분 먹고 나이 먹고 하느 ㄴ부분들 미완성
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!treemap[i][j].size()) continue;

				sort(treemap[i][j].begin(), treemap[i][j].end());
				vector<int> tmp; //살아남은 나무들
				for (int l = 0; l < treemap[i][j].size(); l++) {
					if (arr[i][j] < treemap[i][j][l]) {
						//나무 쥬금 & 나이/2 만큼 양분으로 돌아감(여름에 돌아감아직 안돌아감)
						soil[i][j] += treemap[i][j][l] / 2; //여름에 추가 해줄거라 임시로 soil배열에 추가
					
						//나무 죽는 부분 어떻게 구현하지 ㅠㅁㅠ#####
						//죽었으니까 NOTHING
					}
					else {
						//나무양분 먹고 나이 +1
						arr[i][j] -= treemap[i][j][l]; //양분 뾰로롱
						tmp.push_back(treemap[i][j][l]+1);
					}
				}
				treemap[i][j].clear(); //O(M)
				treemap[i][j]=tmp; //O(M)
			}
		}





		
		//여름 - 양분!
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j]+=soil[i][j]; 
				soil[i][j] = 0;
			}
		}
		//가을
		//1.나무번식 ~ 5의 배수, 인접 8칸에 나이 1 인 애들 생김
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!treemap[i][j].size()) continue;
				for (int l = 0; l < treemap[i][j].size(); l++) {//

					if (treemap[i][j][l] % 5 != 0) continue;
					for (int k = 0; k < 8; k++) {
						//out of range
						if (i + dx[k] <= 0 || j + dy[k] <= 0 ||
							i + dx[k] > N || j + dy[k] > N)continue;
						
						//나이 순에 맞게 나무 추가??????
						treemap[i + dx[k]][j + dy[k]].push_back(1);
					}
				}
			}
		}
		//겨울
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
#include<iostream>
#include<deque>
#include<set>
using namespace std;

int N, M,T;
deque<int> dq[52];
int panSize[52];
int sumPan[52];
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input;
			cin >> input;
			dq[i].push_back(input);
			panSize[i]++;
			sumPan[i] += input;
		}
	}
	while (T--)
	{
		int x, d, k; //번호가 x의 배수인 원판을 d방향으로 k칸 회전

		cin >> x >> d >> k;
		for (int i = x; i <= N; i+=x)
		{
			//if (i == 1)continue;
			//if (i % x != 0) continue;
			if (!panSize[i]) continue;
			//1 단계
			if (!d) // d = 0 -> 시계방향
			{
				for (int j = 0; j < k; j++)
				{
					dq[i].push_front(dq[i].back());
					dq[i].pop_back();
				}
			}
			else// d = 1 -> 반시계방향
			{
				for (int j = 0; j < k; j++)
				{
					dq[i].push_back(dq[i].front());
					dq[i].pop_front();
				}
			}
		}
			//2단계
			//인접 애들 다 0으로 처리하기(빼진X)
			//4 case [i][j] -> 
		set<pair<int, int>> adj;
		bool flag = false;
		for (int i = 1; i <= N; i++)
		{
			if (!panSize[i]) continue;
			for (int j = 0; j < M; j++)
			{
				if (!dq[i][j]) continue;
				for (int s = 0; s < 4; s++)
				{
					int nx = i + di[s]; int ny = j + dj[s];
			
					if (nx < 1) continue;//nx = N;
					if (ny < 0) ny = M - 1;
					if (nx > N) continue;//nx = 1;
					if (ny >= M) ny = 0;
					
					if (dq[i][j] == dq[nx][ny])
					{
						adj.insert({ i, j });
						adj.insert({ nx, ny });
						flag = true;
					}
				}
			}
		}
		for (auto iter = adj.begin(); iter != adj.end(); iter++)
		{
			pair<int, int> pos = *iter;
			sumPan[pos.first] -= dq[pos.first][pos.second];
			dq[pos.first][pos.second] = 0;
			panSize[pos.first]--;
		}
		if (!flag)
		{//###여기 숮어 핗요 
			//인접으로 지운X -> 평균내서 값 변경
			int sumval = 0;
			int sumsize = 0;
			for (int s = 1; s <= N; s++)
			{
				sumval += sumPan[s];
				sumsize += panSize[s];
			}
			if (sumsize == 0) break;
			float avg = (float)sumval / (float)sumsize;
			for (int i = 1; i <= N; i++)
			{
				if (!panSize[i]) continue;
				for (int j = 0; j < M; j++)
				{
					if (!dq[i][j]) continue;
					if (dq[i][j] < avg)
					{
						dq[i][j]++;
						sumPan[i]++;
					}
					else if (dq[i][j] > avg)
					{
						dq[i][j]--;
						sumPan[i]--;
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= N; i++)
		res += sumPan[i];
	cout << res;
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int N, arr[24][24], tmpMin = 0, tmpMin2 = 0;
int num[24];
bool Select[24];
int minDiff = 987654321;
int team[2][12]; //0 is team start, 1 is link


void divide()
{
	int zero_ind = 0, one_ind = 0;
	for (int i = 0; i < N; i++)
	{
		if (Select[i] == true)
		{
			//team start
			team[0][zero_ind] = num[i];
			zero_ind++;
		}
		else {
			//team link
			team[1][one_ind] = num[i];
			one_ind++;
		}
	}
	int tmp_index = 0;
	while (tmp_index< N/2) {
		for (int i = tmp_index + 1; i < N / 2; i++) {
			int n1 = team[0][i] -1;
			int n2 = team[0][tmp_index] -1;
			tmpMin += arr[n1][n2] + arr[n2][n1];
		}
		tmp_index++;
	}
	int tmp_index2 = 0;
	while (tmp_index2 < N / 2) {
		for (int i = tmp_index2 + 1; i < N / 2; i++) {
			int n1 = team[1][i]-1;
			int n2 = team[1][tmp_index2]-1;
			tmpMin2 += arr[n1][n2] + arr[n2][n1];
		}
		tmp_index2++;
	}
	if (tmpMin >= tmpMin2) {
		if (tmpMin - tmpMin2 < minDiff) {
			minDiff = tmpMin - tmpMin2;
		}
	}
	else {
		if (tmpMin2 - tmpMin < minDiff) {
			minDiff = tmpMin2 - tmpMin;
		}
	}

	tmpMin = 0;
	tmpMin2 = 0;


}

void DFS(int Idx, int Cnt)
{
	if (Cnt == N/2)
	{
		divide();
		return;
	}

	for (int i = Idx; i < N; i++)
	{
		if (Select[i] == true) continue;
		Select[i] = true;

		DFS(i, Cnt + 1);
		Select[i] = false;
	}
}


int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		num[i] = i + 1;
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	DFS(0, 0);

	printf("%d", minDiff);
	
}
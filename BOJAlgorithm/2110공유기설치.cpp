#include<iostream>
#include<algorithm>
using namespace std;
int home[200004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> home[i];
	}
	sort(home, home + N);
	
	//##################left = 1, right = home[N-1] - home[0]  이게 문제였음

	int left = 1; //가능한 간격의 최소 거리 
	//왼쪽 제일 끝 (간격)
	int right = home[N - 1] - home[0];// 오른쪽 제일 끝 ( 간격)
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2; //이분탐색 위해 중간을 찍음-> 비교 간격 : 최종 최대간격이 될수 있는 후보 
		int prev_ind = 0; //가장 최근에 설치된 공유기의 위치
		int cnt = 1; //현재 시점에 설치 하고 시작(그래야 비교군 공유기가 생김)


		for (int ind = 1; ind < N; ind++) {
			if (home[ind] - home[prev_ind] >= mid) {
				cnt++; // ind 위치에 공유기 하나 더 설치!
				prev_ind = ind;
			}
		}
		// mid 간격 기준으로 설치 다 해보고 보자~ 공유기 개수 최소 요건 개수 다 채웠니?
		if (cnt >= C) {
			//채움! 답이 될 수 있어! -> 더 큰값도 있나 함 확인하자!
			left = mid + 1;
		}
		else {
			//ㄴㄴ 공유기 설치 더 해야해 = 간격 더 줄여줘야 해 ( 값이 더 작아질 것..)
			right = mid - 1;
		}
		if (answer < mid && cnt >= C) { //기존 간격보단 큰 값(최댓값 갱신) & 최소 공유기 개수 는 설치 ㅇㅇ -> 답 후보 가능
			answer = mid;
		}

	}
	cout << answer;
	return 0;
}
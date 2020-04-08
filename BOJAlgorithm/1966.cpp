#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, M, cnt = 0;
queue<pair<int, int>> printer;
int arr[103];
stack<int> toptob;
int main() {
	memset(arr, -1, sizeof(arr));
	cin >> T;
	while (T--) {
		cin >> N >> M; //M이 원래 배열의 인덱스 기준임

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			printer.push(make_pair(arr[i], i));//우선순위 , 인덱스
		}
		//arr 오름차순 정리 -> 역순으로 스택에 넣기!
		sort(arr, arr + N);
		for (int i = 0; i < N; i++) {
			toptob.push(arr[i]);
			
		}
		//스택은 위에서 부터 내림차순~
		while (1) {
			if (toptob.top() == printer.front().first) {
				toptob.pop();
				if (printer.front().second == M) {
					//마자 우리가 원한거!

					cnt++;
					break;
				}
				else {
					//같은 우선순위지만 해당 인덱스 아님
					//cnt만 증가!
					printer.pop();
					cnt++;
				}
			}
			else {
				//그 뒤에 다른  더 큰 우선순위가 잇으 ㅇㅇ 푸시앤팝!
				printer.push(printer.front());
				printer.pop();
			}
		}
		cout << cnt << "\n";
		//자 이제 다 리셋타임 
		memset(arr, -1, sizeof(arr));
		cnt = 0;
		while (!toptob.empty()) {
			toptob.pop();
		}
		while (!printer.empty()) {
			printer.pop();
		}
	}


}


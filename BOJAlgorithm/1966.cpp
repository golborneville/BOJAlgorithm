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
		cin >> N >> M; //M�� ���� �迭�� �ε��� ������

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			printer.push(make_pair(arr[i], i));//�켱���� , �ε���
		}
		//arr �������� ���� -> �������� ���ÿ� �ֱ�!
		sort(arr, arr + N);
		for (int i = 0; i < N; i++) {
			toptob.push(arr[i]);
			
		}
		//������ ������ ���� ��������~
		while (1) {
			if (toptob.top() == printer.front().first) {
				toptob.pop();
				if (printer.front().second == M) {
					//���� �츮�� ���Ѱ�!

					cnt++;
					break;
				}
				else {
					//���� �켱�������� �ش� �ε��� �ƴ�
					//cnt�� ����!
					printer.pop();
					cnt++;
				}
			}
			else {
				//�� �ڿ� �ٸ�  �� ū �켱������ ���� ���� Ǫ�þ���!
				printer.push(printer.front());
				printer.pop();
			}
		}
		cout << cnt << "\n";
		//�� ���� �� ����Ÿ�� 
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


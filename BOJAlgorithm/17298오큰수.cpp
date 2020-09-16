#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int N;
int arr[1000003];
bool answer[1000003];
stack <int> s;

int main() {
	memset(answer, true, sizeof(answer));
	scanf_s("%d", &N);
	for(int i =1; i<=N; i++) { // 0 X X X X ... 0 0 0 ...0
		scanf_s("%d", &arr[i]);
	}

	for (int i = 1; i <=N; i++) {
		while (!s.empty() && (arr[s.top()] < arr[i])) {
			answer[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
		
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", answer[i]);
	}
}
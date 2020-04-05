#include<iostream>
#include<cstring>
using namespace std;
int a[1003];
void selectionSort( int n) {
	int tmp, k;
	for (int i = 1; i < n; i++) {//넘나 당연한 이중포문-> 시발^_^!
		tmp = a[i-1];
		k = i-1;
		for (int j = i; j < n; j++) {
			if (tmp > a[j]) { //더 작은 값: tmp갱신
				k = j;
				tmp = a[j]; //a[k] == tmp
			}
		}
		//tmp와 a[i]의 교환
		int tt = a[i-1];
		a[i-1] = tmp;
		a[k] = tt;

	}
}
void bubbleSort(int N) {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				//swap!
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

}

int main() {
	int N;
	cin >> N;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	//selectionSort(N);
	bubbleSort(N);
	for (int i = 0; i < N; i++) {
		cout << a[i] << "\n";

	}
}
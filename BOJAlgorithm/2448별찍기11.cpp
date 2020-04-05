#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int k = N / 3; //kÃşÂ¥¸®
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 + 3 * (k - 1)-i; j++) {
			cout << " ";
		}
		int ne = (N-i) % 3;
		int fl = i / 3;
		int bl = i / 6;
		int sec = i / 12;
		switch (ne)
		{
		case 0:
			cout << "*";
			break;
		case 2:
			cout << "* *";
			break;
		case 1:
			cout << "*****";
			break;

		}
		if (fl % 2 != 0) {
			switch (ne)
			{
			case 0:
				cout << "     *";
				break;
			case 2:
				cout << "   * *";
				break;
			case 1:
				cout << " *****";
				break;

			}
		}
		if (bl!=0) {
			switch (i%6)
			{
			case 0:
				cout << "           ";
				break;
			case 1:
				cout << "         ";
				break;

			case 2:
				cout << "       ";
				break;

			case 3:
				cout << "     ";
				break;

			case 4:
				cout << "   ";
				break;

			case 5:
				cout << " ";
				break;

			}
			switch (ne)
			{
			case 0:
				cout << "*";
				break;
			case 2:
				cout << "* *";
				break;
			case 1:
				cout << "*****";
				break;

			}
			if (fl % 2 != 0) {
				switch (ne)
				{
				case 0:
					cout << "     *";
					break;
				case 2:
					cout << "   * *";
					break;
				case 1:
					cout << " *****";
					break;

				}
			}
		}
		
		cout << "\n";

	}
	
}
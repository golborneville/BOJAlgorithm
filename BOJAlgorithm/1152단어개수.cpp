#include <iostream>
using namespace std;


int main() {
	char string[1000003];
	cin.getline(string, 1000003, '\n');
	
	int i = 0, cnt =0;
	while (string[i] != '\0') {
		if (string[i] == ' ') {
			if (i > 0) { //b_ -> 1 
				cnt++;
			}
			else { // (blank) char ~~
				//1. (only blank)
				if (string[i + 1] == '\0') {
					cnt = 0;
					break;
				}

				//2. _a_b => 2
				 // else pass
			}
		}
		i++;
	}
	if (string[i - 1] != ' ') {
		//_b(end)
		cnt++;
	}
	if (string[0] == ' ' && string[1] == '\0') {
		cnt = 0;
	}
	if (string[0] == '\0') {
		cnt = 0;
	}
	cout << cnt;

	return 0;

}
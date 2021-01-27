#include<iostream>
#include<string>
using namespace std;
int minyear = 2021, minmonth = 13, minday = 35;
int maxyear = 0, maxmonth = 0, maxday = 0;
string minName, maxName; //숫자 값 기준mion max라서 minName이 가장 나이 많은 사람 ㅇㅇ (1893 - 2001)느낌

void setminval(int y, int m, int d, string name) {
	minyear = y;
	minmonth = m;
	minday = d;
	minName = name;
}

void setmaxval(int y, int m, int d, string name) {
	maxyear = y;
	maxmonth = m;
	maxday = d;
	maxName = name;
}
int main() {
	
	int n;
	
	cin >> n;
	while (n--) {
		string name;
		int yy, mm, dd;
		cin >> name >> dd >> mm >> yy;
		if (minyear >  yy) {
			setminval(yy, mm, dd, name);
		}
		else if (minyear == yy) {
			if (minmonth > mm) {
				setminval(yy, mm, dd, name);
			}
			else if (minmonth == mm) {
				if (minday > dd) {
					setminval(yy, mm, dd, name);
				}

			}
		}

		if (maxyear < yy) {
			setmaxval(yy, mm, dd, name);
		}
		else if (maxyear == yy) {
			if (maxmonth < mm) {
				setmaxval(yy, mm, dd, name);
			}
			else if (maxmonth == mm) {
				if (maxday < dd) {
					setmaxval(yy, mm, dd, name);
				}
			}
		}
	}
	cout << maxName << "\n" << minName;
	return 0;
}
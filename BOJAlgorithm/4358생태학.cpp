#include<iostream>
#include<string>
#include<map>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string name;
	map<string, float> park;
	map<string, float>::iterator iter;
	float total_size = 0;

	while (getline(cin, name)) {
		total_size++;
		iter = park.find(name);
		if (iter == park.end()) {
			park[name] = 0;
		}
		park[name] += 1;
	}
	cout << fixed;
	cout.precision(4);
	for (iter = park.begin(); iter != park.end(); iter++) {
		float par = (iter->second / total_size) *100;
		cout << iter->first << " " << par << "\n";
	}
}

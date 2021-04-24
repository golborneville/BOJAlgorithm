#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int L, C;
char src[17];
char res[17];
bool chk[17];
void rec(int dep, int ind, int vow, int con)
{
	if (dep == L)
	{
		if (vow < 1 || con < 2) return;
		for (int i = 0; i < L; i++)
			cout << res[i];
		cout << "\n";
		return;
	}
	for (int i = ind; i < C; i++)
	{
		if (chk[i]) continue;
		chk[i] = true;
		res[dep] = src[i];
		int v = 0; int c = 0;
		if (src[i] == 'a' || src[i] == 'e' || src[i] == 'i' || src[i] == 'o' || src[i] == 'u') v = 1;
		else c = 1;
		rec(dep + 1, i+1, vow + v, con + c);
		chk[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> src[i];
	sort(src, src + C);
	rec(0, 0,0,0);
	return 0;
}
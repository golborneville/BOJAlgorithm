#include <string>
#include <vector>
#define MAX_NODE 200003
using namespace std;
bool chk[MAX_NODE]; //node visit chk
int hang[MAX_NODE]; //node 이전에 방문해야 할 방을 방문 안했다면 hang에 넣고 저장 
int before[MAX_NODE];
vector<int> cave[MAX_NODE];
void visit(int node)
{
	if (chk[node]) return;

	if (!chk[before[node]])
	{
		hang[before[node]] = node;
		return;
	}

	chk[node] = true;
	visit(hang[node]);
	for (int e : cave[node]) visit(e);
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	bool answer;
	for (auto &it : path)
	{
		cave[it[0]].push_back(it[1]);
		cave[it[1]].push_back(it[0]);
	}
	for (auto &it : order) before[it[1]] = it[0];
	if (before[0]) return false;

	chk[0] = true;
	for (int e : cave[0]) visit(e);

	for (int i = 0; i<n; i++) if (!chk[i]) return false;

	return true;
}
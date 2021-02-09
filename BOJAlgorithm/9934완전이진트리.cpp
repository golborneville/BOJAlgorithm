#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int K,ind=0;
int build[1026];
vector<int> stage[12];
struct Node {
	int num;
	Node* left;
	Node* right;
	int stage;
};
void makeTree(Node* nn, int dep) {
	
	nn->num = 0;
	nn->stage = dep;
	
	if (dep == K) return;
	
	Node* lf = new Node;
	Node* rt = new Node;
	nn->left = lf;
	nn->right = rt;

	makeTree(lf, dep + 1);
	makeTree(rt, dep + 1);

}
void insertNum(Node* node, int dep ) {
	if (dep > K) return;
	
	insertNum(node->left, dep+1);
	node->num = build[ind++];
	insertNum(node->right, dep+1);
}

void getStage(Node* node, int dep) {
	if (dep > K) return;

	stage[dep].push_back(node->num);
	getStage(node->left, dep + 1);
	getStage(node->right, dep + 1);
}
Node* root;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	for (int i = 0; i < pow(2, K) - 1; i++) {
		cin >> build[i];
	}
	root = new Node;
	makeTree(root, 1);
	insertNum(root,1);
	getStage(root, 1);
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < stage[i].size(); j++) {
			cout << stage[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
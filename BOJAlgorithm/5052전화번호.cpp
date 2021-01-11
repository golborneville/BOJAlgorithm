#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
#define MAX_N 10000
int t, n, r;
char a[MAX_N][11];
struct Trie {
	Trie* next[10]; //0~9 
	bool end; //�ش� trie���� (���) �ܾ ������ �ǹ�
	//������
	Trie(): end(false) {
		memset(next, 0, sizeof(next)); //root ��� (�ƹ� �͵� ����X)
	}
	void insert(const char* key) { //911
		if (*key == '\0') { //�ܾ��� ���������� ���� ���
			end = true;
		}
		else {
			int cur = *key - '0'; //[9]
			if (next[cur] == NULL) //next[9]
				next[cur] = new Trie(); //���� trie���� �ش� ����(Ȥ�� ����) �� ������ �� ���ٴ� �ǹ� -> ���� �����Ҵ� ������
			next[cur]->insert(key + 1); //�� ���� ���ڿ��� ���� Ȯ���������� ( �����Ͷ� �ּ� �� ���� ���ڸ� ����Ŵ)
		
		}

	}

	int find(const char* key) {
		if (key == '\0') {
			return 0; //�ܾ� ������ Ž���ߴµ� prefix��ã��
		}
		if (end) {
			return 1; //prefix������!!!
		}
		int cur = *key - '0';
		return next[cur]->find(key + 1);
	}


};

int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &n);
		getchar();

		for (int i = 0; i<n; i++)
			scanf_s("%s", &a[i], sizeof(a[i]));
		Trie *root = new Trie;
		r = 0;
		for (int i = 0; i<n; i++)
			root->insert(a[i]);
		for (int i = 0; i<n; i++) {
			if (root->find(a[i])) {
				r = 1;
			}
		}
		printf("%s\n", r ? "NO" : "YES");
	}
	return 0;
}


/*

struct Trie {
bool finish;    //������ ������ ǥ������
Trie* next[26];    //26���� ���ĺ��� ���� Ʈ����
Trie() : finish(false) {
memset(next, 0, sizeof(next));
}
~Trie() {
for (int i = 0; i < 26; i++)
if (next[i])
delete next[i];
}
void insert(const char* key) {
if (*key == '\0')
finish = true;    //���ڿ��� ������ ������ ��� ǥ��
else {
int curr = *key - 'A';
if (next[curr] == NULL)
next[curr] = new Trie();    //Ž���� ó���Ǵ� ������ ��� �����Ҵ�
next[curr]->insert(key + 1);    //���� ���� ����
}
}
Trie* find(const char* key) {
if (*key == '\0')return this;//���ڿ��� ������ ��ġ�� ��ȯ
int curr = *key - 'A';
if (next[curr] == NULL)return NULL;//ã�� ���� �������� ����
return next[curr]->find(key + 1); //���� ���ڸ� Ž��
}
};



#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 10000
using namespace std;
struct Trie {
	Trie* next[10];
	bool term;
	Trie() : term(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i<10; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0')
			term = true;
		else {
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0')
			return 0;
		if (term)
			return 1;
		int curr = *key - '0';
		return next[curr]->find(key + 1);
	}
};
int t, n, r;
char a[MAX_N][11];
int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &n);
		getchar();

		for (int i = 0; i<n; i++)
			scanf_s("%s", &a[i], sizeof(a[i]));
		Trie *root = new Trie;
		r = 0;
		for (int i = 0; i<n; i++)
			root->insert(a[i]);
		for (int i = 0; i<n; i++) {
			if (root->find(a[i])) {
				r = 1;
			}
		}
		printf("%s\n", r ? "NO" : "YES");
	}
	return 0;
}
*/
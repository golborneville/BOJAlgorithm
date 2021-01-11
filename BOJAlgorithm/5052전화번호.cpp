#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
#define MAX_N 10000
int t, n, r;
char a[MAX_N][11];
struct Trie {
	Trie* next[10]; //0~9 
	bool end; //해당 trie에서 (노드) 단어가 끝남을 의미
	//생성자
	Trie(): end(false) {
		memset(next, 0, sizeof(next)); //root 노드 (아무 것도 존재X)
	}
	void insert(const char* key) { //911
		if (*key == '\0') { //단어의 마지막까지 끝난 경우
			end = true;
		}
		else {
			int cur = *key - '0'; //[9]
			if (next[cur] == NULL) //next[9]
				next[cur] = new Trie(); //현재 trie에서 해당 숫자(혹은 문자) 가 등장한 적 없다는 의미 -> 새로 동적할당 해주자
			next[cur]->insert(key + 1); //그 다음 문자열에 대해 확ㅇ니해주자 ( 포인터라서 주소 상 다음 문자를 가르킴)
		
		}

	}

	int find(const char* key) {
		if (key == '\0') {
			return 0; //단어 끝까지 탐색했는데 prefix못찾음
		}
		if (end) {
			return 1; //prefix존재함!!!
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
bool finish;    //끝나는 지점을 표시해줌
Trie* next[26];    //26가지 알파벳에 대한 트라이
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
finish = true;    //문자열이 끝나는 지점일 경우 표시
else {
int curr = *key - 'A';
if (next[curr] == NULL)
next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
next[curr]->insert(key + 1);    //다음 문자 삽입
}
}
Trie* find(const char* key) {
if (*key == '\0')return this;//문자열이 끝나는 위치를 반환
int curr = *key - 'A';
if (next[curr] == NULL)return NULL;//찾는 값이 존재하지 않음
return next[curr]->find(key + 1); //다음 문자를 탐색
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
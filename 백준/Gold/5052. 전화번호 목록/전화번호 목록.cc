#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool flag = true;

struct Trie {
	bool finish;
	Trie* next[10];

	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < sizeof(next); i++) {
			if (next[i])
				delete next[i];
		}
	}

	void insertTrie(const char* key) {
		if (!flag) {
			return;
		}
		if (*key == '\0') {
			finish = true;
		}
		else {
			int cur = *key - '0';
			if (next[cur] == NULL) {
				next[cur] = new Trie();
			}
			if (this->finish == true) {
				flag = false;
				return;
			}
			next[cur]->insertTrie(key + 1);
		}
	}

};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--) {
		Trie* trie = new Trie();
		vector<string> v;
		bool consistent = true;
		int StringNum = 0;
		cin >> StringNum;
		flag = true;

		for (int i = 0; i < StringNum; i++) {
			string str = "";
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < StringNum; i++) {
			string str = v[i];
			trie->insertTrie(str.c_str());
			if (!flag) {
				consistent = false;
				break;
			}
		}

		if (consistent) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}
}

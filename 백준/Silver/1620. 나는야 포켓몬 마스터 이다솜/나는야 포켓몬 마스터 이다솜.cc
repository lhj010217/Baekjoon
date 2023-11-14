#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool isName(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int poket_n = 0;
	int problem_n = 0;
	cin >> poket_n >> problem_n;
	unordered_map<string, int>* hm = new unordered_map<string, int>(poket_n);
	vector<string> v(poket_n);
	for (int i = 0; i < poket_n; i++) {
		string name;
		cin>>name;
		hm->insert(pair<string,int>(name, i + 1));
		v[i] = name;
	}


	for (int i = 0; i < problem_n; i++) {
		string s;
		cin >> s;
		if (isName(s)) {
			auto iter = hm->find(s);
			if (iter != hm->end()) {
				cout << iter->second << "\n";
			}
			else {
				;
			}
		}
		else {
			int num = stoi(s);
			cout << v[num - 1] << "\n";
		}
	}

}
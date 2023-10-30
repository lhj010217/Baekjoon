#include<iostream>
#include<cmath>
#include<tuple>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

static bool isShortCut[26];

bool isAlpha(char c) {
	c = tolower(c);
	if ('a' <= c && c <= 'z') return true;
	else return false;
}

int getAlpha(char c) {
	return tolower(c) - 'a';
}

pair<string,int> setShortCut(string s) {
	int iter = 0;
	if (isAlpha(s[0]) && isShortCut[getAlpha(s[0])] == false) {
		isShortCut[getAlpha(s[0])] = true;
		iter = 0;
		return make_pair(s, iter);
	}
	else {
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == ' ') {
				if (isAlpha(s[i+1]) && isShortCut[getAlpha(s[i + 1])] == false) {
					isShortCut[getAlpha(s[i + 1])] = true;
					iter = i + 1;
					return make_pair(s, iter);
				}
			}
		}

		for (int i = 1; i < s.size(); i++) {
			if (s[i] != ' ' && isAlpha(s[i])) {
				if (isShortCut[getAlpha(s[i])] == false) {
					isShortCut[getAlpha(s[i])] = true;
					iter = i;
					return make_pair(s, iter);
				}
			}
		}
	}
	return make_pair(s, -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 26; i++) {
		isShortCut[i] = false;
	}

	int n = 0;
	string temp;
	getline(cin, temp);
	n = stoi(temp);
	vector<pair<string,int>> v(n);
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin,temp);
		v[i] = make_pair(temp,0);
	}
	
	for (int i = 0; i < n; i++) {
		
		v[i] = setShortCut(v[i].first);
	}
	for (int i = 0; i < n; i++) {
		string out_str = v[i].first;
		int out_iter = v[i].second;
		if (out_iter == -1) {
			cout << out_str << "\n";
		}
		else {
			for (int j = 0; j < out_str.size(); j++) {
				if (j == out_iter) {
					cout << "[" << out_str[j] << "]";
				}
				else {
					cout << out_str[j];
				}
			}
			cout << "\n";
		}
	}
}
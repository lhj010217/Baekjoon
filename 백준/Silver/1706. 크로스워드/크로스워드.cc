#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int r, c;
	cin >> r >> c;
	int iter = r + c;
	vector<string> v_ans;
	vector<string> v_r;
	vector<string> v_c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		v_r.push_back(s);
	}
	
	for (int j = 0; j < c; j++) {
		string temp;
		temp.append(r, ' ');
		for (int i = 0; i < r; i++) {
			temp[i] = v_r[i][j];
		}
		v_c.push_back(temp);
	}
	
	for (int i = 0; i < v_r.size(); i++) {
		string s="";
		for (int j = 0; j < v_r[i].length(); j++) {
			if (v_r[i][j] != '#') {
				s.append(1, v_r[i][j]);
				if (j == v_r[i].length() - 1 && s.length() > 1) {
					v_ans.push_back(s);
				}
			}
			else if (v_r[i][j] == '#') {
				if (s.length() > 1) {
					v_ans.push_back(s);
				}
				s.clear();
			}
		}
	}

	for (int i = 0; i < v_c.size(); i++) {
		string s = "";
		for (int j = 0; j < v_c[i].length(); j++) {
			if (v_c[i][j] != '#') {
				s.append(1, v_c[i][j]);
				if (j == v_c[i].length() - 1 && s.length() > 1) {
					v_ans.push_back(s);
				}
			}
			else if (v_c[i][j] == '#') {
				if (s.length() > 1) {
					v_ans.push_back(s);
				}
				s.clear();
			}
		}
	}

	sort(v_ans.begin(), v_ans.end());
	cout << v_ans[0];
}
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
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m = 0;
	cin >> m;
	vector<int> v;

	while (m--) {
		string ope;
		int n;
		cin >> ope;
		if (ope == "add") {
			cin >> n;
			if (find(v.begin(), v.end(), n) == v.end()) {
				v.push_back(n);
			}
		}
		else if (ope == "remove") {
			cin >> n;
			auto iter = find(v.begin(), v.end(), n);
			if (iter != v.end()) {
				v.erase(iter);
			}
		}
		else if (ope == "check") {
			cin >> n;
			auto iter = find(v.begin(), v.end(), n);
			if (iter != v.end()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (ope == "toggle") {
			cin >> n;
			auto iter = find(v.begin(), v.end(), n);
			if (iter != v.end()) {
				v.erase(iter);
			}
			else {
				v.push_back(n);
			}
		}
		else if (ope == "all") {
			v.clear();
			for (int i = 0; i < 20; i++) {
				v.push_back(i + 1);
			}
		}
		else if (ope == "empty") {
			v.clear();
		}

	}


}
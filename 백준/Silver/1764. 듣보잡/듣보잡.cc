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
	
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> um;
	vector<string> res;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		um.insert(pair<string,int>(name,0));
	}

	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		if (um.find(name) != um.end()) {
			res.push_back(name);
			cnt++;
		}
	}
	cout << cnt <<"\n";
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "\n";
	}


} 
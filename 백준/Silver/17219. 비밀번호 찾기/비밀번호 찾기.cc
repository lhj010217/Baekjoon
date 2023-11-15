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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_map<string, string> map;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string site;
		string pass;
		cin >> site >> pass;
		map.insert(pair<string,string>(site, pass));
	}
	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;

		auto iter = map.find(site);
		if(iter != map.end()) {
			cout << iter->second <<"\n";
		}
	}

}
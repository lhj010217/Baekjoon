#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> p = make_pair(a, b);
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}
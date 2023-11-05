#include<iostream>
#include<stdio.h>
#include<queue>
#include<deque>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int sum = 0;
	int t = 0;
	cin >> t;
	vector<int> v(t);
	for (int i = 0; i < t; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	int a = round((double)sum / v.size());
	int b = v[v.size() / 2];
	int c = 0;
	int d = v.back() - v.front();

	vector<int> vf;
	int f = 0;
	int ary[8001] = { 0 };
	for (int i = 0; i < t; i++) {
		ary[v[i] + 4000]++;
	}
	for (int i = 0; i < 8001; i++) {
		f = max(f, ary[i]);
	}
	for (int i = 0; i < 8001; i++) {
		if (ary[i] == f) {
			vf.push_back(i-4000);
		}
	}
	if (vf.size() == 1) {
		c = vf.front();
	}
	else {
		sort(vf.begin(), vf.end());
		c = vf[1];
	}
	cout << a << "\n" << b << "\n" << c << "\n" << d << "\n";
}
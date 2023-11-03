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

	int n = 0;
	int res = 0;
	vector<int> v;
	cin >> n;

	if (n % 5 == 0) {
		cout << n / 5;
	}
	else {
		int a = n / 5;
		for (int i = 0; i <= a; i++) {
			int temp = n - (i * 5);
			if (temp % 3 == 0) {
				v.push_back(temp / 3 + i);
			}
		}
		if (v.empty()) {
			cout << "-1";
		}
		else {
			res = v.front();
			for (int i = 0; i < v.size(); i++) {
				res = min(res, v[i]);
			}
			cout << res;
		}
	}
}
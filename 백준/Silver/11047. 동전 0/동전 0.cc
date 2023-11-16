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
	long long k = 0;
	int n = 0;
	int index = 0;
	int cnt = 0;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = v.size()-1; i >= 0; i--) {
		if (k >= v[i]) {
			int temp = k / v[i];
			cnt += temp;
			k -= temp * v[i];
		}
		if (k == 0) {
			break;
		}
	}
	cout << cnt;
} 
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
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n = 0;
	vector<int> v;
	vector<int> dp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
		dp.push_back(0);
	}
	long long result = v[0];
	dp[0] = v[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		result = max(result, (long long)dp[i]);
	}
	cout << result;
	

} 
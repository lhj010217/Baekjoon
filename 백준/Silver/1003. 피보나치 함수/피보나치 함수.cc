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
	
	int t = 0;
	int n = 0;
	vector<pair<int,int>> dp(41);
	dp[0] = pair<int, int>(1, 0);
	dp[1] = pair<int, int>(0, 1);
	for (int i = 2; i < 41;i++) {
		dp[i] = pair<int, int>(dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second);
	}

	cin >> t;
	
	while (t--) {
		int n = 0;
		cin >> n;
		cout << dp[n].first << " " << dp[n].second << "\n";
	}
	

}
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
	
	int T = 0;
	vector<long long> dp(100);
	dp[2] = dp[1] = dp[0] = 1;
	dp[4] = dp[3] = 2;
	for (int i = 5; i < 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	cin >> T;
	while (T--) {
		int n = 0;
		cin >> n;
		cout << dp[n - 1] << "\n";
	}


}
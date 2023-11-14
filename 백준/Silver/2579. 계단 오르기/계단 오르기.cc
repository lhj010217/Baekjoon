#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int stair_n = 0;
	int* stair = new int[301];
	int* dp = new int[301];
	cin >> stair_n;

	stair[0] = 0;
	for (int i = 1; i <= stair_n; i++) {
		cin >> stair[i];
	}
	dp[0] = stair[0];
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[1], stair[2]) + stair[3];
	for (int i = 4; i <= stair_n; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 1], dp[i - 2]) + stair[i];
	}

	cout << dp[stair_n];
}
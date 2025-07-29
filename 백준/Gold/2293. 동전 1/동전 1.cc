#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;

int main() {
	int n, k;
	vector<int> coins;
	vector<int> dp;

	cin >> n >> k;
	coins.resize(n);
	dp.resize(k+1);

	for (int i = 0;i < n;i++) {
		cin >> coins[i];
	}
	
	dp[0] = 1;
	for (auto& coin : coins) {
		for (int iter = coin; iter <= k;iter++) {
			dp[iter] += dp[iter - coin];
		}
	}

	cout << dp[k];

	return 0;
}
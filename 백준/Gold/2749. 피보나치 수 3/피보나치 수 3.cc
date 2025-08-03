#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#define MODE 1000000

using namespace std;

// pisano period: n > 2라면, k(10^n) = 15×10^(n - 1)
int main() {
	long long n = 0;
	long long period = 15 * (MODE / 10);
	long long target = 0;
	
	cin >> n;
	target = n % period;

	vector<long long> dp(target + 1);
	dp[0] = 0;
	dp[1] = 1;
	
	for (long long i = 2; i <= target; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MODE;
	}

	cout << dp[target];

	return 0;

}
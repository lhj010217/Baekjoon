#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;

int main() {
	int T, W;
	cin >> T >> W;
	vector<int> trees(T+1);
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(W+1, vector<int>(T+1)));
	int result = -1;

	for (int i = 1; i <= T;i++) {
		cin >> trees[i];
		trees[i] == 1 ? dp[0][0][i] = dp[0][0][i - 1] + 1 : dp[0][0][i] = dp[0][0][i - 1];

	}


	for (int move = 1; move <= W; move++) {
		for (int time = 1;time <= T; time++) {
			dp[0][move][time] = max(dp[0][move][time - 1], dp[1][move-1][time-1]);
			dp[1][move][time] = max(dp[0][move-1][time - 1], dp[1][move][time - 1]);
			trees[time] == 1 ? dp[0][move][time]++ : dp[1][move][time]++;
		}
	}

	for (int pos = 0; pos <= 1;pos++) {
		for (int move = 0; move <= W; move++) {
			for (int time = 0;time <= T; time++) {
				result = max(result, dp[pos][move][time]);
			}
		}
	}


	cout << result;
	return 0;
}
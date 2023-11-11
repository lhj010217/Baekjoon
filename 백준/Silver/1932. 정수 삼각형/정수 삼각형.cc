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

	int size;
	cin >> size;
	vector<vector<int>> triangle(size, vector<int>(size, 0));
	vector<vector<int>> dp(size, vector<int>(size, 0));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];
	if (size == 1) {
		cout << dp[0][0];
		exit(0);
	}
	dp[1][1] = dp[0][0] + triangle[1][1];
	dp[1][0] = dp[0][0] + triangle[1][0];
	if (size == 2) {
		cout << max(dp[1][0], dp[1][1]);
		exit(0);
	}
	for (int i = 2; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}
	
	int res = -1;
	for (int i = 0; i < size; i++) {
		res = max(res, dp[size - 1][i]);
	}

	cout << res;
}
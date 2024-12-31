#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
using namespace std;

int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	
	long long N = 0, M = 0;
	cin >> N >> M;

	vector<vector<long long>> table(N+1, vector<long long>(N+1));

	vector<vector<long long>> dp(N + 1, vector<long long>(N + 1));

	for (long long i = 1; i <= N;i++) {
		for (long long j = 1; j <= N;j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + table[i][j];
		}
	}

	while (M--) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}
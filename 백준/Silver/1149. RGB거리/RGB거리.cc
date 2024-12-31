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
	
	int N = 0;
	cin >> N;

	vector<tuple<int, int, int>> house(N);
	for (int i = 0; i < N;i++) {
		int r, g, b;
		cin >> r >> g >> b;
		house[i] = make_tuple(r, g, b);
	}

	vector<vector<int>> dp(3, vector<int>(N));
	dp[0][N-1] = get<0>(house[N - 1]);
	dp[1][N-1] = get<1>(house[N - 1]);
	dp[2][N-1] = get<2>(house[N - 1]);

	for (int i = N - 2;i >= 0;i--) {
		dp[0][i] = min(dp[1][i + 1], dp[2][i + 1]) + get<0>(house[i]);
		dp[1][i] = min(dp[0][i + 1], dp[2][i + 1]) + get<1>(house[i]);
		dp[2][i] = min(dp[0][i + 1], dp[1][i + 1]) + get<2>(house[i]);
	}

	cout << min(min(dp[0][0], dp[1][0]), dp[2][0]);

	return 0;
}
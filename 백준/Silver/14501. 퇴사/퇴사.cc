#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;

int main() {

	vector<int> T;
	vector<int> P;
	vector<int> dp;
	int N;
	
	cin >> N;
	T.resize(N + 2);
	P.resize(N + 2);
	dp.resize(N + 2, 0);

	for (int i = 1; i <= N;i++) {
		cin >> T[i] >> P[i];
	}

	T[0] = 0;
	P[0] = 0;

	for (int i = 1;i <= N+1;i++) {
		dp[i] = max(dp[i], dp[i-1]);
		if (T[i] + i <= N + 1) {
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
		}
	}
	
	cout << dp[N+1];
	return 0;
}
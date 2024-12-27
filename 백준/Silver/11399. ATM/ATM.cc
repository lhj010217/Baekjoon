#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int N = 0;
	cin >> N;

	vector<int> v(N, 0);
	vector<int> dp(N, 0);
	long long result = 0; 
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	 
	dp[0] = v[0];
	result += dp[0];
	for (int i = 1; i < N;i++) {
		dp[i] = dp[i - 1] + v[i];
		result += dp[i];
	}
	cout << result;
	
	return 0;
}
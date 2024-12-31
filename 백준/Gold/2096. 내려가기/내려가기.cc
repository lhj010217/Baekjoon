#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	

	int N = 0;
	cin >> N;

	int cur_ary[3];
	int max_dp[3];
	int min_dp[3];
	int temp[3];

	cin >> cur_ary[0] >> cur_ary[1] >> cur_ary[2];
	for (int i = 0; i < 3;i++) {
		max_dp[i] = min_dp[i] = cur_ary[i];
	}

	while (N-- != 1) {
		cin >> cur_ary[0] >> cur_ary[1] >> cur_ary[2];
		copy(begin(max_dp), end(max_dp), begin(temp));
		max_dp[0] = max(temp[0], temp[1]) + cur_ary[0];
		max_dp[1] = max(max(temp[0], temp[1]), temp[2]) + cur_ary[1];
		max_dp[2] = max(temp[1], temp[2]) + cur_ary[2];
		
		copy(begin(min_dp), end(min_dp), begin(temp));
		min_dp[0] = min(temp[0], temp[1]) + cur_ary[0];
		min_dp[1] = min(min(temp[0], temp[1]), temp[2]) + cur_ary[1];
		min_dp[2] = min(temp[1], temp[2]) + cur_ary[2];

	}

	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) <<" ";
	cout << min(min(min_dp[0], min_dp[1]), min_dp[2]);

	return 0;
}
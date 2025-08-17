#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
#include<numeric>
using namespace std;

void meet_in_the_middle(vector<long long> nums, vector<long long>& sums, int start, int end, long long sum) {
	if (start == end) {
		sums.push_back(sum);
		return;
	}

	meet_in_the_middle(nums, sums, start + 1, end, sum);
	meet_in_the_middle(nums, sums, start + 1, end, sum + nums[start]);
}



int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
	}

	long long result = 0;
	int N, S;
	cin >> N >> S;
	vector<long long> nums(N);
	vector<long long> left_partSum;
	vector<long long> right_partSum;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	
	meet_in_the_middle(nums, left_partSum, 0, N / 2, 0);
	meet_in_the_middle(nums, right_partSum, N / 2, N, 0);

	sort(right_partSum.begin(), right_partSum.end());

	for (auto& left : left_partSum) {
		auto range = equal_range(right_partSum.begin(), right_partSum.end(), S - left);
		result += (range.second - range.first);
	}
	if (S == 0) result--;
	cout << result;
	return 0;
}
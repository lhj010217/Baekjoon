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

	int item_number = 0;
	int inventory_weight = 0;
	vector<pair<int, int>> item;
	cin >> item_number >> inventory_weight;
	vector<vector<int>> dp(inventory_weight + 1, vector<int>(item_number, 0));

	for (int i = 0; i < item_number; i++) {
		int temp_value = 0;
		int temp_weight = 0;
		cin >> temp_weight >> temp_value;
		item.push_back(pair<int, int>(temp_weight, temp_value));
	}
	for (int i = 0; i <= inventory_weight; i++) {
		if (i < item[0].first) dp[i][0] = 0;
		else {
			dp[i][0] = item[0].second;
		}
	}
	
	for (int j = 1; j < item_number; j++) {
		for (int i = 1; i <= inventory_weight; i++) {
			if (item[j].first > i) {
				dp[i][j] = dp[i][j - 1];
			}
			else {
				dp[i][j] = max(dp[i][j - 1], item[j].second + dp[i - item[j].first][j - 1]);
			}
		}
	}
	cout << dp[inventory_weight][item_number - 1];
}
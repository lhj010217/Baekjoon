#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

string str1 = "";
string str2 = "";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> str1 >> str2;
	
	int result = 0;
	int** dp = new int*[str1.length() + 1];
	for (int i = 0; i <= str1.length(); i++) {
		dp[i] = new int[str2.length() + 1];
	}

	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	for (int i = 0; i <= str2.length(); i++) {
		result = max(result, dp[str1.length()][i]);
	}

	cout << result;
}
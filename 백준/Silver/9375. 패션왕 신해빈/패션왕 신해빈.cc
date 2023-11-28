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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t = 0;
	cin >> t;
	while (t--) {
		unordered_map<string, int> um;
		vector<int> v;
		int n = 0;
		cin >> n;
		if (n == 0) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			string dress = "";
			string key = "";
			cin >> dress >> key;

			auto iter = um.find(key);
			if (iter != um.end()) {
				iter->second++;
			}
			else {
				um.insert(make_pair(key, 1));
			}
		}
		int result = 1;
		for (auto iter : um) {
			result *= (iter.second + 1);
		}
		result--;
		cout << result << "\n";
	}
	

} 
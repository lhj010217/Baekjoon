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
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int k = 0;
		cin >> k;
		multiset<int, less<int>> ms;
		for (int i = 0; i < k; i++) {
			string op;
			int n;
			cin >> op >> n;

			if (op == "I") {
				ms.insert(n);
			}
			if (op == "D") {
				if (n == 1 && !ms.empty()) {
					ms.erase(--ms.end());
				}
				if (n == -1 && !ms.empty()) {
					ms.erase(ms.begin());
				}
			}
		}
		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout  << *(--ms.end()) << " " << *ms.begin() << "\n";
		}
	}

}
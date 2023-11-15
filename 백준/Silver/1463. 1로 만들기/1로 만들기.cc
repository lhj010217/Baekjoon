#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> v(1000001);
	int n;
	cin >> n;
	v[1] = 0;
	v[2] = 1;
	v[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			int temp = min(v[i/3], v[i/2]);
			v[i] = min(v[i - 1], temp) + 1;
		}
		else if (i % 3 == 0 && i%2 != 0) {
			v[i] = min(v[i-1], v[i/3]) + 1;
		}
		else if (i % 3 != 0 && i % 2 == 0) {
			v[i] = min(v[i - 1], v[i/2]) + 1;
		}
		else {
			v[i] = v[i - 1] + 1;
		}
	}

	cout << v[n];
}
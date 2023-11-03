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

	stack<long long> st;
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t = 0;
		cin >> t;
		if (t == 0) {
			st.pop();
		}
		else {
			st.push(t);
		}
	}
	int res = 0;
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	cout << res;
}
#include<iostream>
#include<stdio.h>
#include<queue>
#include<deque>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N = 0;
	int M = 0;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		cout << upper_bound(v.begin(), v.end(), t) - lower_bound(v.begin(), v.end(), t) << " ";
	}

}
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

	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int t = 0;
		cin >> t;
		if (t < x) {
			cout << t << " ";
		}
	}
}
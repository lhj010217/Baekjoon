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

	int t = 0;
	int k = 0;
	int n = 0;
	cin >> t;
	int a[15][14] = {0};
	for (int i = 0; i < 14; i++) {
		a[0][i] = i+1;
	}
	while (t--) {
		cin >> k >> n;
		for (int i = 1; i <= k; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				sum += a[i - 1][j];
				a[i][j] = sum;
			}
		}/*
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 14; j++) {
				cout << a[i][j] <<"\t";
			}
			cout << "\n";
		}*/
		cout << a[k][n - 1] << "\n";
	}
}
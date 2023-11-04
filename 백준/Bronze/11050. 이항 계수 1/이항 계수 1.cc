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

	int n, k;
	cin >> n >> k; // n!/k!*(n-k)!

	int a = 1, b = 1, c = 1;

	for (int i = 1; i <= n; i++) {
		a *= i;
	}
	for (int i = 1; i <= k; i++) {
		b *= i;
	}
	for (int i = 1; i <= n - k; i++) {
		c *= i;
	}
	cout << a / (b * c);

}
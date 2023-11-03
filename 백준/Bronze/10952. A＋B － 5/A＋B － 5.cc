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

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		cout << a + b << "\n";
	}
}
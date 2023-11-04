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
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) { break; }
		int max_n = max(a, b);
		max_n = max(max_n, c);
		int x = 0, y = 0;
		if (a == max_n) {
			x = b; y = c;
		}
		else if (b == max_n) {
			x = a; y = c;
		}
		else if (c==max_n) {
			x = a; y = b;
		}
		
		if (max_n * max_n == (x * x + y * y)) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}

	}
}
#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string x;
	string y;

	cin >> y >> x;

	if (x.length() == y.length()) {
		int res = 0;
		for (int i = 0; i < x.length(); i++) {
			if (x[i] != y[i])res++;
		}
		cout << res;
	}
	else {
		int res = 10000000;

		for (int i = 0; i <= x.length() - y.length(); i++) {
			int temp = 0;
			for (int j = i; j < i + y.length(); j++) {
				if (x[j] != y[j - i]) temp++;
			}
			res = min(res, temp);
		}
		cout << res;
	}
}
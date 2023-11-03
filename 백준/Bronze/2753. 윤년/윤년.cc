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

	int n;
	cin >> n;

	if (n%4 == 0 && n%100 != 0) {
		cout << "1";
	}
	else if (n%400 == 0) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}
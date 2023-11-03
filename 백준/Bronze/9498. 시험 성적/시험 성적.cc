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
	n = n / 10;
	if (n>=9) {
		cout << "A";
	}
	else if (n == 8) {
		cout << "B";
	}
	else if (n == 7) {
		cout << "C";
	}
	else if (n == 6) {
		cout << "D";
	}
	else {
		cout << "F";
	}
}
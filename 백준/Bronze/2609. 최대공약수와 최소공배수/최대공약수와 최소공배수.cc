#include<iostream>
#include<stack>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int getGCD(int a, int b) {
	int r = 1;
	int gcd = 0, lcm = 0;
	while (a % b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a = 0, b = 0;
	cin >> a >> b;
	int gcd = 0, lcm = 0;
	gcd = getGCD(a,b);
	lcm = a * b / gcd;
	cout << gcd << "\n" << lcm;
	
}
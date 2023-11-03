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

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << (a * a + b * b + c * c + d * d + e * e) % 10;
}
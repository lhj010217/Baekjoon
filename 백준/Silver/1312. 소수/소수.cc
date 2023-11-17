#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a, b, n;
	int res = 0;
	string s;

	cin >> a >> b >> n;
	while (n--) {
		a %= b;
		a *= 10;
		res = a / b;
	}
	cout << res;
} 
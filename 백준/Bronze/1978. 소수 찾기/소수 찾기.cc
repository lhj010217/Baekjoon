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

bool isPrime(unsigned int n) {
	if (n <= 3) return n > 1;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int res = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (isPrime(temp)) res++;
	}
	cout << res;


}
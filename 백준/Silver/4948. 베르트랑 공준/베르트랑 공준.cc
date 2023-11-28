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
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool isPrime(int n) {
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
	
	while (1) {
		int n = 0;
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime(i)) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}


} 
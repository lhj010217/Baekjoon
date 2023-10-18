#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool isDis(long long n, long long i) {
	long long dis = i;
	string s = to_string(i);
	for (int j = 0; j < s.size(); j++) {
		dis += s[j] - '0';
	}
	if (n == dis) return true;
	else return false;
}

int main() {
	long long n;
	cin >> n;
	long long res = n;
	for (long long i = n-1; i > 0; i--) {
		if (isDis(n, i)) { res = min(res, i); }
	}
	if (res == n) { cout << "0"; }
	else {
		cout << res;
	}
}
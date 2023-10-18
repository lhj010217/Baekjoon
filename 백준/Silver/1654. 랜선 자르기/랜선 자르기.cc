#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

bool fn(long long num, long long gnum, vector<long long> vec, long long p) {
	long long cnt = 0;
	for (long long i = 0; i < num; i++) {
		cnt += vec[i] / p;
	}
	if (cnt >= gnum) return true;
	else return false;
}



int main() {
	long long n = 0, m = 0;
	cin >> n >> m;
	vector <long long > v(n, 0);
	for (long long i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long L = 1;
	long long R = v[v.size() - 1];
	long long res = 0;
	while (L <= R) {
		long long p = (L + R) / 2;
		if (fn(n, m, v, p)) {
			res = max(res, p);
			L = p + 1;
		}
		else {
			R = p - 1;
		}
	}
	cout << res;
}
#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool flag = false;
	long long N = 0;
	int L = 0;
	cin >> N >> L;

	for (int i = L; i <= 100; i++) {
		double k = (N - (double)i*(i + 1) / 2) / i;
		if (k == (long long)k) {
			flag = true;
			long long res = floor(k) + 1;
			if (res >= 0) {
				for (int j = 0; j < i; j++)
					cout << res + j << " ";
				break;
			}
			else {
				flag = false;
			}
		}
		else {
			flag = false;
		}
	}
	if (!flag) {
		cout << "-1";
	}
}
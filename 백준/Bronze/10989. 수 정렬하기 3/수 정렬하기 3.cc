#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long n = 0;
	cin >> n;
	int ary[10001] = { 0 };
	for (auto i = 0; i < n; i++) {
		int t;
		cin >> t;
		ary[t]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < ary[i]; j++) {
			printf("%d\n", i);
		}
	}
}
#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int res = 0;
	while (n != 0) {
		string s = to_string(n);
		if (s.length() == 1 || s.length() == 2) {
			res++;
		}
		else {
			bool flag = true;
			int dif = s[0]-s[1];
			for (int i = 1; i < s.length() - 1; i++) {
				if (dif != s[i] - s[i + 1]) {
					flag = false;
					break;
				}
				else {
					dif = s[i - 1] - s[i];
				}
			}
			if (flag) res++;
		}
		n--;
	}
	cout << res;

}
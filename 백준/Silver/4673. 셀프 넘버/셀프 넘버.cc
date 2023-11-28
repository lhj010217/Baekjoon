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
bool self_num[100001];

int nextNum(int n) {
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++) {
		n += s[i] - '0';
	}
	return n;
}

void check(int n) {
	
	while (n < 10000) {
		n = nextNum(n);
		self_num[n] = true;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 1; i <= 10000; i++) {
		if (self_num[i] == true) {
			continue;
		}
		check(i);
	}
	for (int i = 1; i < 10001; i++) {
		if (self_num[i] == false) {
			cout << i<<"\n";
		}
	}
} 
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

int ary[100000] = { 0 };
int prefix[100000] = { 0 };

void getPrefix(int n) {
	prefix[0] = ary[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + ary[i];
	}
	return;
}

void getRes(int i, int j) {
	if (i == 0) {
		cout << prefix[j] << "\n";
	}
	else {
		cout << prefix[j] - prefix[i - 1] << "\n";
	}

	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n = 0;
	int m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
	}
	getPrefix(n);

	while (m--) {
		int i = 0;
		int j = 0;
		cin >> i >> j;

		getRes(i - 1, j - 1);
	}

} 
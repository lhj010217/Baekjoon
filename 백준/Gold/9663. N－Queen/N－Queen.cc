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

int col[15] = { 0 };
int num = 0;
int result = 0;

bool promissing(int level) {
	for (int i = 0; i < level; i++) {
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) {
			return false;
		}
	}
	return true;
}

void dfs(int x) {
	if (x == num) {
		result++;
	}
	else {
		for (int i = 0; i < num; i++) {
			col[x] = i;
			if (promissing(x)) {
				dfs(x + 1);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> num;
	dfs(0);
	cout << result;

}
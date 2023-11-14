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
	
	int ary[] = { 64,32,16,8,4,2,1 };
	int index = 0;
	int res = 0;
	int x;
	cin >> x;
	
	for (int i = 0; i < 7; i++) {
		if (x >= ary[i]) {
			res++;
			x -= ary[i];
		}
		if (x == 0)
			break;
	}

	cout << res;
}
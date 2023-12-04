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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int testCase = 0;
	cin >> testCase;

	while (testCase--) {
		int num = 0;
		vector<int> v(11);
		cin >> num;

		v[0] = 1;
		v[1] = 2;
		v[2] = 4;

		for (int i = 3; i < num; i++) {
			v[i] = v[i - 3] + v[i - 2] + v[i - 1];
		}

		cout << v[num - 1] << "\n";

	}

}
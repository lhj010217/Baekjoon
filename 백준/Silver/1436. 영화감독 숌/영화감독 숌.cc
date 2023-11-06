#include<iostream>
#include<stdio.h>
#include<queue>
#include<deque>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int iter = 0;
	int cnt = 0;
	cin >> n;
	while (cnt<n) {
		string s = to_string(iter);
		if (s.find("666") != string::npos) {
			cnt++;
			iter++;
		}
		else {
			iter++;
		}
	}
	cout << iter-1;
}
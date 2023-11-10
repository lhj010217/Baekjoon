#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n;
	int f;

	cin >> n >> f;
	n[n.size() - 2] = '0';
	n[n.size() - 1] = '0';
	int N = stoi(n);
	
	for (int i = 0; i < 100; i++) {
		if (N % f == 0) {
			break;
		}
		else {
			N++;
		}
	}
	n = to_string(N);
	cout << n[n.size() - 2] << n[n.size() - 1];
}
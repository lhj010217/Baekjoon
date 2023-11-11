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

	int S = 0;
	int T = 0;

	for (int i = 0; i < 4; i++) {
		int temp = 0;
		cin >> temp;
		S += temp;
	}
	for (int i = 0; i < 4; i++) {
		int temp = 0;
		cin >> temp;
		T += temp;
	}

	S >= T ? cout << S : cout << T;

}
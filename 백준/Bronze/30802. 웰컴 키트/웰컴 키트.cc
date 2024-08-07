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
	long long N;
	vector<long long> v(6);
	long long s, m, l, xl, xxl, xxxl;
	long long T, P;

	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> v[i];
	}
	cin >> T >> P;

	long long t_res = 0;
	for (int i = 0; i < 6; i++) {
		if (v[i] % T != 0) {
			t_res += v[i] / T + 1;
		}
		else {
			t_res += v[i] / T;
		}
	}
	cout << t_res <<"\n";
	cout << N / P << " " << N % P;
}

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

vector<int> initArr(int n) {
	vector<int> temp(n);
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; 
	vector<int> a;
	vector<int> b;
	
	cin >> N;
	a = initArr(N);
	b = initArr(N);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int res = 0;

	for (int i = 0; i < N; i++) {
		res += a[i] * b[i];
	}

	cout << res;

}
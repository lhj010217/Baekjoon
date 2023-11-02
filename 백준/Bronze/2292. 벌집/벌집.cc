#include<iostream>
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

	long long n = 0;
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	n--;
	long long left = 1;
	long long right = 6;
	long long iter = 1;
	while (n < left || n > right) {
		left = left + 6 * iter;
		right = right + 6 * (iter + 1);
		iter++;
	}
	cout << iter + 1;
}
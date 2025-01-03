#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int main() {

	long long A, B, C;
	cin >> A >> B >> C;

	long long r = 1;
	while (B != 0) {
		if (B % 2 == 1) {
			r = (r * A) % C;
		}
		A = (A * A) % C;
		B /= 2;
	}
	cout << r;

	return 0;
}
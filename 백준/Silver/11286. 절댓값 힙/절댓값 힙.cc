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

struct comp {
	bool operator()(long long n1, long long n2) {
		if (abs(n1) > abs(n2)) {
			return true;
		}
		else if (abs(n1) == abs(n2)) {
			return n1 > n2;
		}
		else {
			return false;
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long N = 0;
	priority_queue<long long, vector<long long>, comp> pq;
	scanf("%lld", &N);

	for (int i = 0; i < N; i++) {
		long long ope = 0;
		scanf("%lld", &ope);

		if (ope == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(ope);
		}
	}

}
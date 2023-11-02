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
	
	long long N = 0;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
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
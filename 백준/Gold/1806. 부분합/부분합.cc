#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
#include<numeric>
#include<limits.h>
using namespace std;


int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
	}

	long long N, S;
	long long min_value = LLONG_MAX;
	int en = 0;
	int tot = 0;

	cin >> N >> S;
	vector<long long> A(N);
	
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	
	tot = A[0];
	for (int st = 0; st < N;st++) {
		while (en < N && tot < S) {
			en++;
			if (en != N) tot += A[en];
		}

		if (en == N) break;

		min_value = min(min_value, (long long)(en - st + 1));
		tot -= A[st];
	}

	if (min_value == LLONG_MAX) min_value = 0;
	cout << min_value;

	return 0;
}
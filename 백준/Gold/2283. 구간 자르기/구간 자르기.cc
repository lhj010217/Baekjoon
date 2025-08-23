#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
#include<numeric>
#include<limits.h>
#include<math.h>
#define POINT_MAX 1000000
using namespace std;


int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
	}

	long long N, K;
	cin >> N >> K;
	vector<long long> diff(POINT_MAX + 2, 0);
	vector<long long> cover(POINT_MAX + 2, 0);
	vector<long long> prefix(POINT_MAX + 2, 0);
	long long total_len = 0;

	for (int i = 0; i < N;i++) {
		long long s, e;
		cin >> s >> e;
		diff[s] += 1;
		diff[e] -= 1;
	}

	cover[0] = diff[0];
	for (int i = 1; i <= POINT_MAX;i++) {
		cover[i] += cover[i - 1] + diff[i];
	}

	for (int i = 1;i <= POINT_MAX; i++) {
		prefix[i] = prefix[i - 1] + cover[i - 1];
	}

	long long A = 0, B = 1;
	while(B<=POINT_MAX) {
		long long covered = prefix[B] - prefix[A];
		if (covered == K) {
			cout << A << " " << B;
			return 0;
		}
		if (covered < K) {
			B++;
		}
		else {
			A++;
			if (A >= B) B = A + 1;
		}
	}
	cout << "0 0";
	return 0;
}
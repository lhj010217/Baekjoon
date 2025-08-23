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
using namespace std;


int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
	}

	int N = 0;
	cin >> N;

	vector<int> prime_check(N + 1);
	vector<int> prime;
	for (int i = 2;i <= N;i++) {
		prime_check[i] = i;
	}

	for (int i = 2;i <= sqrt(N); i++) {
		if (prime_check[i] == 0) continue;
		for (int j = i * i; j <= N;j+=i) {
			prime_check[j] = 0;
		}
	}

	for (int i = 2;i <= N;i++) {
		if (prime_check[i] != 0) {
			prime.push_back(prime_check[i]);
		}
	}

	int sum = 0;
	int res = 0;
	int left = 0;
	for (int right = 0; right < (int)prime.size(); right++) {
		while (sum > N && left < right) {
			sum -= prime[left++];
		}
		if (sum == N) {
			res++;
		}
		sum += prime[right];
	}

	if (prime_check[N] != 0) res++;
	cout << res;
	return 0;
}
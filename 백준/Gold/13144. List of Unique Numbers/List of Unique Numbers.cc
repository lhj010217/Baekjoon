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

	long long N;

	cin >> N;
	vector<long long> A(N);
	vector<bool> isUsed(100001);
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	
	int left = 0;
	long long res = 0;
	for (int right = 0; right < N; right++) {
		while (isUsed[A[right]] == true) {
			isUsed[A[left++]] = false;
		}
		isUsed[A[right]] = true;
		res += (right - left + 1);

	}

	cout << res;
	return 0;
}
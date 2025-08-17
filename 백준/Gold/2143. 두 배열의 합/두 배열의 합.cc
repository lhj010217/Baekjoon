#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
#include<numeric>
using namespace std;

vector<long long> getPartSum(vector<long long> v, long long size) {
	vector<long long> prefix(size+1, 0);
	vector<long long> partsum_v;
	partial_sum(v.begin(), v.end(), prefix.begin()+1);

	for (int i =1; i <= size; i++) {
		for (int j = i; j <= size; j++) {
			partsum_v.push_back(prefix[j] - prefix[i - 1]);
		}
	}

	return partsum_v;
}


int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}
	long long T = 0;
	long long n = 0;
	long long m = 0;
	long long cnt = 0;
	vector<long long> A;
	vector<long long> B;
	vector<long long> partsum_A;
	vector<long long> partsum_B;
	
	cin >> T;
	
	cin >> n;
	A.resize(n);
	for (int i = 0; i < n;i++) {
		cin >> A[i];
	}

	cin >> m;
	B.resize(m);
	for (int i = 0; i < m;i++) {
		cin >> B[i];
	}

	partsum_A = getPartSum(A, n);
	partsum_B = getPartSum(B, m);

	
	sort(partsum_B.begin(), partsum_B.end());
	for (auto& partsum_a : partsum_A) {
		long long low = lower_bound(partsum_B.begin(), partsum_B.end(), T - partsum_a) - partsum_B.begin();
		long long high = upper_bound(partsum_B.begin(), partsum_B.end(), T - partsum_a) - partsum_B.begin();

		cnt += high - low;
	}

	cout << cnt;
	return 0;
}
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
		cout.tie(0);
	}

	long long N, M;
	long long min_value = LLONG_MAX;
	cin >> N >> M;
	vector<long long> A(N);
	
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	
	sort(A.begin(), A.end());
	

	for (int i = 0;i < N;i++) {
		for (int j = i+1;j < N;j++) {
			if (abs(A[i] - A[j]) >= M) {
				min_value = min(min_value, abs(A[i] - A[j]));
				break;
			}
			
		}
	}

	cout << min_value;
	return 0;
}
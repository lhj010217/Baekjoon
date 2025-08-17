#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;


int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}
	
	int n;
	cin >> n;

	vector<long long> A(n);
	vector<long long> B(n);
	vector<long long> C(n);
	vector<long long> D(n);
	vector<long long> sumAB;
	vector<long long> sumCD;
	long long cnt = 0;


	for (int i = 0; i < n;i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	
	for (auto& a : A) {
		for (auto& b : B) {
			sumAB.push_back(a + b);
		}
	}

	for (auto& c : C) {
		for (auto& d : D) {
			sumCD.push_back(c + d);
		}
	}
	
	sort(sumCD.begin(), sumCD.end());

	for (int i = 0; i < sumAB.size();i++) {
		auto low = lower_bound(sumCD.begin(), sumCD.end(), sumAB[i] * -1) - sumCD.begin();
		auto high = upper_bound(sumCD.begin(), sumCD.end(), sumAB[i] * -1) - sumCD.begin();
		cnt += abs(high - low);
	}


	cout << cnt;
	return 0;
}
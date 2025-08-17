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

	int N = 0;
	vector<long long> U;
	vector<long long>sum_of_two;
	cin >> N;
	
	U.resize(N);
	for (int i = 0; i < N;i++) {
		cin >> U[i];
	}
	
	for (int i = 0; i < N;i++) {
		for (int j = i;j < N;j++) {
			sum_of_two.push_back(U[i] + U[j]);
		}
	}
	
	sort(U.begin(), U.end());
	sort(sum_of_two.begin(), sum_of_two.end());

	for (int i = N - 1;i >= 0;i--) {
		for (int j = 0;j < N;j++) {
			int index = lower_bound(sum_of_two.begin(), sum_of_two.end(), U[i] - U[j]) - sum_of_two.begin();
			if (U[i] - U[j] == sum_of_two[index]) {
				cout << U[i];
				return 0;
			}
		}
	}


	return 0;
}
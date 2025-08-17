#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;


int main() {
	int N;
	vector<int> A;
	vector<int> LIS;
	vector<int> path;
	int length = 0;

	cin >> N;
	LIS.resize(N + 1);
	path.resize(N + 1);
	A.resize(N + 1);

	for (int i = 1; i < N + 1; i++) {
		cin >> A[i];

		if (i == 1) {
			LIS[length] = A[i];
			path[i] = 0;
			continue;
		}

		if (A[i] > LIS[length]) {
			LIS[++length] = A[i];
			path[i] = length;
		}
		else {
			int pos = lower_bound(LIS.begin(), LIS.begin() + length + 1, A[i]) - LIS.begin();
			LIS[pos] = A[i];
			path[i] = pos;
		}
	}

	cout << length + 1 << "\n";

}
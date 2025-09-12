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
	int N;
	vector<long long> stones;
	bool all_one_flag = true;
	cin >> N;
	stones.resize(N);
	

	for (int i = 0; i < N;i++) {
		cin >> stones[i];
		if (stones[i] != 1) all_one_flag = false;
	}
	
	if (all_one_flag) {
		N % 2 == 0 ? cout << "koosaga" : cout << "cubelover";
	}
	else {
		long long groundy = 0;
		for (long long& stone : stones) {
			groundy ^= stone;
		}

		if (groundy != 0) cout << "koosaga";
		else cout << "cubelover";
	}
}
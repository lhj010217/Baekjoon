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
	int N;
	vector<long long> stones;

	cin >> N;
	stones.resize(N);
	
	for (int i = 0; i < N;i++) {
		cin >> stones[i];
	}
	
	long long groundy = 0;
	for (long long& stone : stones) {
		groundy ^= stone;
	}

	if (groundy != 0) cout << "koosaga";
	else cout << "cubelover";
}
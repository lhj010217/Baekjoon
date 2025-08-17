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

	int N;
	int result = -1;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N;i++) {
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	
	for (int i = 0;i < N;i++) {
		result = max(result, (N - i) * v[i]);

	}

	cout << result;
	return 0;
}
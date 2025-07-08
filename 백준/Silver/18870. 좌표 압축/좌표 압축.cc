#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<tuple<int, int, int>> v;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		v.push_back(make_tuple(num, i, -1));
	}

	sort(v.begin(), v.end(), [](auto& a, auto& b) {return get<0>(a) < get<0>(b);});

	get<2>(v[0]) = 0;
	for (int i = 1; i < N; i++) {
		get<0>(v[i]) > get<0>(v[i-1]) ? get<2>(v[i]) = get<2>(v[i-1]) + 1 : get<2>(v[i]) = get<2>(v[i-1]);
	}

	sort(v.begin(), v.end(), [](auto& a, auto& b) {return get<1>(a) < get<1>(b);});
	for (int i = 0;i < N;i++) {
		cout << get<2>(v[i]) << " ";

	}
}
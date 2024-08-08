#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		vector<pair<int, int>> v;
		for (int i = 0; i < 4; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x,y));
		}
		sort(v.begin(), v.end());

		pair<int, int> a = v[0], b = v[1], c = v[3], d = v[2];
		pair<int, int> ac = make_pair(c.first - a.first, c.second - a.second);
		pair<int, int> bd = make_pair(d.first - b.first, d.second - b.second);

		//cout << "\n===\n";
		//cout << ac.first << " , " << ac.second << "\n";
		//cout << bd.first << " , " << bd.second << "\n";

		if ((ac.first * bd.first + ac.second * bd.second == 0)
			&& (ac.first * ac.first + ac.second * ac.second == bd.first * bd.first + bd.second * bd.second))
			cout << "1\n";
		else
			cout << "0\n";
	}


}

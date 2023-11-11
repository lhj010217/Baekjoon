#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2) {
	if (p1.first < p2.first) {
		return true;
	}
	else if(p1.first == p2.first){
		return p1.second > p2.second;
	}
	else {
		return false;
	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	int m = 0;
	int inventory = 0;
	cin >> n >> m >> inventory;
	vector<vector<int>> mine(n,vector<int>(m, 0));
	vector<pair<int, int>> res;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>mine[i][j];
		}
	}

	for (int height = 256; height >= 0; height--) {
		int temp_inventory = inventory;
		int temp_time = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int dif = mine[i][j] - height;
				if (dif > 0) { // dig
					temp_time += (dif * 2);
					temp_inventory += dif;
				}
				else if (dif < 0) { // stack
					temp_time += abs(dif);
					temp_inventory -= abs(dif);
				}
			}
		}
		if (temp_inventory >= 0) {
			res.push_back(pair<int, int>(temp_time, height));
		}
	}

	sort(res.begin(), res.end(), cmp);

	cout << res[0].first << " " << res[0].second;

}
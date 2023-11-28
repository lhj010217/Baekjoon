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
#include<unordered_map>
#include<algorithm>
using namespace std;

bool visit[1001];
vector<int> v[1001];

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!visit[y]) {
			dfs(y);
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int res = 0;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i);
			res++;
		}
	}
	cout << res;
} 
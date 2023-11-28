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

bool visit[101];
vector<int> v[101];

void dfs(int x){
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
	
	int com_num = 0;
	int line_num = 0;

	cin >> com_num >> line_num;

	for (int i = 0; i < line_num; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < 100; i++) {
		visit[i] = false;
	}
	dfs(1);
	int res = 0;
	for (int i = 0; i < 101; i++) {/*
		cout << visit[i]<<"/";*/
		if (visit[i] == true) {
			res++;
		}
	}
	cout << res - 1;
} 
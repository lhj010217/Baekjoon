#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int size;
bool* dfs_visit;
bool* bfs_visit;
vector<vector<int>>v;

void init(int n) {
	dfs_visit = new bool[n + 1];
	bfs_visit = new bool[n + 1];

	for (int i = 0; i <= n; i++) {
		v.push_back(vector<int>(0));
	}
}

void dfs(int x) {
	dfs_visit[x] = true;
	cout << x << " ";
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!dfs_visit[y]) {
			dfs(y);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	bfs_visit[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!bfs_visit[y]) {
				q.push(y);
				bfs_visit[y] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int node = 0;
	int link = 0;
	int start = 0;

	cin >> node >> link >> start;
	init(node);
	for (int i = 0; i < link; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}

	for (int i = 0; i <= node; i++) {
		dfs_visit[i] = false;
		bfs_visit[i] = false;
	}

	for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(start);
	cout<<"\n";
	bfs(start);


}
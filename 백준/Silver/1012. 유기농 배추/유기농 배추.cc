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

vector<vector<bool>> bfs(vector<vector<int>> v, vector<vector<bool>> v_b, int y, int x, int n, int m) { // n이 세로, m이 가로
	queue<pair<int, int>> q;
	pair<int, int> p = make_pair(y,x);

	q.push(p);
	v_b[y][x] = true;

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		int b = temp.first; // y
		int a = temp.second; // x

		q.pop();
		if (a - 1 >= 0) {
			if (v[b][a - 1] == 1 && v_b[b][a - 1] == false) {
				q.push(make_pair(b, a - 1));
				v_b[b][a - 1] = true;
			}
		}
		if (a + 1 < m) {
			if (v[b][a + 1] == 1 && v_b[b][a + 1] == false) {
				q.push(make_pair(b, a + 1));
				v_b[b][a + 1] = true;
			}
		}
		if (b - 1 >= 0) {
			if (v[b - 1][a] == 1 && v_b[b - 1][a] == false) {
				q.push(make_pair(b - 1, a));
				v_b[b - 1][a] = true;
			}
		}
		if (b + 1 < n) {
			if (v[b + 1][a] == 1 && v_b[b + 1][a] == false) {
				q.push(make_pair(b + 1, a));
				v_b[b + 1][a] = true;
			}
		}
	}

	return v_b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T = 0;
	cin >> T;
	while (T--) {
		int m = 0;
		int n = 0;
		int k = 0;
		int result = 0;
		cin >> m >> n >> k;
		vector<vector<int>> v(n, vector<int>(m));
		vector<vector<bool>> v_b(n, vector<bool>(m));

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;

			v[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 1 && v_b[i][j] == false) {
					v_b = bfs(v, v_b, i, j, n, m);
					result++;
				}
			}
		}

		cout << result << "\n";

	}



} 
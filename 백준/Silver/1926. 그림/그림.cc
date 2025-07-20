#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

struct Point {
	int x;
	int y;
	Point(int y = 0, int x = 0) : y(y), x(x) {};
};


int n, m;

int BFS(Point start, vector<vector<int>>& paper, vector<vector<bool>>& visit, vector<vector<int>>& draw, int idx) {
	queue<Point> q;
	int dy[4] = {0, 1, 0, -1};
	int dx[4] = {1, 0, -1 ,0};
	int area = 0;

	q.push(start);
	visit[start.y][start.x] = true;
	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		draw[cur.y][cur.x] = idx;
		area++;

		for (int i = 0; i < 4; i++) {
			Point next = Point(cur.y + dy[i], cur.x + dx[i]);
			if (next.y >= 0 && next.x >= 0 && next.y < n && next.x < m) {
				if (paper[next.y][next.x] == 1 && visit[next.y][next.x] == false) {
					visit[next.y][next.x] = true;
					q.push(next);
				}
			}
		}
	}
	return area;
}


int main() {

	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}

	cin >> n >> m;

	vector<vector<int>> paper(n, vector<int>(m, 0));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	vector<vector<int>> draw(n, vector<int>(m, 0));

	queue<Point> q;
	int idx = 1;
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 1 && visit[i][j] == false) {
				area = max(area, BFS(Point(i, j), paper, visit, draw, idx++));
			}
		}
	}
	cout << idx - 1<<"\n";
	cout << area << "\n";

	return 0;
}
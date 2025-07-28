#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
#define CLASS_ROW_SIZE 5
#define CLASS_COL_SIZE 5
using namespace std;

struct Point{
	int x;
	int y;
	Point(int y, int x) : y(y), x(x) {}
};

vector<vector<char>> grid(CLASS_ROW_SIZE, vector<char>(CLASS_COL_SIZE));
vector<vector<char>> selected(CLASS_ROW_SIZE, vector<char>(CLASS_COL_SIZE));
vector<Point> seven_princess;
int result = 0;

bool bfs() {
	queue<Point> q;
	Point start = seven_princess.front();
	bool visited[CLASS_ROW_SIZE][CLASS_COL_SIZE] = { false, };
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int princess_count = 1;
	

	q.push(start);
	visited[start.y][start.x] = true;

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 4;i++) {
			Point next(cur.y + dy[i], cur.x + dx[i]);
			if (next.x >= 0 && next.x < CLASS_COL_SIZE && next.y >= 0 && next.y < CLASS_ROW_SIZE) {
				if (!visited[next.y][next.x]) {
					for (Point& tmp : seven_princess) {
						if (tmp.y == next.y && tmp.x == next.x) {
							q.push(next);
							visited[next.y][next.x] = true;
							princess_count++;
							break;
						}
					}
				}
			}
		}
	}
	return princess_count == 7;
}

void backTracking(int start_idx, int depth, int count_S) {
	if (depth == 7) {
		if (count_S >= 4 && bfs()) {
			result++;
		}
	}
	
	for (int i = start_idx; i < 25; i++) {
		int y = i / 5;
		int x = i % 5;
		int is_S = (grid[y][x] == 'S' ? 1 : 0);

		seven_princess.push_back(Point(y, x));
		backTracking(i + 1, depth + 1, count_S + is_S);
		seven_princess.pop_back();
	}
}


int main() {

	for (int i = 0; i < CLASS_ROW_SIZE;i++) {
		for (int j = 0;j < CLASS_COL_SIZE;j++) {
			cin >> grid[i][j];
		}
	}
	
	backTracking(0, 0, 0);
	cout<<result;
	return 0;
}
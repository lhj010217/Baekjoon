#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#define KNIGHT_MOVE_NUMBER 8
using namespace std;

struct Point{
	int x;
	int y;
	Point(int y = 0, int x = 0) : y(y), x(x){}
};

int main() {
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int T;
	cin >> T;

	while (T--) {
		int size;
		int start_x, start_y, end_x, end_y;
		cin >> size;
		cin >> start_x >> start_y >> end_x >> end_y;

		Point start = Point(start_y, start_x);
		Point end = Point(end_y, end_x);

		vector<vector<int>> board(size, vector<int>(size,-1));
		queue<Point> knight;
		knight.push(start);
		board[start.y][start.x] = 0;
		while (!knight.empty()) {
			Point cur = knight.front();
			knight.pop();

			if (cur.x == end.x && cur.y == end.y) {
				cout << board[cur.y][cur.x] << "\n";
			}

			int dx[KNIGHT_MOVE_NUMBER] = {2, 1, -1, -2, -2, -1, 1, 2};
			int dy[KNIGHT_MOVE_NUMBER] = { 1, 2, 2, 1, -1, -2, -2, -1 };
			
			for (int i = 0; i < KNIGHT_MOVE_NUMBER; i++) {
				Point next = Point(cur.y + dy[i], cur.x + dx[i]);
				
				if (next.x >= 0 && next.x < size && next.y >= 0 && next.y < size) {
					if (board[next.y][next.x] == -1) {
						knight.push(next);
						board[next.y][next.x] = board[cur.y][cur.x] + 1;
					}
				}
			}
		}
	}

	return 0;
}
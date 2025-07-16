#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

struct Point{
	int x;
	int y;
	Point(int y = 0, int x = 0) : y(y), x(x){}
};

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		int w, h;
		cin >> w >> h;

		int time = -1;
		queue<Point> fire;
		queue<Point> move;
		vector<vector<char>> building(h, vector<char>(w));
		vector<vector<int>> fire_time(h, vector<int>(w, -1));
		vector<vector<int>> move_time(h, vector<int>(w, -1));
		int next_x[4] = { 1, 0, -1, 0 };
		int next_y[4] = { 0, 1, 0, -1 };

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> building[i][j];
				if (building[i][j] == '@') {
					move.push(Point(i, j));
					move_time[i][j] = 0;
				}
				else if (building[i][j] == '*') {
					fire.push(Point(i,j));
					fire_time[i][j] = 0;
				}
			}
		}
		
		while (!fire.empty()) {
			Point cur_fire = fire.front();
			fire.pop();
			for (int iter = 0; iter < 4; iter++) {
				Point next_fire = Point(cur_fire.y + next_y[iter], cur_fire.x + next_x[iter]);
				if (next_fire.y >= 0 && next_fire.y < h && next_fire.x >= 0 && next_fire.x < w) {
					if (building[next_fire.y][next_fire.x] == '.' && fire_time[next_fire.y][next_fire.x] == -1) {
						fire_time[next_fire.y][next_fire.x] = fire_time[cur_fire.y][cur_fire.x] + 1;
						fire.push(Point(next_fire.y, next_fire.x));
					}
				}
			}
		}

		bool flag = false;
		while (!move.empty()) {
			Point cur_move = move.front();
			move.pop();

			if (cur_move.x == 0 || cur_move.y == 0 || cur_move.x == w - 1 || cur_move.y == h - 1) {
				cout << move_time[cur_move.y][cur_move.x] + 1 << "\n";
				flag = true;
				break;
			}

			for (int iter = 0; iter < 4; iter++) {
				Point next_move = Point(cur_move.y + next_y[iter], cur_move.x + next_x[iter]);
				if (next_move.y >= 0 && next_move.y < h && next_move.x >= 0 && next_move.x < w) {
					if (building[next_move.y][next_move.x] == '.' && move_time[next_move.y][next_move.x] == -1 && 
						((fire_time[next_move.y][next_move.x] > move_time[cur_move.y][cur_move.x] + 1) || fire_time[next_move.y][next_move.x] == -1)) {

						move_time[next_move.y][next_move.x] = move_time[cur_move.y][cur_move.x] + 1;
						move.push(Point(next_move.y, next_move.x));
					}
				}
			}
		}

		if (!flag) {
			cout << "IMPOSSIBLE\n";
		}
	}



	return 0;
}
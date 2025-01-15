#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

struct Pos {
	int row;
	int col;
	int height;
};

int main() {

	int M = 0, N = 0, H=0;
	cin >> M >> N >> H;

	queue<pair<Pos, int>> q;
	vector<vector<vector<int>>> map(H, vector<vector<int>>(N, vector<int>(M)));

	for (int k = 0;k < H;k++) {
		for (int i = 0; i < N;i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[k][i][j];
				if (map[k][i][j] == 1) {
					q.push(make_pair(Pos{i, j, k}, 0));
				}
				if (map[k][i][j] == -1) {
					;
				}
			}
		}
	}
	
	int days = -1;
	while (!q.empty()) {
		Pos cur_pos = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		map[cur_pos.height][cur_pos.row][cur_pos.col] = 1;
		days = max(days, cur_time);

		int x[] = { 0, 0, 1, -1, 0, 0 };
		int y[] = { 1, -1, 0, 0, 0, 0 };
		int h[] = { 0 ,0 ,0 ,0, 1, -1 };
		for (int iter = 0; iter < 6; iter++) {
			int next_x = cur_pos.col + x[iter];
			int next_y = cur_pos.row + y[iter];
			int next_h = cur_pos.height + h[iter];
			if (next_x < 0 || next_x > M - 1 || next_y <0 || next_y > N - 1 || next_h <0 || next_h > H-1) {
				continue;
			}
			
			if (map[next_h][next_y][next_x] == 0) {
				Pos next = { next_y, next_x, next_h };
				q.push(make_pair(next, cur_time + 1));
				map[next_h][next_y][next_x] = 1;
			}
		}
	}

	for (int k = 0;k < H;k++) {
		for (int i = 0; i < N;i++) {
			for (int j = 0; j < M; j++) {
				if(map[k][i][j]== 0){
					cout << "-1";
					return 0;
				}
			}
		}
	}

	cout << days;

	return 0;
}
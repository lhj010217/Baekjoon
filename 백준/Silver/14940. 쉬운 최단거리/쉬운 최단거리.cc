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
};

int main() {

	int N = 0, M = 0;
	cin >> N >> M;

	queue<pair<Pos, int>> q;
	vector<vector<int>> map(N, vector<int>(M));
	vector<vector<bool>> visit(N, vector<bool>(M));
	vector<vector<int>> time(N, vector<int>(M));
	Pos start = { 0,0 };
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				start.row = i;
				start.col = j;
			}
		}
	}

	q.push(make_pair(start, 0));

	while (!q.empty()) {
		Pos cur_pos = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		visit[cur_pos.row][cur_pos.col] = true;
		time[cur_pos.row][cur_pos.col] = cur_time;

		int x[] = { 0,0,1,-1 };
		int y[] = { -1, 1, 0, 0 };

		for (int iter = 0; iter < 4; iter++) {
			int next_x = cur_pos.col + x[iter];
			int next_y = cur_pos.row + y[iter];

			if (next_x < 0 || next_x > M - 1 || next_y <0 || next_y > N - 1) {
				continue;
			}
			
			if (map[next_y][next_x] == 1 && visit[next_y][next_x] == false) {
				Pos next = { next_y, next_x };
				q.push(make_pair(next, cur_time + 1));
				visit[next_y][next_x] = true;
			}
			
		}
	}

	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M;j++) {
			if (map[i][j] == 2) {
				cout << "0 ";
			}
			else if (map[i][j] == 0) {
				cout << "0 ";
			}
			else if (map[i][j] == 1 && visit[i][j] == true) {
				cout << time[i][j] << " ";
			}
			else if (map[i][j] == 1 && visit[i][j] == false) {
				cout << "-1 ";
			}
		}
		cout << "\n";
	}

	return 0;
}
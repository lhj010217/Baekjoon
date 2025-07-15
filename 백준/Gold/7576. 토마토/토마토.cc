#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;


int main() {
	int M, N;
	cin >> M >> N;

	vector<vector<int>> container(N, vector<int>(M));
	queue<tuple<int, int, int>> q; // tomato, y, x
	int no_tomato = 0;
	int day = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> container[i][j];
			if (container[i][j] == 1) {
				q.push(make_tuple(container[i][j], i, j));
			}
			if (container[i][j] == -1) {
				no_tomato++;
			}
		}
	}
	
	// queue가 비어있으면 익은 토마토가 없는 상태
	if (q.empty()) {
		cout << "-1";
		return 0;
	}
	// q의 size가 (전체 칸 개수 - 토마토가 없는 칸 개수)라면 이미 모든 토마토가 익은 상태
	if (q.size() == N * M - no_tomato) {
		cout << "0";
		return 0;
	}


	while (!q.empty()) {
		int size = q.size();
		day++;

		for (int i = 0; i < size; i++) {
			int tomato = get<0>(q.front());
			int y = get<1>(q.front());
			int x = get<2>(q.front());
			q.pop();

			int x_weight[4] = { 1, 0, -1, 0 };
			int y_weight[4] = { 0, 1, 0, -1 };

			for (int iter = 0; iter < 4; iter++) {
				int next_y = y + y_weight[iter];
				int next_x = x + x_weight[iter];
				if (next_y > -1 && next_x > -1 && next_y < N && next_x < M) {
					if (container[next_y][next_x] == 0) {
						container[next_y][next_x] = 1;
						q.push(make_tuple(container[next_y][next_x], next_y, next_x));
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (container[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << day;
}
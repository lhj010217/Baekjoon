#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<set>
using namespace std;

vector<int> graph[101];
vector<vector<int>> matrix(101, vector<int>(101, 0));

void bfs(int start, int N) {
	queue<int> q;
	vector<bool> visit(N + 1, false);

	q.push(start);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : graph[cur]) {
			if (!visit[next]) {
				visit[next] = true;
				matrix[start][next] = 1;
				q.push(next);
			}
		}
	}

	return;
}

int main() {
	int N = 0;
	cin >> N;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			int cur;
			cin >> cur;
			if (cur == 1) {
				graph[i].push_back(j);
			}
		}
	}

	for (int start = 1; start < N + 1; start++) {
		bfs(start, N);
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;
}






#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<set>
#define MAX_NODE 10000
#define MAX_EDGE 100000
using namespace std;

vector<int> graph[MAX_NODE + 1];
vector<int> hack(MAX_NODE + 1);
int max_hack = -1;

void bfs(int start) {
	queue<int> q;
	vector<bool> visit(MAX_NODE + 1, false);
	int num_hack = 0;

	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (auto next : graph[cur]) {
			if (visit[next] == false) {
				q.push(next);
				visit[next] = true;
				num_hack++;
			}
		}
	}
	
	hack[start] = num_hack;
	max_hack = max(max_hack, num_hack);
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		graph[end].push_back(start);
	}
	
	for (int i = 1; i < N + 1; i++) {
		bfs(i);
	}

	for (int i = 1; i < N + 1; i++) {
		if (hack[i] == max_hack) {
			cout << i << " ";
		}
	}

	return 0;
}
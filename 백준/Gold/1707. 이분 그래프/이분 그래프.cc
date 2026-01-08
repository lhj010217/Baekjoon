#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
#include<numeric>
#include<climits>
#define V_MAX 20001
using namespace std;

vector<char> color(V_MAX);
vector<int> graph[V_MAX];

bool bfs(int start) {
	if (color[start] != 0) {
		return true;
	}
	
	queue<int> q;
	
	q.push(start);
	color[start] = 'R';

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : graph[cur]) {
			if (color[next] == color[cur]) {
				return false;
			}
			if (color[next] == 0) {
				color[cur] == 'R' ? color[next] = 'B' : color[next] = 'R';
				q.push(next);
			}
		}
	}

	return true;
}

int main() {
	int K;
	cin >> K;

	while (K--) {
		int is_bipartie = true;
		int V, E;
		cin >> V >> E;

		for (int i = 0; i <= V; ++i) {
			graph[i].clear();
		}
		fill(color.begin(), color.end(), 0);

		for (int i = 0; i < E; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		for (int i = 1; i < V + 1; i++) {
			if (bfs(i) == false) {
				is_bipartie = false;
				break;
			}
		}
		
		if (is_bipartie == true) {
			cout << "YES" << "\n";
		}
		if (is_bipartie == false) {
			cout << "NO" << "\n";
		}
	}
	


}
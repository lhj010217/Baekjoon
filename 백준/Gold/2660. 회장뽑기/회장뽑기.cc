#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
#include<numeric>
#include<climits>
#define MAX 51
using namespace std;

int N;
vector<int> friends[MAX];

int bfs(int start) {
	vector<int> dist(N + 1, -1);
	queue<int> q;
	int score = 0;

	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : friends[cur]) {
			if (dist[next] == -1) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}

	for (int i = 1; i < N + 1; i++) {
		score = max(score, dist[i]);
	}
	return score;
}

int main() {
	vector<int> candidates;
	int score[MAX];
	int min_score = INT_MAX;

	cin >> N;
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	
	for (int i = 1; i < N + 1; i++) {
		score[i] = bfs(i);
		min_score = min(min_score, score[i]);
	}

	for (int i = 1; i < N + 1; i++) {
		if (score[i] == min_score) {
			candidates.push_back(i);
		}
	}


	cout << min_score << " " << candidates.size() << "\n";
	for (int i = 0; i < candidates.size(); i++) {
		cout << candidates[i] << " ";
	}

}
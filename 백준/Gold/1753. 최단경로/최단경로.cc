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
using namespace std;

int main() {
	{
		/*ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);*/
	}
	
	int V = 0, E = 0;
	int start_vertex = 0;

	scanf("%d %d", &V, &E);
	scanf("%d", &start_vertex);

	//cin >> V >> E >> start_vertex;

	vector<vector<pair<int,int>>> adj(V+1);
	vector<int> dist(V+1, INT_MAX);
	priority_queue<pair<int,int>> pq;
	
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		//cin >> u >> v >> w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(w, v));
	}
	

	pq.push(make_pair(0, start_vertex));
	dist[start_vertex] = 0;

	while (!pq.empty()) {
		int cur_node = pq.top().second;
		int cur_weight = -pq.top().first;
		pq.pop();
		
		if (cur_weight > dist[cur_node]) continue;

		for (auto e : adj[cur_node]) {
			int temp_weight = cur_weight + e.first;
			if (temp_weight < dist[e.second]) {
				pq.push(make_pair(-temp_weight, e.second));
				dist[e.second] = temp_weight;
			}
		}
	}
	
	for (int i = 1;i < V + 1;i++) {
		if (dist[i] != INT_MAX) {
			printf("%d\n", dist[i]);
		}
		else {
			printf("INF\n");
		}
	}


	
	
	return 0;
}
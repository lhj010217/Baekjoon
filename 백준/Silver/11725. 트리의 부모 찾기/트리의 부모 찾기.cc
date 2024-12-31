#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;



int main() {
	int N = 0;
	cin >> N;
	

	vector<vector<int>> tree(N+1);
	
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	vector<int> res(N+1, 0);
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur_root = q.front();
		q.pop();
		
		for (int e : tree[cur_root]) {
			if (res[e] == 0) {
				res[e] = cur_root;
				q.push(e);
			}
		}
	}

	for (int i = 2;i < N + 1;i++) {
		cout << res[i]<<"\n";
	}
	return 0;
}
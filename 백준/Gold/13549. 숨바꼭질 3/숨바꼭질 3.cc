#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#define MAX_POS 100000
#define MIN_POS 0
using namespace std;

int main() {

	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}

	int N = 0, K = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<bool> visit(MAX_POS + 1);
	cin >> N >> K;


	q.push(make_pair(0, N));
	visit[N] = true;
	bool first = true;
	int time = 0;
	int ways = 0;

	while (!q.empty()) {
		int cur_time = q.top().first;
		int cur_pos = q.top().second;
		q.pop();
		visit[cur_pos] = true;

		if (cur_pos == K) {
			time = cur_time;
			break;
		}
		
		if (first) {
			if (cur_pos < MAX_POS && visit[cur_pos + 1] != true) {
				q.push(make_pair(cur_time + 1, cur_pos + 1));
			}
			if (cur_pos > MIN_POS && visit[cur_pos - 1] != true) {
				q.push(make_pair(cur_time + 1,cur_pos - 1));
			}
			if (cur_pos * 2 <= MAX_POS && visit[cur_pos * 2] != true) {
				q.push(make_pair(cur_time,cur_pos * 2));
			}
		}
	}
	
	cout << time;

	return 0;
}
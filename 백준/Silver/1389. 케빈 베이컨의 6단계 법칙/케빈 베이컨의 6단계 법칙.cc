#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<set>
#define MAX_NODE 100
#define MAX_EDGE 5000
#define INF 1e9
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(MAX_NODE + 1, vector<int>(MAX_NODE + 1, INF));
	
	for (int i = 1; i < N + 1; i++) {
		v[i][i] = 0;
	}
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v[a][b] = v[b][a] = 1;
	}
	
	for (int k = 1; k < N + 1; k++) {
		for (int a = 1; a < N + 1; a++) {
			for (int b = 1; b < N + 1; b++) {
				v[a][b] = min(v[a][b], v[a][k] + v[k][b]);
			}
		}
	}

	int res = 1;
	int min_kb = INF;
	
	for (int i = 1; i < N + 1; i++) {
		int kb = 0;
		for (int j = 1; j < N + 1; j++) {
			kb += v[i][j];
		}
		if (kb < min_kb) {
			min_kb = kb;
			res = i;
		}
	}

	cout << res;
	return 0;
}
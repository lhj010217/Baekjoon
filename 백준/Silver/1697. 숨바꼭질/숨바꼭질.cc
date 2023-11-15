#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#define MAX 100001
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int,int>> q;
	bool visit[MAX];

	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < MAX; i++) {
		visit[i] = false;
	}
	visit[n] = true;
	q.push(pair<int,int>(n,0));
	
	while (!q.empty()) {
		int temp_x = q.front().first;
		int temp_cnt = q.front().second;
		q.pop();

		if (temp_x == k) {
			cout << temp_cnt;
			break;
		}
			if (temp_x - 1 >= 0) {
				if (visit[temp_x - 1] == false) {
					q.push(pair<int, int>(temp_x - 1, temp_cnt + 1));
					visit[temp_x - 1] = true;
				}
			}
			if (temp_x + 1 < MAX) {
				if (visit[temp_x + 1] == false) {
					q.push(pair<int, int>(temp_x + 1, temp_cnt + 1));
					visit[temp_x + 1] = true;
				}
			}
			if (temp_x * 2 < MAX) {
				if (visit[temp_x *2] == false) {
					q.push(pair<int, int>(temp_x * 2, temp_cnt + 1));
					visit[temp_x * 2] = true;
				}
			}
		
	}
	

}
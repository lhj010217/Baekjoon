#include<iostream>
#include<stdio.h>
#include<queue>
#include<deque>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int testCase_num;
	cin >> testCase_num;

	while (testCase_num--) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		int file_num, target;
		int result = 0;
		cin >> file_num >> target;


		for (int i = 0; i < file_num; i++) {
			int temp_num;
			cin >> temp_num;

			q.push(pair<int,int>(temp_num, i));
			pq.push(temp_num);
		}
		while (!q.empty()) {
			int loc = q.front().second;
			int val = q.front().first;
			q.pop();

			if (pq.top() == val) {
				pq.pop();
				result++;
				if (loc == target) {
					cout << result << "\n";
					break;
				}
			}
			else {
				q.push(pair<int, int>(val, loc));
			}


		}
	}
}
#include<iostream>
#include<stdio.h>
#include<queue>
#include<deque>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	deque<int> dq;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string ope;
		cin >> ope;
		if (ope == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (ope == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (ope == "pop_front") {
			if (dq.empty()) { cout << "-1\n"; }
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (ope == "pop_back") {
			if (dq.empty()) { cout << "-1\n"; }
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (ope == "size") {
			cout << dq.size() << "\n";
		}
		else if (ope == "empty") {
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (ope == "front") {
			if (dq.empty()) { cout << "-1\n"; }
			else cout << dq.front() << "\n";
		}
		else if (ope == "back") {
			if (dq.empty()) { cout << "-1\n"; }
			else cout << dq.back() << "\n";
		}
	}


}
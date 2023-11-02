#include<iostream>
#include<stdio.h>
#include<queue>
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
	
	stack<int> st;
	int ope_n = 0;
	cin >> ope_n;
	for (int i = 0; i < ope_n; i++) {
		string ope;
		cin >> ope;
		if (ope == "push") {
			int num = 0;
			cin >> num;
			st.push(num);
			continue;
		}
		else if (ope == "pop") {
			if (st.empty())	cout << "-1\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
			continue;
		}
		else if (ope == "size") {
			cout << st.size() << "\n";
			continue;
		}
		else if (ope == "empty") {
			if (st.empty()) cout << "1\n";
			else cout << "0\n";
			continue;
		}
		else if (ope == "top") {
			if (st.empty()) cout << "-1\n";
			else {
				cout << st.top() << "\n";
			}
			continue;
		}
	}

}
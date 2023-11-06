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
#include<unordered_set>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		string s;
		getline(cin, s);
		if (s == ".") break;

		stack<char> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') st.push('(');
			else if (s[i] == '[') st.push('[');
			else if (s[i] == ')') {
				if (!st.empty()) {
					if (st.top() == '(') st.pop();
					else if (st.top() == '[') {
						st.push(' ');
						break;
					}
				}
				else {
					st.push(' ');
					break;
				}
			}
			else if (s[i] == ']') {
				if (!st.empty()) {
					if (st.top() == '[') st.pop();
					else if (st.top() == '(') {
						st.push(' ');
						break;
					}
				}
				else {
					st.push(' ');
					break;
				}
			}
		}

		if (st.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}
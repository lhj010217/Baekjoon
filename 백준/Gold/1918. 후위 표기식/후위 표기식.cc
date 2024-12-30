#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<map>
#include<set>
#include<stack>

using namespace std;



int main() {
	stack<char> st;
	string str;
	cin >> str;
	int str_len = str.length();
	for (int i = 0;i < str_len; i++) {
		char c = str[i];
		if (c >= 'A' && c  <= 'Z')
			cout << c;
		else if (c == '+' || c == '-') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.push(c);
		}
		else if (c == '*' || c == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(c);
		}
		else if (c == '(') {
			st.push('(');
		}
		else if (c == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}

	}
	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}
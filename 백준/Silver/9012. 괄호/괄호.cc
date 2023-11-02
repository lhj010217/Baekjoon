#include<iostream>
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

	int n = 0;
	cin >> n;
	
	stack<char> s;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') {
				s.push(str[j]);
			}
			else if (str[j] == ')') {
				if (s.empty()) {
					cout << "NO\n";
					break;
				}
				else {
					s.pop();
				}
			}
			if (j == str.length() - 1) {
				if (!s.empty()) cout << "NO\n";
				else cout << "YES\n";
				while (!s.empty()) {
					s.pop();
				}
			}
		}
	}

}
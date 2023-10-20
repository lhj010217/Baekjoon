#include<iostream>
#include<stack>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int size = 0;
	int target = 0;
	int cur = 1;
	cin >> size;
	stack<int> s;
	vector<string> res;
	for (int i = 0; i < size; i++) {
		cin >> target;
		if (!s.empty() && s.top() == target) {
			s.pop();
			res.push_back("-");
		}
		else if (cur <= target) {
			while (cur <= target) {
				s.push(cur++);
				res.push_back("+");
			}
			s.pop();
			res.push_back("-");
		}
		else if (!s.empty() && s.top() > target) {
			cout << "NO";
			return 0;
		}
	}

	for (auto x:res) {
		cout << x << '\n';
	}
}
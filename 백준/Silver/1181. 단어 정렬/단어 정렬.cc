#include<iostream>
#include<queue>
#include<cmath>
#include<tuple>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct node {
	string str;
	int strlen;
	
	bool operator<(const node& a) const {
		if (a.strlen != this->strlen) return a.strlen < this->strlen;
		else return a.str < this->str;
	}
};

priority_queue<node> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		node temp;
		cin >> temp.str;
		temp.strlen = temp.str.length();
		
		pq.push(temp);
	}
	string s = "";
	for (int i = 0; i < n; i++) {
		node output;
		output = pq.top();
		pq.pop();
		if (output.str == s) continue;
		s = output.str;
		cout << s << "\n";
	}

}
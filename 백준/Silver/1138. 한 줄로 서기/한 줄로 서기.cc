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

	int n = 0;
	cin >> n;
	int num = n;
	vector<int> person(n);
	stack<int> information;
	
	for (int i = 0; i < n; i++) {
		person[i] = n - i;
		int temp;
		cin >> temp;
		information.push(temp);
	}

	for (int target = n; target > 0; target--) {
		int left = information.top();
		information.pop();

		int cnt = 0;
		int index = 0;
		auto iter = person.begin();
		for (int i = 0; person[i] != target; i++) {
			if (person[i] > target) {
				cnt++;
			}
			index++;
			iter++;
		}
		if (cnt > left) {
			int temp = *iter;
			person.erase(person.begin()+index);
			person.insert(person.begin() + left, temp);
		}
	}
	for (int i = 0; i < person.size(); i++) {
		cout << person[i] << " ";
	}
}
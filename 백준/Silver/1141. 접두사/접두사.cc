#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		bool flag = true;
		for (int j = 0; j < v.size(); j++) {
			if (i != j && v[i].length() <= v[j].length()) {

				if (v[j].find(v[i]) == 0) {
					flag = false;
				}
			}
		}
		if (flag == true) {
			result++;
		}
	}

	cout << result;

}

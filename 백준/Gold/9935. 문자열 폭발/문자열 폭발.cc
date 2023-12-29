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

deque<char> dq;
string str = "";
string boomStr = "";

void checkExplode(string boom, int boomLen) {
	bool flag = true;
	auto dqIter = dq.end();
	for (int i = 0; i < boomLen; i++) {
		if (boom[boomLen - 1 - i] != dq.at(dq.size() - 1 - i)) {
			flag = false;
		}
	}
	if (flag) {
		for (int i = 0; i < boomLen; i++) {
			dq.pop_back();
		}
	}
	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	cin >> boomStr;

	int strLen = str.length();
	int boomStrLen = boomStr.length();
	
	for (int i = 0; i < strLen; i++) {
		dq.push_back(str[i]);
		if (dq.size() >= boomStrLen) {
			checkExplode(boomStr, boomStrLen);
		}
	}


	if (dq.empty()) {
		cout << "FRULA";
	}
	else {
		while (!dq.empty()) {
			cout << dq.front();
			dq.pop_front();
		}
	}

}
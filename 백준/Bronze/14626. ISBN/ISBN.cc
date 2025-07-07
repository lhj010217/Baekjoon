#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;


int main() {
	string s;
	cin >> s;
	int len = s.length();
	int check = s[len - 1] - '0';
	int weight = 0;
	int position = 0;
	int result = 0;

	for (int i = 0; i < len - 1; i++) {
		if (s[i] == '*') {
			position = (i % 2 == 0) ? 1 : 3;
			continue;
		}
		if (i % 2 == 0) {
			weight += (s[i] - '0') * 1;
		}
		else {
			weight += (s[i] - '0') * 3;
		}
	}
	for (int x = 0; x < 10;x++) {
		if ((x * position + weight + check) % 10 == 0) {
			result = x;
			break;
		}
	}
	cout << result;

}
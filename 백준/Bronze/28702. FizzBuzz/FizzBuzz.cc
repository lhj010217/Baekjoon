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
	int nextNum = 0;
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			nextNum = stoi(s) + (3-i);
			break;
		}
	}

	if (nextNum % 5 == 0 && nextNum % 3 == 0) cout << "FizzBuzz";
	else if (nextNum % 5 != 0 && nextNum % 3 == 0) cout << "Fizz";
	else if (nextNum % 5 == 0 && nextNum % 3 != 0) cout << "Buzz";
	else cout << nextNum;
}

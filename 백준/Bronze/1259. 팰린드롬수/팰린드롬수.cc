#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	while (1) {
		bool isF = true;
		cin >> s;
		if (s == "0") { exit(0); }
		for (int i = 0; i < s.size() / 2 + 1; i++) {
			if (s[i] != s[s.size() - 1 - i]) {
				isF = false;
			}
		}
		if (isF) cout << "yes" << endl;
		else  cout << "no" << endl;
	}
}
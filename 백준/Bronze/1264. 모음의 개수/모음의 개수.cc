#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int main() {
	while (true) {
		string s;
		getline(cin, s);
		if (s == "#") return 0;
		int len = s.length();
		int sum = 0;
		for (int i = 0; i < len; i++) {
			char c = s[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
				sum++;
			}
		}
		cout << sum << "\n";
	}

	return 0;
}
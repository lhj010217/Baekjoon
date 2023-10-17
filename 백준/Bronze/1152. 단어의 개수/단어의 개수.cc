#include<iostream>
#include<string>
using namespace std;

int main() {
	int num = 0;
	int iter = 0;

	string s;
	getline(cin,s);
	if (s.empty()) { cout << "0"; }
	for (int i = 0; i <= s.size(); i++) {
		if (isalpha(s[i])) {
			for (int j = i; j<=s.size() ; j++) {
				if (s[j] == ' ' || j==s.size()) {
					num++;
					i = j;
					break;
				}
			}
		}
	}
	cout << num;
}
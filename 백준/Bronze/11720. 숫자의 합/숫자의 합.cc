#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	int res = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		res = res + (s[i]-'0');
	}
	cout << res;
}
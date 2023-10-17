#include<iostream>
#include<string>
using namespace std;

int main() {
	int r = 0;
	string s;
	cin >> r;
	for (int i = 0; i < r; i++) {
		int sum = 0;
		int score = 1;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'O') {
				sum = sum + score++;
			}
			if (s[j] == 'X') {
				score = 1;
			}
		}
		cout << sum << endl;
	}
}
#include<iostream>
#include<string>
using namespace std;

int main() {
	int a[26] = {0,};
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		a[toupper(s[i]) - 65]++;
	}

	int max_num = a[0];

	for (int i = 1; i < 26; i++) {
		max_num = max(max_num, a[i]);
	}

	for (int i = 0; i < 26; i++) {
		if (a[i] == max_num) {
			for (int j = i+1; j < 26; j++) {
				if (a[j] == max_num) {
					cout << '?';
					exit(0);
				}
			}
			char c = 65+i;
			cout << c;
			break;
		}
	}
}
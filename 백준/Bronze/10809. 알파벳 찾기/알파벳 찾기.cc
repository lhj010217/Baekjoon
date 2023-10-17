#include<iostream>
#include<string>
using namespace std;

int main() {
	int res[26];
	bool Ex = false;
	string s;
	cin >> s;

	fill_n(res, 26, -1);
	for (int i = 0; i < s.size(); i++) {
		if (i > 0) {
			for (int j = i-1; j >= 0; j--) {
				if (s[i] == s[j]) {
					Ex = true; 
					break;
				}
				else Ex = false;
			}
		}
		if(!Ex)	res[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << res[i] << " ";
	}
}
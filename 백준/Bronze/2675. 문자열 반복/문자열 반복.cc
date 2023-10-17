#include<iostream>
#include<string>
using namespace std;

int main() {
	int test_num = 0;
	int r = 0;
	string s;
	cin >> test_num;
	for (int i = 0; i < test_num; i++) {
		cin >> r >> s;
		for (int j = 0; j < s.size(); j++) {
			for (int k = 0; k < r; k++) {
				cout << s[j];
			}
		}
		cout << endl;
	}
}
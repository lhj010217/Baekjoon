#include<iostream>
#include<string>
using namespace std;

int main() {
	int ary[10] = { 0, };
	int num = 0;
	int a, b, c = 0;
	string s;
	cin >> a >> b >> c;
	num = a * b * c;
	s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		ary[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << ary[i] << endl;
	}
}
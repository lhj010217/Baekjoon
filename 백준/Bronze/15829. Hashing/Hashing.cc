#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int num = 0;
	int res = 0;
	int M = 1234567891;
	string s;
	cin >> num;
	cin >> s;
	for (int i = 0; i < num; i++) {
		res += (s[i] - 'a' + 1) * pow(31, i);
	}
	cout << res%M;

}
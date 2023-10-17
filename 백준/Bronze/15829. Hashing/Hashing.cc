#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int main() {
	int num = 0;
	long long res = 0;
	int M = 1234567891;
	string s;
	cin >> num;
	cin >> s;
	for (int i = 0; i < num; i++) {
		long long pow = 1;
		for (int j = 0; j < i; j++) {
			pow = pow * 31;
			pow = pow % M;
		}
		res += (s[i] - 'a' + 1) * pow;
	}
	cout << res % M;
}
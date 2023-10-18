#include<iostream>
#include<cmath>
#include<string>
using namespace std;


int main() {
	long long a=0, b = 0, v = 0;
	long long h = 0;
	long long cnt = 0;
	cin >> a >> b >> v;
	if (a == v) { cout << "1"; exit(0); }
	(v - a) % (a - b) == 0 ? cnt = (v - a) / (a - b) + 1 : cnt = (v - a) / (a - b) + 2;
	cout << cnt;
}
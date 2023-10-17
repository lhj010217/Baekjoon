#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int t = 0;
	int h = 0;
	int w = 0;
	int n = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		n% h == 0 ? cout << h : cout << n % h;
		cout.width(2);
		cout.fill('0');
		cout << ceil((float)n/h) << endl;
	}
}
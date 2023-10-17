#include<iostream>
#include<string>
using namespace std;


int main() {
	int n;
	int a = 0;
	int b = 0;
	int res;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x = i;
		while (x % 2 == 0) {
			x /= 2;
			a++;
		}
		while (x % 5 == 0) {
			x /= 5;
			b++;
		}
	}
	a < b ? res = a : res = b;
	cout << res;
}
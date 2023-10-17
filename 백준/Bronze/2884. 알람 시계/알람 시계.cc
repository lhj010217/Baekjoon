#include<iostream>
#include<string>
using namespace std;

int main() {
	int n1, n2 = 0;
	cin >> n1 >> n2;
	if (n2 < 45) {
		if (n1 == 0) n1 = 23;
		else n1--;
		n2 = n2 + 15;
	}
	else {
		n2 = n2 - 45;
	}
	cout << n1 << " " << n2;
}
#include<iostream>
using namespace std;

int main() {
	int ary[9] = { 0, };
	int max_num = 0;
	int a, b = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a;
		ary[i] = a;
	}
	for (int i = 0; i < 9; i++) {
		max_num = max(max_num, ary[i]);
	}
	for (int i = 0; i < 9; i++) {
		if (ary[i] == max_num) {
			cout << max_num << endl;
			cout << i+1;
			break;
		}
	}
}
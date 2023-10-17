#include<iostream>
using namespace std;

int main() {
	int ary[10] = { 0, };
	int count[42] = { 0, };
	int res = 0;
	for (int i = 0; i < 10; i++) {
		cin >> ary[i];
		ary[i] = ary[i] % 42;
	}
	for (int i = 0; i < 10; i++) {
		count[ary[i]]++;
	}
	for (int i = 0; i < 42; i++) {
		if (count[i] != 0) res++;
	}
	cout << res;
}
#include<iostream>
#include<vector>
using namespace std;

int main() {
	 long n, m;
	cin >> n >> m;
	vector<bool> v(1000001, true);
	v[0] = v[1] = false;
	for (long i = 2; i + i <= m; i++) {
		if (v[i]) {
			for (long j = i * i; j <= m; j += i) {
				v[j] = false;
			}
		}
	}
	for (long i = n; i <= m; i++) {
		if (v[i]) cout << i << " ";
	}
}
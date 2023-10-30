#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int m = 0;
	cin >> n >> m;
	int res = 0;
	int* ary = new int[n];
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		ary[i] = temp;
	}
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = ary[i] + ary[j] + ary[k];
				if(sum < m)
					res = max(res, sum);
				else if (sum == m) {
					cout << sum;
					exit(0);
				}
			}
		}
	}
	cout << res;
}
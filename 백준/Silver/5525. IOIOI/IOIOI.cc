#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

string str = "";
int n = 0;
int length = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> length >> str;
	int cnt = 0;
	for (int i = 0; i <= length - (2*n + 1); i++) {
		if (str[i] == 'I') {
			bool flag = false;
			for (int j = 0; j < 2 * n + 1; j++) {
				if (j % 2 == 0 && str[i+j] == 'I') {
					flag = true;
				}
				else if (j % 2 == 1 && str[i+j] == 'O') {
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag) {
				cnt++;
			}
		}
	}

	cout << cnt;


}
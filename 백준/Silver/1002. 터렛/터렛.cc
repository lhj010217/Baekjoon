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


int main() {
	int T = 0;
	
	cin >> T;
	while (T--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		long long dist = (x1 - x2)* (x1 - x2) + (y1 - y2)* (y1 - y2);
		
		// 동심원
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << "-1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else {
			// 2점에서 만나는 경우
			if (dist < (r1 + r2)*(r1+r2) && dist >(r1 - r2) * (r1 - r2)) {
				cout << "2\n";
			}
			// 1점에서 만나는 경우
			else if (dist == (r1 + r2) * (r1 + r2) || dist == (r1 - r2)*(r1-r2)) {
				cout << "1\n";
			}
			// 만나지 않는 경우
			else if (dist > (r1 + r2) * (r1 + r2) || dist < (r1 - r2)* (r1 - r2)) {
				cout << "0\n";
			}
		}
	}

}

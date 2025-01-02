#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int main() {
	int T = 0;
	cin >> T;

	while (T--) {
		int start_x, start_y, end_x, end_y;
		int n;
		int res = 0;
		cin >> start_x >> start_y >> end_x >> end_y;
		cin >> n;

		for (int i = 0; i < n;i++) {
			int Cx, Cy, r;
			cin >> Cx >> Cy >> r;
			int dist_with_start = (Cx - start_x) * (Cx - start_x) + (Cy - start_y) * (Cy - start_y);
			int dist_with_end = (Cx - end_x) * (Cx - end_x) + (Cy - end_y) * (Cy - end_y);

			if ((dist_with_start < r*r) ^ (dist_with_end < r*r)) {
				res++;
			}
		}
		
		cout << res << "\n";



	}
	return 0;
}
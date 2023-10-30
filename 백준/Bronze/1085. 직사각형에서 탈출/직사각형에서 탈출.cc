#include<iostream>
#include<cmath>
#include<tuple>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x1, x2, y1, y2;
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	x1 = x;
	x2 = w - x;
	y1 = y;
	y2 = h - y;

	int res = 1000;
	res = min(res, x1);
	res = min(res, x2);
	res = min(res, y1);
	res = min(res, y2);
	cout << res;
}
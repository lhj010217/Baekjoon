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

class vec {
private:
	int x;
	int y;
	int z = 0;

public:
	vec(int x, int y) {
		this->x = x;
		this->y = y;
	}
	vec(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	vec operator^(vec operand) {
		int res_x = this->y * operand.z - this->z * operand.y;
		int res_y = this->x * operand.z - this->z * operand.x;
		int res_z = this->x * operand.y - this->y * operand.x;
		
		vec res(res_x, res_y, res_z);
		return res;
	}
	int getZ() {
		return this->z;
	}
};

int main() {
	//p, q, r
	int x1, x2, x3, y1, y2, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	vec pq(x2 - x1, y2 - y1);
	vec qr(x3 - x2, y3 - y2);
	
	vec norm = pq ^ qr;

	if (norm.getZ() < 0) {
		cout << "-1";
	}
	else if(norm.getZ() == 0) {
		cout << "0";
	}
	else {
		cout << "1";
	}
}

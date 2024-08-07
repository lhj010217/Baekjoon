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
	int a, b, c;
	cin >> a >> b >> c;

	cout << a + b - c << "\n";
	cout << stoi(to_string(a).append(to_string(b)))-c;

}

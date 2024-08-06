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

vector<long long> v;

// 865가 감소하는 수라면
// 1) 865 * 10 + (끝자리인5 보다 작은 숫자들)도 감소하는 수
// 2) 1의 숫자의 * 10 + 끝자리보다 작은 숫자들도 감소하는 수
void getNumbers(long long num, long long last) {
	
	for (int i = last - 1; i >= 0; i--) {
		v.push_back(num * 10 + i);
		getNumbers(num * 10 + i, i);
	}
}


int main() {

	int N;
	
	cin >> N;

	for (int i = 0; i <= 9; i++) {
		v.push_back(i);
	}
	for (int i = 0; i <= 9; i++) {
		getNumbers(i, i);
	}
	
	sort(v.begin(), v.end());
	if (N > v.size() - 1) {
		cout << "-1";
	}
	else {
		cout << v[N];
	}


}

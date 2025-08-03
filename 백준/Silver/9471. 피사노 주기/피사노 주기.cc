#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

long long Pisano_Period(long long M) {
	long long prev = 1;
	long long cur = 1;
	long long temp = 0;

	for (long long i = 0; i < M * M; i++) {
		temp = (prev + cur) % M; 
		prev = cur;
		cur = temp;
		
		if (prev == 1 && cur == 1) {
			return i + 1;
		}
	}
	return 0;
}


int main() {
	int test_case = 0;
	cin >> test_case;

	while (test_case--) {
		int test_case_number;
		long long M = 0;
		cin >> test_case_number >> M;

		
		cout << test_case_number << " " << Pisano_Period(M)<<"\n";

	}

	return 0;

}
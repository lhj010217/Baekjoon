#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;


int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}
	
	int N;
	vector <long long> plus;
	vector<long long> minus;
	vector<long long> zero;
	long long sum = 0;
	cin >> N;

	for (int i = 0; i < N;i++) {
		long long num = 0;
		cin >> num;
		if (num > 0) {
			plus.push_back(num);
		}
		else if (num == 0) {
			zero.push_back(num);
		}
		else if (num < 0) {
			minus.push_back(num);
		}
	}
	
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	for (int i = plus.size() - 1; i >= 0; i -= 2) {
		if (i == 0) {
			sum += plus[i];
			break;
		}
		if (plus[i] == 1 || plus[i-1] == 1) {
			sum += plus[i] + plus[i - 1];
		}
		else {
			sum += plus[i] * plus[i - 1];
		}
	}
	
	for (int i = 0; i < minus.size(); i += 2) {
		if (i == minus.size()-1) {
			if (zero.size() > 0) {
				sum += 0;
				break;
			}
			else {
				sum += minus[i];
				break;
			}
		}
		sum += minus[i] * minus[i + 1];
	}

	cout << sum;

	return 0;
}
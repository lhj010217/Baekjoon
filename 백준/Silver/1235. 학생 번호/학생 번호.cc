#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	int N = 0;
	cin >> N;

	vector<string> student(N);
	for (int i = 0; i < N; i++) {
		cin >> student[i];
	}
	
	int number_len = student[0].length();
	int str_len = 0;
	int result = 0;
	
	for (int i = number_len - 1; i >= 0; i--) {
		set<string> s;
		vector<string> substrs(N);
		for (int j = 0; j < N; j++) {
			string sub = student[j].substr(i);
			s.insert(sub);
		}
		if (s.size() == N) {
			result = number_len - i;
			break;
		}
		str_len++;
	}

	cout << result;
	return 0;
}
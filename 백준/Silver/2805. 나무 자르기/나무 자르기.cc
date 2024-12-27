#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

long long getSum(vector<long long> t, long long t_num, long long h) {
	long long sum = 0;
	for (int i = 0; i < t_num; i++) {
		sum += max((long long)0, t[i] - h);
	}
	return sum;
}


int main() {
	long long tree_num = 0;
	long long tree_need = 0;
	long long max_height = -1;
	cin >> tree_num >> tree_need;

	vector<long long> trees(tree_num, 0);
	for (int i = 0; i < tree_num; i++) {
		cin >> trees[i];
		max_height = max(max_height, trees[i]);
	}

	long long left = 0;
	long long right = max_height;
	long long cut_line = max_height / 2;
	while (true) {
		if (getSum(trees, tree_num, cut_line) >= tree_need) {
			left = cut_line;
			cut_line = (cut_line + right) / 2;
			if (cut_line == left || cut_line == right) {
				break;
			}
		}
		else {
			right = cut_line;
			cut_line = (cut_line - left) / 2;
		}
	}

	cout << cut_line;
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;

struct line{
	long long start;
	long long end;
	line() :start(0), end(0) {}
	line(long long s, long long e) : start(s), end(e) {}
};

bool cmp(const line& a, const line& b) {
	if (a.start == b.start) return a.end < b.end; 
	return a.start < b.start; 
}

int main() {
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}

	long long N;
	long long cur_time = 0;
	long long classroom_number = 0;
	vector<line> lines;
	vector<line> result;
	long long total_length = 0;

	cin >> N;
	lines.resize(N);


	for (long long i = 0; i < N;i++) {
		cin >> lines[i].start >> lines[i].end;
	}

	sort(lines.begin(), lines.end(), cmp);

	result.push_back(lines[0]);

	for (long long i = 1;i < N;i++) {
		if (lines[i].end < result.back().end) {
			continue;
		}
		else if (lines[i].start <= result.back().end) {
			result.back().end = lines[i].end;
		}
		else {
			result.push_back(lines[i]);
		}
	}

	for (auto& l : result) {
		total_length += (l.end - l.start);
	}

	cout << total_length;
	return 0;
}
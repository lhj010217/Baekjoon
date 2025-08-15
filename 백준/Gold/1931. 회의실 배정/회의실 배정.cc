#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;

struct meeting_time{
	int start;
	int end;
	meeting_time() :start(0), end(0) {}
	meeting_time(int s, int e): start(s), end(e) {}
};


bool cmp(const meeting_time& a, const meeting_time& b) {
	if (a.end == b.end) return a.start < b.start; 
	return a.end < b.end; 
}

int main() {
	int N;
	int cur_time = 0;
	int meeting_number = 0;
	vector<meeting_time> timetable;
	
	cin >> N;
	timetable.resize(N);


	for (int i = 0; i < N;i++) {
		cin >> timetable[i].start >> timetable[i].end;
	}

	sort(timetable.begin(), timetable.end(), cmp);

	for (int i = 0;i < N;i++) {
		if (cur_time > timetable[i].start) {
			continue;
		}

		cur_time = timetable[i].end;
		meeting_number++;
	}

	cout << meeting_number;
	return 0;
}
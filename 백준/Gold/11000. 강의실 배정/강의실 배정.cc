#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>
using namespace std;

struct class_time{
	int start;
	int end;
	class_time() :start(0), end(0) {}
	class_time(int s, int e): start(s), end(e) {}
};

bool cmp(const class_time& a, const class_time& b) {
	if (a.start == b.start) return a.end < b.end; 
	return a.start < b.start; 
}

int main() {
	int N;
	int cur_time = 0;
	int classroom_number = 0;
	vector<class_time> timetable;
	priority_queue<int, vector<int>, greater<int>> classroom;

	cin >> N;
	timetable.resize(N);


	for (int i = 0; i < N;i++) {
		cin >> timetable[i].start >> timetable[i].end;
	}

	sort(timetable.begin(), timetable.end(), cmp);

	classroom.push(timetable[0].end);
	
	for (int i = 1; i < N;i++) {
		classroom.push(timetable[i].end);
		if (classroom.top() <= timetable[i].start) {
			classroom.pop();
		}
	}
	cout << classroom.size();


	return 0;
}
#include<iostream>
#include<queue>
using namespace std;

int main() {
	int num = 0, iter = 0;
	cin >> num >> iter;
	queue<int> q;
	for (int i = 0; i < num; i++) {
		q.push(i + 1);
	}
	cout << "<";
	while (q.size() > 0) {
		if (q.size() > 1) {
			for (int i = 0; i < iter - 1; i++) {
				q.push(q.front());
				q.pop();
			}
			cout << q.front() << ", ";
			q.pop();
		}
		else {
			cout << q.front() << ">";
			q.pop();
		}
	}
}

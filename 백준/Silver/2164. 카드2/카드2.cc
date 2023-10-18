#include<iostream>
#include<queue>
using namespace std;

int main() {
	int size;
	queue<int> q;
	cin >> size;
	for (int i = 1; i <= size; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.back();
}
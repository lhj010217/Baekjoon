#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;

deque<int> init(string e) {
	deque<int> temp;
	string num = "";
	if (e.length() == 2) {
		return temp;
	}
	for (int i = 1; i < e.length(); i++) { // ignore []
		if (e[i] == ',' || e[i] == ']') {
			temp.push_back(stoi(num));
			num = "";
		}
		else {
			num += e[i];
		}
	}
	
	return temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 0;
	cin >> t;
	while (t--) {
		deque<int> dq;
		string ope = "";
		int size = 0;
		string element = "";
		bool reverse = false;
		bool error_flag = false;
		cin >> ope >> size >> element;
		dq = init(element);

		for (int i = 0; i < ope.length(); i++) {
			if (ope[i] == 'R') {
				reverse == true ? reverse = false : reverse = true;
			}
			if (ope[i] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					error_flag = true;
					break;
				}
				else {
					if (reverse == false) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
			}
		}
		if (!dq.empty()) {
			cout << "[";
			if (reverse == true) {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0) {
						cout << ",";
					}
				}
			}
			else {
				for (int i = 0; i < dq.size();i++) {
					cout << dq[i];
					if (i != dq.size()-1) {
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
		else if(error_flag == false){
			cout << "[]\n";
		}
	}
}
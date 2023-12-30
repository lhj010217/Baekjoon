#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;


string Problem = "";
int ProblemLength = 0;
vector<string> v;
int Result = 0;


void Parsing() {
	int RecentOperatorIndex = -1;
	int NumberLength = 0;

	for (int i = 0; i < ProblemLength; i++) {
		NumberLength++;
		if (Problem[i] == '+' || Problem[i] == '-') {
			v.push_back(Problem.substr(RecentOperatorIndex + 1, NumberLength - 1));
			v.push_back(Problem.substr(i, 1));
			RecentOperatorIndex = i;
			NumberLength = 0;
		}
	}
	v.push_back(Problem.substr(RecentOperatorIndex + 1, NumberLength));
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string OperatorFlag = "+";
	cin >> Problem;
	ProblemLength = Problem.length();
	Parsing();

	Result += stoi(v[0]);
	
	for (int i = 1; i < v.size(); i += 2) {
		if (v[i] == "+" && OperatorFlag == "+") {
			OperatorFlag = "+";
		}
		if (v[i] == "-") {
			OperatorFlag = "-";
		}
		if (OperatorFlag == "+") {
			Result += stoi(v[i + 1]);
		}
		else {
			Result -= stoi(v[i + 1]);
		}

	}
	cout << Result;



}

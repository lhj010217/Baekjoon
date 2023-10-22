#include<iostream>
#include<vector>
#include<tuple>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(pair<int, string>a, pair<int, string>b) {
	if (get<0>(a) < get<0>(b)) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num = 0;
	vector<pair<int, string>> member;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int age = 0;
		string name;
		cin >> age >> name;
		member.push_back({age,name});
	}
	stable_sort(member.begin(), member.end(), cmp);

	for (int i = 0; i < member.size(); i++) {
		cout << get<0>(member[i]) << " " << get<1>(member[i]) << "\n";
	}
}
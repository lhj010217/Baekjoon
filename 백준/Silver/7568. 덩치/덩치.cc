#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct st {
	int w;
	int h;
	int r;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N = 0;
	vector<st> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int w, h;
		cin >> w >> h;
		st* s = new st;
		s->w = w;
		s->h = h;
		s->r = 1;
		v.push_back(*s);
	}
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[i].w < v[j].w && v[i].h < v[j].h) {
				v[i].r++;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].r << " ";
	}
}
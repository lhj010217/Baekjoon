#include<iostream>
#include<stdio.h>
#include<queue>
#include<deque>
#include<cmath>
#include<tuple>
#include<stack>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

string start_b[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
string start_w[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

int getRes(string b[], int x, int y) {
	int res_b = 0;
	int res_w = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (start_b[i][j] != b[i + x][j + y]) res_b++;
			if (start_w[i][j] != b[i + x][j + y]) res_w++;
		}
	}

	return min(res_b, res_w);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string board[50];
	int n = 0;
	int m = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int res = 32;
	for (int i = 0; i < n - 8 + 1; i++) {
		for (int j = 0; j < m - 8 + 1; j++) {
			res = min(res, getRes(board, i, j));
		}
	}
	cout << res;
}
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;
int main() {
	int N = 0;
	cin >> N;
	vector<int> A(N + 1, 0);
	vector<int> D(N + 1, 0);
	vector<int> Ai(N + 1, INT_MAX);
	vector<int> Di(N + 1, INT_MAX);
	int max_len = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		int cur_num = A[i];
		if (cur_num < Ai[max_len]) {
			max_len++;
			Ai[max_len] = cur_num;
			Di[max_len] = max_len;
			D[i] = max_len;
		}
		else {
			for (int Ai_iter = 0; Ai_iter <= max_len; Ai_iter++) {
				if (cur_num >= Ai[Ai_iter]) {
					Ai[Ai_iter] = cur_num;
					D[i] = Ai_iter;
					break;
				}
			}
		}
	}

	cout << max_len;
	return 0;
}
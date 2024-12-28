#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>

using namespace std;



int main() {
	int N, M;
	int cur_sideLength = 1;
	int max_sideLength= -1;
	int cube_size = 0;
	cin >> N >> M;

	vector<vector<int>> oblong(N, vector<int>(M));
	for (int i = 0; i < N;i++) {
		string s = "";
		cin >> s;
		for (int j = 0;j < M;j++) {
			oblong[i][j] = s[j] - '0';
		}
	}

	while (cur_sideLength <= min(N, M)) {
		for (int i = 0; i <= N - cur_sideLength; i++) {
			for (int j = 0; j <= M - cur_sideLength; j++) {
				if (oblong[i][j] == oblong[i+(cur_sideLength-1)][j] 
					&& oblong[i + (cur_sideLength - 1)][j] == oblong[i + (cur_sideLength - 1)][j + (cur_sideLength - 1)] 
					&& oblong[i + (cur_sideLength - 1)][j + (cur_sideLength - 1)] == oblong[i][j + (cur_sideLength - 1)]) {
					max_sideLength = cur_sideLength;
				}
			}
		}
		cur_sideLength++;
	}

	cube_size = max_sideLength * max_sideLength;

	cout << cube_size;


}
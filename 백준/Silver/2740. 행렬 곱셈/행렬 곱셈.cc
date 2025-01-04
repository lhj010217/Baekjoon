#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> A(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	int K;
	cin >> M >> K;
	vector<vector<int>> B(M, vector<int>(K));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int C = 0;
			for (int k = 0; k < M; k++) {
				C += A[i][k] * B[k][j];
			}
			cout << C << " ";
		}
		cout << "\n";
	}




	return 0;
}
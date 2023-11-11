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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int,int>> A(N + 1);

    for (int i = 1; i <= N;i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    
    sort(A.begin(), A.end());
    
    int res = -1;
    for (int i = 1; i <= N; i++) {
        res = max(res, A[i].second - i);
    }
    cout << res + 1;
}
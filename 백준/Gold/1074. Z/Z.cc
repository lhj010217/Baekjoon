#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;


int solve(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1 << (n - 1); // 2^(n-1)
    int quad_size = half * half;

    if (r < half && c < half) {
        return solve(n - 1, r, c);
    }
    else if (r < half && c >= half) {
        return quad_size + solve(n - 1, r, c - half);
    }
    else if (r >= half && c < half) {
        return 2 * quad_size + solve(n - 1, r - half, c);
    }
    else {
        return 3 * quad_size + solve(n - 1, r - half, c - half);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << solve(N, r, c);
}
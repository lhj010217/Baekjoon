#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N = 0, M = 0;
int ary[9];
bool isUsed[9];

void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << ary[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (isUsed[i] == false) {
            ary[k] = i;
            isUsed[i] = true;
            func(k + 1);
            isUsed[i] = false;
        }
    }
    return;
}


int main() {
    
    cin >> N >> M;
    func(0);

    return 0;
}

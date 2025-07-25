#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<tuple>

using namespace std;


int N = 0, M = 0;
vector<int> numbers;
vector<bool> visited;
vector<int> sequence;


void backtrace(int depth) {
    if (depth == M) {
        for (auto& num : sequence)
            cout << num << " ";
        cout << "\n";
        return;
    }
    int last_number = -1;

    for (int i = 1; i <= N; i++) {
        if (visited[i] == false && numbers[i] != last_number) {       
                visited[i] = true;
                sequence.push_back(numbers[i]);
                last_number = numbers[i];
                backtrace(depth + 1);
                sequence.pop_back();
                visited[i] = false;        }
    }
    return;
}


int main() {

    cin >> N >> M;
    numbers.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin()+1, numbers.end());
    backtrace(0);
}
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Pos {
    int x, y, isBreak;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N + 1, vector<int>(M + 1));
    vector<vector<vector<bool>>> visit(N + 1, vector<vector<bool>>(M + 1, vector<bool>(2, false)));
    for (int i = 1; i <= N; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= M; j++) {
            map[i][j] = row[j - 1] - '0';
        }
    }

    queue<pair<Pos, int>> q;
    q.push({ {1, 1, 0}, 1 }); 
    visit[1][1][0] = true;

    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    while (!q.empty()) {
        Pos cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur.x == M && cur.y == N) {
            cout << dist;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = cur.x + dx[i];
            int next_y = cur.y + dy[i];
            int breakWall = cur.isBreak;

            if (next_x < 1 || next_y < 1 || next_x > M || next_y > N) continue;

            if (map[next_y][next_x] == 0 && !visit[next_y][next_x][breakWall]) {
                visit[next_y][next_x][breakWall] = true;
                q.push({ {next_x, next_y, breakWall}, dist + 1 });
            }
            if (map[next_y][next_x] == 1 && breakWall == 0 && !visit[next_y][next_x][1]) {
                visit[next_y][next_x][1] = true;
                q.push({ {next_x, next_y, 1}, dist + 1 });
            }
        }
    }

    cout << -1;
    return 0;
}

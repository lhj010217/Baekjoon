#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int y, x;
    Point(int y = 0, int x = 0) : y(y), x(x) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int size = N + 1;

    vector<vector<vector<Point>>> light(size, vector<vector<Point>>(size));
    vector<vector<bool>> light_on(size, vector<bool>(size, false));
    vector<vector<bool>> visit(size, vector<bool>(size, false));

    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        light[y][x].push_back(Point(b, a));
    }

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    queue<Point> q;
    q.push(Point(1, 1));
    visit[1][1] = true;
    light_on[1][1] = true;

    bool light_changed = true;
    while (light_changed) {
        light_changed = false;
        queue<Point> bfs;
        bfs.push(Point(1, 1));

        vector<vector<bool>> temp_visit(size, vector<bool>(size, false));
        temp_visit[1][1] = true;

        while (!bfs.empty()) {
            Point cur = bfs.front();
            bfs.pop();

            for (auto& next : light[cur.y][cur.x]) {
                if (!light_on[next.y][next.x]) {
                    light_on[next.y][next.x] = true;
                    light_changed = true; 
                }
            }

            for (int i = 0; i < 4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
                    if (light_on[ny][nx] && !temp_visit[ny][nx]) {
                        temp_visit[ny][nx] = true;
                        bfs.push(Point(ny, nx));
                        visit[ny][nx] = true;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (light_on[i][j]) result++;

    cout << result << '\n';
    return 0;
}

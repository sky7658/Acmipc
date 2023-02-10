#include <iostream>
#include <queue>
using namespace std;

int n, m, answer;
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string map[50];

queue<pair<int, int>> q;

int bfs() {
    bool visit[50][50] = {
        false,
    };
    int count = 0;
    int size = 1;
    visit[q.front().first][q.front().second] = true;

    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int tx = q.front().second + d[i][1];
            int ty = q.front().first + d[i][0];

            if (tx >= 0 && ty >= 0 && tx < m && ty < n && map[ty][tx] != 'W' &&
                !visit[ty][tx]) {
                visit[ty][tx] = true;
                q.push({ty, tx});
            }
        }
        q.pop();
        if (--size == 0) {
            count++;
            size = q.size();
        }
    }

    return count - 1;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> map[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'W') continue;

            q.push({i, j});
            answer = max(answer, bfs());
        }
    }

    cout << answer;
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int map[100][100];
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool EscapeRange(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return true;
    return false;
}

bool isSink(int h) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (map[i][j] > h) return true;
    }
    return false;
}

int bfs(int h) {
    bool visit[100][100] = {
        false,
    };
    int count = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (visit[y][x] || map[y][x] <= h) {
                visit[y][x] = true;
                continue;
            }
            queue<pair<int, int>> q;
            q.push({y, x});
            visit[y][x] = true;

            while (!q.empty()) {
                for (int i = 0; i < 4; i++) {
                    int dx = q.front().second + d[i][1];
                    int dy = q.front().first + d[i][0];

                    if (EscapeRange(dx, dy)) continue;
                    if (visit[dy][dx] || map[dy][dx] <= h) continue;

                    q.push({dy, dx});
                    visit[dy][dx] = true;
                }
                q.pop();
            }
            count++;
        }
    }

    return count;
}

int main(void) {
    cin >> n;
    int h = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> map[i][j];
    }

    while (isSink(h)) {
        answer = max(answer, bfs(h));
        h++;
    }

    cout << answer;
    return 0;
}
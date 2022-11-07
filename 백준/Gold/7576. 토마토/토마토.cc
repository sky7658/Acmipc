#include <iostream>
#include <queue>
using namespace std;

int tomato[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int m, n, ans = 0;

void bfs() {
    int size = q.size();

    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = q.front().first + dx[i];
            int ny = q.front().second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && tomato[ny][nx] == 0) {
                q.push({nx, ny});
                tomato[ny][nx] = 1;
            }
        }
        q.pop();
        if (--size == 0) {
            ans++;
            size = q.size();
        }
    }
}

int main(void) {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                q.push({j, i});
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans - 1;
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int m, n, k;

void bfs(int x, int y, int f[][50], bool v[][50]) {
    q.push({x, y});
    v[y][x] = true;

    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = q.front().first + dx[i];
            int ny = q.front().second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && v[ny][nx] == false &&
                f[ny][nx] == 1) {
                q.push({nx, ny});
                v[ny][nx] = true;
            }
        }
        q.pop();
    }
}

int main(void) {
    int t, x, y, number = 0;
    cin >> t;
    while (t-- > 0) {
        bool visit[50][50] = {
            false,
        };
        int field[50][50] = {
            0,
        };
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            field[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == 1 && visit[i][j] == false) {
                    bfs(j, i, field, visit);
                    number++;
                }
            }
        }

        cout << number << '\n';
        number = 0;
    }
    return 0;
}
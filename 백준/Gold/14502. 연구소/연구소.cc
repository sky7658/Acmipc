#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m, safeArea;
int map[8][8];
int check[8][8];
int d[4][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

queue<pair<int, int>> q;

int bfs() {
    int count = 0;
    bool visit[8][8] = {false};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] == 2 && !visit[i][j]) {
                q.push({i, j});

                while (!q.empty()) {
                    int tx = q.front().second;
                    int ty = q.front().first;

                    for (int k = 0; k < 4; k++) {
                        int px = tx + d[k][1];
                        int py = ty + d[k][0];

                        if (px >= 0 && py >= 0 && px < m && py < n &&
                            check[py][px] == 0) {
                            q.push({py, px});
                            check[py][px] = 2;
                            visit[py][px] = true;
                        }
                    }

                    q.pop();
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (check[i][j] == 0) count++;
    }

    return count;
}

void dfs(int wall) {
    if (wall == 3) {
        copy(&map[0][0], &map[0][0] + (8 * 8), &check[0][0]);
        safeArea = max(safeArea, bfs());
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                dfs(wall + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0);

    cout << safeArea;
    return 0;
}
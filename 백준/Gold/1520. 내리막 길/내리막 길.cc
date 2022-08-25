#include <iostream>
using namespace std;

int dp[500][500];
int road[500][500];
int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;

int dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        return 1;
    }
    if (dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][1];
        int ty = y + dir[i][0];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
            if (road[ty][tx] < road[y][x]) dp[y][x] += dfs(tx, ty);
        }
    }
    return dp[y][x];
}

int main(void) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> road[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
    return 0;
}
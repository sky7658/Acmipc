#include <cmath>
#include <iostream>
using namespace std;

int n, m;
int paper[501][501];
bool visit[501][501];
int d[4][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int answer;

void dfs(int depth, int score, int x, int y) {
    if (depth == 4) {
        answer = max(answer, score);
        return;
    }

    if (x < 0 || y < 0 || x >= m || y >= n) return;

    for (int i = 0; i < 4; i++) {
        int tx = x + d[i][1];
        int ty = y + d[i][0];

        if (visit[ty][tx]) continue;

        visit[y][x] = true;
        dfs(depth + 1, score + paper[ty][tx], tx, ty);
        visit[y][x] = false;
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> paper[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(1, paper[i][j], j, i);

            for (int k = 0; k < 4; k++) {
                int score = paper[i][j];
                int l = 0;
                while (l < 3) {
                    int px = j + d[(l + k) % 4][1];
                    int py = i + d[(l + k) % 4][0];
                    if (px < 0 || py < 0 || px >= m || py >= n) break;
                    score += paper[py][px];
                    l++;
                }
                answer = max(answer, score);
            }
        }
    }

    cout << answer;
    return 0;
}
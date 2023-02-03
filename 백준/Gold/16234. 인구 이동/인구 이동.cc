#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

int n, l, r, count;
int group_n, group_p, group_count;
int country[50][50];
bool visit[50][50];
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

queue<pair<int, int>> q;

void bfs() {
    queue<pair<int, int>> q1;
    q1.push(q.front());

    while (!q.empty()) {
        int tx = q.front().second;
        int ty = q.front().first;

        group_p += country[ty][tx];
        group_n++;

        for (int i = 0; i < 4; i++) {
            int diffrence =
                abs(country[ty][tx] - country[ty + d[i][0]][tx + d[i][1]]);
            if (tx + d[i][1] >= 0 && ty + d[i][0] >= 0 && tx + d[i][1] < n &&
                ty + d[i][0] < n && diffrence >= l && diffrence <= r &&
                !visit[ty + d[i][0]][tx + d[i][1]]) {
                q.push({ty + d[i][0], tx + d[i][1]});
                q1.push({ty + d[i][0], tx + d[i][1]});
                visit[ty + d[i][0]][tx + d[i][1]] = true;
            }
        }
        q.pop();
    }

    if (group_n > 1) {
        group_count++;
        while (!q1.empty()) {
            country[q1.front().first][q1.front().second] = group_p / group_n;
            q1.pop();
        }
    }

    group_p = 0;
    group_n = 0;
}

int main(void) {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> country[i][j];
    }

    while (true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j]) continue;
                visit[i][j] = true;
                q.push({i, j});
                bfs();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) visit[i][j] = false;
        }

        if (group_count > 0) {
            count++;
            group_count = 0;
        } else
            break;
    }
    cout << count;
    return 0;
}
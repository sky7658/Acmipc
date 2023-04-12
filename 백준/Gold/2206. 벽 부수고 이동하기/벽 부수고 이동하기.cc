#include <iostream>
#include <queue>

using namespace std;

int n, m;
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string map[1000];
int visit[1000][1000][2];
queue<pair<pair<int, int>, int>> q;

int bfs() {
    visit[0][0][0] = 1, visit[0][0][1] = 1;

    q.push({{0, 0}, 0});

    while (!q.empty()) {
        int x = q.front().first.second;
        int y = q.front().first.first;
        int broke = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int px = x + d[i][1];
            int py = y + d[i][0];

            if (px < 0 || py < 0 || px >= m || py >= n) continue;
            if (visit[py][px][broke] > 0 || (broke && map[py][px] == '1'))
                continue;

            if (map[py][px] == '1') {
                q.push({{py, px}, 1});
                visit[py][px][1] = visit[y][x][broke] + 1;
            } else {
                q.push({{py, px}, broke});
                visit[py][px][broke] = visit[y][x][broke] + 1;
            }
        }

        if (x == m - 1 && y == n - 1) {
            return visit[y][x][broke];
        }
    }

    return -1;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> map[i];

    cout << bfs();
    return 0;
}
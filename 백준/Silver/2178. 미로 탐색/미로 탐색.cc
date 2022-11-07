#include <iostream>
#include <queue>
using namespace std;

string maze[100];
queue<pair<int, int>> q;
int visit[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

void bfs(int x, int y) {
    q.push({x, y});
    visit[y][x] = 1;
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = q.front().first + dx[i];
            int ny = q.front().second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && maze[ny][nx] == '1' &&
                visit[ny][nx] == 0) {
                q.push({nx, ny});
                visit[ny][nx] = visit[q.front().second][q.front().first] + 1;
            }
        }
        q.pop();
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    bfs(0, 0);
    cout << visit[n - 1][m - 1];
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int iceberg[300][300];
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool EscapeRange(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return true;
    return false;
}

void CopyArray(int (*arr)[300], int (*copyArr)[300]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = copyArr[i][j];
        }
    }
}

void PassTime() {
    int copy_iceberg[300][300];
    CopyArray(copy_iceberg, iceberg);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!iceberg[i][j]) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int x = j + d[k][1];
                int y = i + d[k][0];

                if (EscapeRange(x, y)) continue;
                if (!iceberg[y][x]) cnt++;
            }
            copy_iceberg[i][j] -= cnt;
            if (copy_iceberg[i][j] < 0) copy_iceberg[i][j] = 0;
        }
    }

    CopyArray(iceberg, copy_iceberg);
}

int IcebergCount() {
    bool visit[300][300] = {
        false,
    };
    queue<pair<int, int>> q;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!iceberg[i][j] || visit[i][j]) {
                visit[i][j] = true;
                continue;
            }
            q.push({i, j});
            visit[i][j] = true;

            while (!q.empty()) {
                int x = q.front().second;
                int y = q.front().first;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int dx = x + d[k][1];
                    int dy = y + d[k][0];

                    if (EscapeRange(dx, dy)) continue;
                    if (visit[dy][dx] || !iceberg[dy][dx]) continue;

                    q.push({dy, dx});
                    visit[dy][dx] = true;
                }
            }
            count++;
        }
    }

    return count;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> iceberg[i][j];
    }

    int time = 0;
    while (true) {
        int cnt = IcebergCount();
        if (cnt > 1) break;
        if (cnt == 0) {
            cout << 0;
            return 0;
        }
        PassTime();
        time++;
    }
    cout << time;
    return 0;
}
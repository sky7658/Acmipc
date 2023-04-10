#include <iostream>
#include <vector>
using namespace std;

int r, c, t;
int map[50][50];
int d[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
vector<pair<int, int>> pos;

bool EscapeRange(int x, int y) {
    if (x < 0 || y < 0 || x >= c || y >= r) return true;
    return false;
}

void Spread() {
    int copy_map[50][50];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) copy_map[i][j] = map[i][j];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int count = 0;
            if (map[i][j] < 5) continue;
            for (int k = 0; k < 4; k++) {
                int x = j + d[k][1];
                int y = i + d[k][0];

                if (EscapeRange(x, y)) continue;
                if (map[y][x] == -1) continue;
                count++;
                copy_map[y][x] += map[i][j] / 5;
            }
            copy_map[i][j] -= (map[i][j] / 5) * count;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) map[i][j] = copy_map[i][j];
    }
}

void Circleing(bool clockwise, int curX, int curY) {
    int arrow = 0;
    int value = 0;

    int add;
    if (clockwise)
        add = -1;
    else
        add = 1;

    while (true) {
        int nextX = curX + d[arrow][1];
        int nextY = curY + d[arrow][0];

        if (EscapeRange(nextX, nextY)) {
            arrow += add;
            arrow = (arrow + 4) % 4;
            nextX = curX + d[arrow][1];
            nextY = curY + d[arrow][0];
        }

        int swap;

        if (map[nextY][nextX] == -1) break;

        swap = map[nextY][nextX];
        map[nextY][nextX] = value;
        value = swap;

        curX = nextX;
        curY = nextY;
    }
}

int main() {
    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1) pos.push_back({i, j});
        }
    }

    while (t-- > 0) {
        Spread();
        Circleing(false, pos[0].second, pos[0].first);
        Circleing(true, pos[1].second, pos[1].first);
    }

    int answer = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == -1) continue;
            answer += map[i][j];
        }
    }

    cout << answer;
    return 0;
}
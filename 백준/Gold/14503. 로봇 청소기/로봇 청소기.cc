#include <iostream>
using namespace std;

int n, m, r, c, d, count = 1;
int place[51][51];
bool clear[51][51];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(void) {
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> place[i][j];
    }

    int l = 0;
    clear[r][c] = true;

    while (true) {
        --d += 4;
        d %= 4;
        int tx = c + direction[d][1];
        int ty = r + direction[d][0];
        if (tx >= 0 && ty >= 0 && tx < m && ty < n && !clear[ty][tx] &&
            !place[ty][tx]) {
            r += direction[d][0];
            c += direction[d][1];

            clear[r][c] = true;
            count++;
            l = 0;
            continue;
        }
        l++;
        if (l == 4) {
            int px = c + direction[(d + 2) % 4][1];
            int py = r + direction[(d + 2) % 4][0];
            if (px < 0 || py < 0 || px >= m || py >= n || place[py][px]) break;

            r += direction[(d + 2) % 4][0];
            c += direction[(d + 2) % 4][1];

            l = 0;
        }
    }

    cout << count;
    return 0;
}
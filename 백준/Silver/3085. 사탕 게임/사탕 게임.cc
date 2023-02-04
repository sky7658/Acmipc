#include <iostream>
using namespace std;

int n, max_eat, c1, c2;
string board[50];
int d[4][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void check(int arrow, int count, int x, int y, char alpha, bool sw) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        if (sw)
            c1 += count;
        else
            c2 += count;
        return;
    }
    if (alpha != board[y][x]) {
        if (sw)
            c1 += count;
        else
            c2 += count;
        return;
    }
    check(arrow, count + 1, x + d[arrow][1], y + d[arrow][0], alpha, sw);
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int tx = j + d[k][1];
                int ty = i + d[k][0];
                char swap;

                if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                    swap = board[i][j];
                    board[i][j] = board[ty][tx];
                    board[ty][tx] = swap;

                    for (int h = 0; h < 2; h++) {
                        check(h, 0, tx, ty, board[ty][tx], h);
                        check(h + 2, 0, tx, ty, board[ty][tx], h);
                    }

                    max_eat = max(max_eat, max(c1 - 1, c2 - 1));
                    board[ty][tx] = board[i][j];
                    board[i][j] = swap;

                    c1 = c2 = 0;
                }
            }
        }
    }

    cout << max_eat;
    return 0;
}
#include <cmath>
#include <iostream>
using namespace std;

// column x, row y
int n, l, answer;
int map[100][100];

int Column(int x) {
    bool runway[100] = {
        false,
    };

    for (int i = 0; i < n - 1; i++) {
        if (map[i][x] != map[i + 1][x]) {
            if (abs(map[i][x] - map[i + 1][x]) > 1) return false;
            int a;
            if (map[i][x] > map[i + 1][x]) {
                a = map[i + 1][x];
                for (int j = 1; j <= l; j++) {
                    if (i + j >= n || runway[i + j] || map[i + j][x] != a)
                        return false;
                    runway[i + j] = true;
                }
                i += l - 1;
            } else {
                a = map[i][x];
                for (int j = 0; j < l; j++) {
                    if (i - j >= n || runway[i - j] || map[i - j][x] != a)
                        return false;
                    runway[i - j] = true;
                }
            }
        }
    }

    return true;
}

int Row(int y) {
    bool runway[100] = {
        false,
    };

    for (int i = 0; i < n - 1; i++) {
        if (map[y][i] != map[y][i + 1]) {
            if (abs(map[y][i] - map[y][i + 1]) > 1) return false;
            int a;
            if (map[y][i] > map[y][i + 1]) {
                a = map[y][i + 1];
                for (int j = 1; j <= l; j++) {
                    if (i + j >= n || runway[i + j] || map[y][i + j] != a)
                        return false;
                    runway[i + j] = true;
                }
                i += l - 1;
            } else {
                a = map[y][i];
                for (int j = 0; j < l; j++) {
                    if (i - j >= n || runway[i - j] || map[y][i - j] != a)
                        return false;
                    runway[i - j] = true;
                }
            }
        }
    }

    return true;
}

int main(void) {
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> map[i][j];

    for (int i = 0; i < n; i++) {
        if (Column(i)) answer++;
        if (Row(i)) answer++;
    }

    cout << answer;
    return 0;
}
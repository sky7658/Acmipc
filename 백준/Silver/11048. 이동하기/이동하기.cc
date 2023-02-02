#include <iostream>
using namespace std;

int n, m, max_n;
int map[1001][1001];
int ans[1001][1001];
int d[3][2] = {{1, 0}, {0, 1}, {1, 1}};

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> map[i][j];
    }

    ans[0][0] = map[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                int tx = j + d[k][1];
                int ty = i + d[k][0];
                ans[ty][tx] = max(ans[ty][tx], ans[i][j] + map[ty][tx]);
            }
        }
    }
    cout << ans[n - 1][m - 1];
    return 0;
}
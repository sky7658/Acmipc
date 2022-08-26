#include <iostream>
using namespace std;

int dp[501][501];
int arr[501][2];

int mul(int n, int m, int k) { return n * m * k; }

int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i = 1; i < n; i++) {
        for (int tx = 1; tx + i <= n; tx++) {
            int ty = tx + i;
            dp[tx][ty] = 2147483647;

            for (int m = tx; m < ty; m++) {
                dp[tx][ty] =
                    min(dp[tx][ty], dp[tx][m] + dp[m + 1][ty] +
                                        mul(arr[tx][0], arr[m][1], arr[ty][1]));
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
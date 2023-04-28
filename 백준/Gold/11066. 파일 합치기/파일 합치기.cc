#include <iostream>
#include <limits.h>
using namespace std;

int file[501];
int sum[501];
int dp[501][501];

int main(void) {
    int t, k;
    cin >> t;
    while (t-- > 0) {
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> file[i];
            sum[i] = sum[i - 1] + file[i];
        }
        for (int d = 1; d < k; d++) {
            for (int tx = 1; tx + d <= k; tx++) {
                int ty = tx + d;
                dp[tx][ty] = INT_MAX;
                for (int mid = tx; mid < ty; mid++) {
                    dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] +
                                                     sum[ty] - sum[tx - 1]);
                }
            }
        }
        cout << dp[1][k] << '\n';
    }
    return 0;
}
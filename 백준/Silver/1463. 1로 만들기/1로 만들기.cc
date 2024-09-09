#include <iostream>
using namespace std;

int dp[1000001];

int main(void) {
    int n;
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i <= 3) {
            dp[i] = 1;
        } else {
            if (!(i % 3) && !(i % 2)) {
                dp[i] = min(1 + dp[i / 3], 1 + dp[i / 2]);
            } else if (!(i % 3)) {
                dp[i] = min(1 + dp[i / 3], 1 + dp[i - 1]);
            } else if (!(i % 2)) {
                dp[i] = min(1 + dp[i / 2], 1 + dp[i - 1]);
            } else {
                dp[i] = 1 + dp[i - 1];
            }
        }
    }
    cout << dp[n];
    return 0;
}
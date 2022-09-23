#include <iostream>
using namespace std;

int dp[10001];

int main(void) {
    int n, k, coin;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> coin;
        for (int j = coin; j <= k; j++) {
            dp[j] += dp[j - coin];
        }
    }
    cout << dp[k];
    return 0;
}
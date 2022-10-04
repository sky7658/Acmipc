#include <iostream>
using namespace std;

int dp[101][10001];
int n, m;
pair<int, int> cost[101];

int main(void) {
    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i].second;
        sum += cost[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (cost[i].second <= j) {
                dp[i][j] = max(dp[i - 1][j - cost[i].second] + cost[i].first,
                               dp[i][j]);
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
        }
    }
    for (int i = 0; i <= sum; i++) {
        if (dp[n][i] >= m) {
            cout << i;
            break;
        }
    }
    return 0;
}
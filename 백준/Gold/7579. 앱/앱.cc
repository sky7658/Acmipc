#include <iostream>
using namespace std;

int dp[10001][101];
int n, m;
pair<int, int> cost[101];

int main(void) {
    int min_cost = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cost[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i].second;
    }
    while (true) {
        for (int i = 0; i < n; i++) {
            if (cost[i].second > min_cost) {
                dp[min_cost][i] = dp[min_cost][i - 1];
            } else {
                dp[min_cost][i] =
                    max(dp[min_cost - cost[i].second][i - 1] + cost[i].first,
                        dp[min_cost][i - 1]);
            }
        }
        if (dp[min_cost][n - 1] >= m) break;
        min_cost++;
    }
    cout << min_cost;
    return 0;
}
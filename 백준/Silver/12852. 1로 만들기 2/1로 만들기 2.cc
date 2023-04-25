#include <iostream>
using namespace std;

int n;
pair<int, int> dp[1000001];

int main(void) {
    cin >> n;

    for (int i = 2; i <= n; i++) dp[i].first = 1000001;

    for (int i = 2; i <= n; i++) {
        if (i % 3 == 0) {
            if (dp[i].first > dp[i / 3].first + 1) {
                dp[i].first = dp[i / 3].first + 1;
                dp[i].second = i / 3;
            }
        }
        if (i % 2 == 0) {
            if (dp[i].first > dp[i / 2].first + 1) {
                dp[i].first = dp[i / 2].first + 1;
                dp[i].second = i / 2;
            }
        }
        if (dp[i].first > dp[i - 1].first + 1) {
            dp[i].first = dp[i - 1].first + 1;
            dp[i].second = i - 1;
        }
    }
    cout << dp[n].first << '\n';

    while (n > 0) {
        cout << n << ' ';
        n = dp[n].second;
    }
    return 0;
}

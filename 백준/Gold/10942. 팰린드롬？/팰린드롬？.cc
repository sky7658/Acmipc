#include <iostream>
using namespace std;

int dp[2001][2001];
int num[2000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, s, e;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        dp[i + 1][i + 1] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            if (num[j - 1] == num[j + i - 1]) {
                if (i == 1)
                    dp[j][j + i] = 1;
                else if (dp[j + 1][j + i - 1] == 1)
                    dp[j][j + i] = 1;
            } else
                dp[j][j + i] = 0;
        }
    }
    cin >> m;
    while (m-- > 0) {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
    return 0;
}
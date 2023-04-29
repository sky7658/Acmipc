#include <iostream>
using namespace std;

int dp[1001][1001];
string s1, s2;

int main(void) {
    cin >> s1 >> s2;
    int max_len = 0;

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[s1.length()][s2.length()] << '\n';

    string ans;
    int size = s2.size();

    for (int i = s1.size(); i >= 0; i--) {
        for (int j = size; j >= 0; j--) {
            if (dp[i][j] == dp[i - 1][j]) {
                size = j;
                break;
            } else if (dp[i][j] == dp[i][j - 1])
                continue;
            else
                ans = s2[j - 1] + ans;
        }
    }
    cout << ans;
    return 0;
}
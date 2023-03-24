#include <iostream>
using namespace std;

int dp[200001][26];

int main(void) {
    string s;
    int q, l, r;
    char c;
    cin >> s >> q;
    for (int i = 0; i < s.length(); i++) {
        dp[i][s[i] - 'a']++;
        for (int j = 0; j < 26; j++) {
            dp[i][j] += dp[i - 1][j];
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> c >> l >> r;
        cout << dp[r][c - 'a'] - dp[l - 1][c - 'a'] << '\n';
    }
    return 0;
}
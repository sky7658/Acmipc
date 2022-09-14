#include <iostream>
using namespace std;

int dp[31][40001];
int w[30];
int num, check, chu;

void dfs(int weight, int cnt) {
    if (cnt > num || dp[cnt][weight]) {
        return;
    }

    dp[cnt][weight] = 1;

    dfs(weight + w[cnt], cnt + 1);
    dfs(weight, cnt + 1);
    dfs(weight - w[cnt], cnt + 1);
}

int main(void) {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> w[i];
    }
    dfs(0, 0);
    cin >> check;

    for (int i = 0; i < check; i++) {
        cin >> chu;
        if (dp[num][chu])
            cout << "Y ";
        else
            cout << "N ";
    }

    return 0;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int dp[100001];
    
    dp[0] = 1;
    
    for (int i = 0; i < money.size(); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < money[i]) continue;
            dp[j] += dp[j - money[i]];
        }
    }
    
    return dp[n];
}
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> dp(8);

int solution(int N, int number) {
    if(N == number) return 1;
    
    dp[0].insert(N);
    
    int result = N;
    
    for(int i = 1; i < 8; i++) {
        result = result * 10 + N;
        dp[i].insert(result);
        
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < i; k++) {
                if(j + k + 1 != i) continue;
                
                for(auto a : dp[j]) {
                    for(auto b : dp[k]) {
                        dp[i].insert(a + b);
                        if(a - b > 0)
                            dp[i].insert(a - b);
                        dp[i].insert(a * b);
                        if(a / b > 0)
                            dp[i].insert(a / b);
                        
                    }
                }
            }
        }
        if(dp[i].find(number) != dp[i].end()) return i + 1;
    }
    
    return -1;
}
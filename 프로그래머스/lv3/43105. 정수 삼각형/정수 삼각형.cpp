#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[500][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 0; i < triangle.size() - 1; i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            if(j == 0) dp[i + 1][j] = dp[i][j] + triangle[i + 1][j];
            dp[i + 1][j + 1] = max(dp[i][j], dp[i][j + 1]) + triangle[i + 1][j + 1];
        }
    }
    
    for(int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
        answer = max(answer, dp[triangle.size() - 1][i]);
    }
    
    return answer;
}
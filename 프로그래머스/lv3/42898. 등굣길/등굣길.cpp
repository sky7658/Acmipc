#include <string>
#include <vector>

using namespace std;

int map[100][100];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i = 0; i < puddles.size(); i++) {
        map[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }
    map[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == -1) continue;
            
            if(i + 1 < n && map[i + 1][j] != -1) {
                map[i + 1][j] += map[i][j];
                map[i + 1][j] %= 1000000007;
            }
                
            if(j + 1 < m && map[i][j + 1] != -1) {
                map[i][j + 1] += map[i][j];
                map[i][j + 1] %= 1000000007;
            }
                
        }
    }
    
    return map[n - 1][m - 1];
}
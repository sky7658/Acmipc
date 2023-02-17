#include <string>
#include <vector>
#include <queue>

using namespace std;

int map[102][102];
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visit[102][102];
queue<pair<int, int>> q;

void bfs(vector<vector<int>> rectangle, int itemX, int itemY) {
    
    while(!q.empty()) {
        int mx = q.front().second;
        int my = q.front().first;
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int tx = mx + d[i][1];
            int ty = my + d[i][0];
            
            if(tx < 1 || tx > 100 || ty < 1 || ty > 100 || visit[ty][tx] || !map[ty][tx]) continue;
            
            q.push({ty, tx});
            visit[ty][tx] = true;
            map[ty][tx] = map[my][mx] + 1;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int x1, x2, y1, y2;
    
    characterX *= 2, characterY *= 2;
    itemX *= 2, itemY *= 2;
    
    for (int i = 0; i < rectangle.size(); i++) {
        x1 = rectangle[i][0] * 2, x2 = rectangle[i][2] * 2;
        y1 = rectangle[i][1] * 2, y2 = rectangle[i][3] * 2;
        
        for (int j = y1; j <= y2; j++) {
            for (int k = x1; k <= x2; k++) map[j][k] = 1;
        }
    }
    for (int i = 0; i < rectangle.size(); i++) {
        x1 = rectangle[i][0] * 2, x2 = rectangle[i][2] * 2;
        y1 = rectangle[i][1] * 2, y2 = rectangle[i][3] * 2;
        
        for (int j = y1 + 1; j < y2; j++) {
            for (int k = x1 + 1; k < x2; k++) map[j][k] = 0;
        }
    }
    
    visit[characterY][characterX] = true;
    q.push({characterY, characterX});
    
    bfs(rectangle, itemX, itemY);
    
    return map[itemY][itemX] / 2;
}
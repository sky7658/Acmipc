#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visit[101][101];
int map[101][101];

queue<pair<int, int>> q;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    q.push({0, 0});
    visit[0][0] = true;
    
    int count = 2;
    int size = q.size();
    
    map[0][0] = 1;
    
    while(!q.empty())
    {
        for(int i = 0; i < 4; i++) {
            int tx = q.front().second + d[i][1];
            int ty = q.front().first + d[i][0];
            
            if(tx >= 0 && ty >= 0 && ty < n && tx < m && !visit[ty][tx] && maps[ty][tx])
            {
                q.push({ty, tx});
                visit[ty][tx] = true;
                map[ty][tx] = count;
            }
        }
        q.pop();
        if(--size == 0) {
            size = q.size();
            count++;
        }
    }
    if(visit[n - 1][m - 1])
        return map[n - 1][m - 1];
    else
        return -1;
}
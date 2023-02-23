#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
queue<int> q;
bool visit[100];

int bfs(vector<vector<int>> wires) {
    int count = 1;
    
    while(!q.empty()) {
        int index = q.front();
        q.pop();
        for(int i = 0; i < wires.size(); i++) {
            if(visit[i]) {
                continue;
            }
            if(wires[i][0] == index) {
                visit[i] = true;
                q.push(wires[i][1]);
                count++;
            }
            if(wires[i][1] == index) {
                visit[i] = true;
                q.push(wires[i][0]);
                count++;
            }
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999;
    
    for(int i = 0; i < wires.size(); i++) {
        q.push(wires[i][0]);
        visit[i] = true;
        int x = bfs(wires);
        if(n - x > x) {
            answer = min(answer, n - x * 2);
        } else {
            answer = min(answer, x * 2 - n);
        }
        for(int j = 0; j < wires.size(); j++) visit[j] = false;           
    }
    return answer;
}
#include <string>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
bool visit[200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int j = 0; j < computers.size(); j++) {
        if(visit[j]) continue;
        for(int k = 0; k < computers[j].size(); k++) {
            if(!computers[j][k] || visit[k]) continue;
            visit[k] = true;
            q.push(k);
        }
        if(q.empty()) continue;
        while(!q.empty()) {
            int index = q.front();
            q.pop();
            for(int i = 0; i < computers[index].size(); i++) {
                if(!computers[index][i] || visit[i]) continue;
                visit[i] = true;
                q.push(i);
            }
        }
        answer++;
    }
    return answer;
}
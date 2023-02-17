#include <string>
#include <vector>
using namespace std;

bool visit[50];
int answer = 9999;

void dfs(string begin, string target, vector<string> words, int change) {
    if(answer <= change) return;
    
    if(begin == target) {
        answer = min(answer, change);
        return ;
    }
    
    for(int i = 0; i < words.size(); i++) {
        int count = 0;
        
        if(visit[i]) continue;
        
        for(int j = 0; j < words[i].size(); j++) {
            if(begin[j] == words[i][j]) count++;
        }
        if(count == words[i].size() - 1) {
            visit[i] = true;
            dfs(words[i], target, words, change + 1);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if(answer == 9999) return 0;
    return answer;
}
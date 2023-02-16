#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> answer;
bool visit[10000];

void dfs(vector<vector<string>> tickets, string arrive) {
    if (answer.size() == tickets.size() + 1) return;

    for (int i = 0; i < tickets.size(); i++) {
        if (arrive != tickets[i][0] || visit[i]) continue;

        visit[i] = true;
        answer.push_back(tickets[i][1]);
        dfs(tickets, tickets[i][1]);
        if (answer.size() == tickets.size() + 1) return;
        answer.pop_back();
        visit[i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());

    answer.push_back("ICN");
    dfs(tickets, "ICN");

    return answer;
}
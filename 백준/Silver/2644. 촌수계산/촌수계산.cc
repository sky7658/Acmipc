#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, s, e, p, c;

int bfs(vector<vector<int>> p) {
    int visit[101] = {
        0,
    };
    queue<int> q;
    q.push(s);
    visit[s] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == e) return visit[x];
        for (int i = 0; i < p[x].size(); i++) {
            if (visit[p[x][i]]) continue;

            visit[p[x][i]] = visit[x] + 1;
            q.push(p[x][i]);
        }
    }

    return -1;
}

int main(void) {
    cin >> n >> s >> e >> m;
    vector<vector<int>> per(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        per[a].push_back(b);
        per[b].push_back(a);
    }

    cout << bfs(per);

    return 0;
}
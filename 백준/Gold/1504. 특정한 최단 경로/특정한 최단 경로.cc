#include <iostream>
#include <queue>
#include <vector>
#define MAX 987654321
using namespace std;

int n, e, v1, v2;

int bfs(int start, int end, vector<vector<pair<int, int>>> line) {
    int dist[801];

    for (int i = 1; i <= n; i++) {
        dist[i] = MAX;
    }

    dist[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, start});

    while (!q.empty()) {
        int x = q.top().second;
        int w = -q.top().first;
        q.pop();

        for (int i = 0; i < line[x].size(); i++) {
            if (w + line[x][i].second >= dist[line[x][i].first]) continue;

            dist[line[x][i].first] = w + line[x][i].second;
            q.push({-dist[line[x][i].first], line[x][i].first});
        }
    }

    return dist[end];
}

int main(void) {
    cin >> n >> e;
    vector<vector<pair<int, int>>> line(n + 1);

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        line[a].push_back({b, c});
        line[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    int ans = MAX;

    ans = min(ans, bfs(1, v1, line) + bfs(v1, v2, line) + bfs(v2, n, line));
    ans = min(ans, bfs(1, v2, line) + bfs(v2, v1, line) + bfs(v1, n, line));

    if (ans == MAX || bfs(v1, v2, line) == MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}
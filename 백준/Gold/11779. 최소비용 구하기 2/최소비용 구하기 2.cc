#include <iostream>
#include <queue>
#include <vector>
#define MAX 987654321
using namespace std;

int n, m, s, e;
int dist[1001][2];
vector<vector<pair<int, int>>> bus(1001);

void Dijkstra() {
    for (int i = 1; i <= n; i++) dist[i][0] = MAX;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    dist[s][0] = 0;

    while (!q.empty()) {
        int x = q.top().second;
        int w = -q.top().first;
        q.pop();

        if (x == e) break;

        for (int i = 0; i < bus[x].size(); i++) {
            int nextX = bus[x][i].first;
            int nextW = bus[x][i].second;
            if (dist[nextX][0] <= w + nextW) continue;
            dist[nextX][0] = w + nextW;
            dist[nextX][1] = x;
            q.push({-dist[nextX][0], nextX});
        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }
    cin >> s >> e;
    Dijkstra();
    cout << dist[e][0] << '\n';
    vector<int> ans;
    while (e != 0) {
        ans.push_back(e);
        e = dist[e][1];
    }
    cout << ans.size() << '\n';
    while (!ans.empty()) {
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1234567891234
using namespace std;

int n, m, a, b, c;
long long dist[101];
vector<vector<pair<int, int>>> bus(101);

void Dijkstra(int s) {
    for (int i = 1; i <= n; i++) dist[i] = MAX;
    priority_queue<pair<long long, int>> q;
    q.push({0, s});
    dist[s] = 0;

    while (!q.empty()) {
        int x = q.top().second;
        long long w = -q.top().first;
        q.pop();

        for (int i = 0; i < bus[x].size(); i++) {
            int nextX = bus[x][i].first;
            int nextW = bus[x][i].second;

            if (dist[nextX] <= w + nextW) continue;

            dist[nextX] = w + nextW;
            q.push({-dist[nextX], nextX});
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++) {
        Dijkstra(i);
        for (int j = 1; j <= n; j++) {
            if (dist[j] == MAX)
                cout << 0 << ' ';
            else
                cout << dist[j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
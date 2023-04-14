#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 987654321
using namespace std;

int T, n, m, t, s, g, h;
int dist[2001];

void Dijkstra(vector<vector<pair<int, int>>> road, int s) {
    for (int i = 1; i <= n; i++) dist[i] = MAX;

    priority_queue<pair<int, int>> q;
    q.push({0, s});
    dist[s] = 0;

    while (!q.empty()) {
        int x = q.top().second;
        int w = -q.top().first;
        q.pop();

        for (int i = 0; i < road[x].size(); i++) {
            int nextX = road[x][i].first;
            int nextW = road[x][i].second;

            if (dist[nextX] <= w + nextW) continue;
            dist[nextX] = w + nextW;
            q.push({-dist[nextX], nextX});
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T-- > 0) {
        int hintCost;

        cin >> n >> m >> t >> s >> g >> h;
        vector<vector<pair<int, int>>> road(n + 1);
        vector<int> answer;

        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            road[a].push_back({b, d});
            road[b].push_back({a, d});

            if ((a == g && b == h) || (a == h && b == g)) hintCost = d;
        }

        for (int i = 0; i < t; i++) {
            Dijkstra(road, s);

            int x;
            cin >> x;
            int w = dist[x];

            int hintG = 0, hintH = 0;

            hintG = dist[g] + hintCost;
            hintH = dist[h] + hintCost;

            Dijkstra(road, h);
            hintG += dist[x];

            Dijkstra(road, g);
            hintH += dist[x];

            if (hintG == w || hintH == w) answer.push_back(x);
        }
        sort(answer.begin(), answer.end());
        for (auto itr = answer.begin(); itr != answer.end(); itr++)
            cout << *itr << ' ';
        cout << '\n';
    }
    return 0;
}
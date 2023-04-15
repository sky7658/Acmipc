#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

int n, m, a, b, c;
long long dist[501];
vector<vector<pair<int, int>>> bus(501);

void Bellman_Ford() {
    for (int i = 1; i <= n; i++) {
        if (dist[i] == MAX) continue;
        for (int j = 0; j < bus[i].size(); j++) {
            int nextX = bus[i][j].first;
            int nextW = bus[i][j].second;

            if (dist[nextX] <= dist[i] + nextW) continue;
            dist[nextX] = dist[i] + nextW;
        }
    }
}

bool Negative_Cycle() {
    for (int i = 2; i <= n; i++) dist[i] = MAX;

    for (int t = 1; t < n; t++) {
        Bellman_Ford();
    }

    int copy_dist[501];
    for (int i = 1; i <= n; i++) {
        copy_dist[i] = dist[i];
    }

    Bellman_Ford();

    for (int i = 1; i <= n; i++) {
        if (copy_dist[i] != dist[i]) return true;
    }

    return false;
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }

    if (Negative_Cycle()) {
        cout << -1;
    } else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == MAX)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }

    return 0;
}
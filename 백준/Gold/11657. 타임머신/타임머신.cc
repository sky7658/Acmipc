#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

int n, m, a, b, c;
long long dist[501];
vector<pair<pair<int, int>, int>> bus;

bool Bellman_Ford() {
    for (int i = 2; i <= n; i++) dist[i] = MAX;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < bus.size(); j++) {
            int from = bus[j].first.first;
            int to = bus[j].first.second;
            int cost = bus[j].second;

            if (dist[from] == MAX) continue;
            if (dist[to] <= dist[from] + cost) continue;
            dist[to] = dist[from] + cost;
        }
    }

    for (int j = 0; j < bus.size(); j++) {
        int from = bus[j].first.first;
        int to = bus[j].first.second;
        int cost = bus[j].second;

        if (dist[from] == MAX) continue;
        if (dist[to] > dist[from] + cost) return true;
    }

    return false;
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        bus.push_back({{a, b}, c});
    }

    if (Bellman_Ford()) {
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
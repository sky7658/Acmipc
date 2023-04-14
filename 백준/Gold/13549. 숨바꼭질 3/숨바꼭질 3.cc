#include <iostream>
#include <queue>
#define MAX 987654321
using namespace std;

int n, k;
priority_queue<pair<int, int>> q;
int dist[100001];

bool EscapeRange(int x) {
    if (x < 0 || x > 100000) return true;
    return false;
}

void Dijkstra() {
    for (int i = 0; i < 100001; i++) dist[i] = MAX;

    q.push({0, n});
    dist[n] = 0;

    while (!q.empty()) {
        int x = q.top().second;
        int w = -q.top().first;
        q.pop();

        for (int i = 0; i < 3; i++) {
            int _x;
            int cost;
            switch (i) {
                case 0:
                    _x = x + 1;
                    cost = 1;
                    break;
                case 1:
                    _x = x - 1;
                    cost = 1;
                    break;
                case 2:
                    _x = x * 2;
                    cost = 0;
                    break;
            }

            if (EscapeRange(_x)) continue;
            if (dist[_x] <= w + cost) continue;
            dist[_x] = cost + dist[x];
            q.push({-dist[_x], _x});
        }
    }
}

int main(void) {
    cin >> n >> k;
    Dijkstra();
    cout << dist[k];
    return 0;
}
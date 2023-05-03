#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

int n, m;
int dist[101][101][2];
vector<int> v;

void Route(int start, int end) {
    if (dist[start][end][1] == 0) {
        v.push_back(start);
        v.push_back(end);
        return;
    }
    Route(start, dist[start][end][1]);
    v.pop_back();
    Route(dist[start][end][1], end);
}

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j][0] = MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b][0] > c) {
            dist[a][b][0] = c;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (k == j) continue;
                if (dist[j][k][0] > dist[j][i][0] + dist[i][k][0]) {
                    dist[j][k][0] = dist[j][i][0] + dist[i][k][0];
                    dist[j][k][1] = i;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j][0] >= MAX)
                cout << 0 << ' ';
            else
                cout << dist[i][j][0] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j][0] == MAX) {
                cout << 0;
            } else {
                v.clear();
                Route(i, j);
                cout << v.size() << ' ';
                for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
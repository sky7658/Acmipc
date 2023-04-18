#include <iostream>
#define MAX 987654321
using namespace std;

int v, e, a, b, c;
int dist[401][401];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) dist[i][j] = MAX;
    }

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int p = 1; p <= v; p++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][p] + dist[p][j]);
            }
        }
    }

    int answer = MAX;

    for (int i = 1; i <= v; i++) {
        answer = min(answer, dist[i][i]);
    }

    if (answer == MAX)
        cout << -1;
    else
        cout << answer;
    return 0;
}
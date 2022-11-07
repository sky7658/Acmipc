#include <iostream>
#include <queue>
using namespace std;

int field[200001];
int dx[3] = {1, -1, 0};
queue<int> q;
int n, k;

void bfs() {
    q.push(n);
    field[n] = 0;

    while (!q.empty()) {
        dx[2] = q.front();
        for (int i = 0; i < 3; i++) {
            int nx = q.front() + dx[i];
            if (nx >= 0 && nx < 200001 && field[nx] == 0) {
                q.push(nx);
                if (field[nx] > 0)
                    field[nx] = min(field[q.front()] + 1, field[nx]);
                else
                    field[nx] = field[q.front()] + 1;
            }
        }
        q.pop();
    }
}

int main(void) {
    cin >> n >> k;
    bfs();
    if (n == k)
        cout << 0;
    else
        cout << field[k];
    return 0;
}
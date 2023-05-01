#include <iostream>
#include <queue>
using namespace std;

int t, a, b;
bool visit[10000];

void bfs() {
    for (int i = 0; i < 10000; i++) {
        visit[i] = false;
    }

    queue<pair<int, string>> q;
    q.push({a, ""});
    visit[a] = true;

    while (!q.empty()) {
        int x = q.front().first;
        string str = q.front().second;
        q.pop();

        if (x == b) {
            cout << str << '\n';
            return;
        }

        int nextX;

        nextX = (x * 2) % 10000;
        if (!visit[nextX]) {
            q.push({nextX, str + "D"});
            visit[nextX] = true;
        }

        nextX = x - 1 < 0 ? 9999 : x - 1;
        if (!visit[nextX]) {
            q.push({nextX, str + "S"});
            visit[nextX] = true;
        }

        nextX = (x % 1000) * 10 + x / 1000;
        if (!visit[nextX]) {
            q.push({nextX, str + "L"});
            visit[nextX] = true;
        }

        nextX = x / 10 + (x % 10) * 1000;
        if (!visit[nextX]) {
            q.push({nextX, str + "R"});
            visit[nextX] = true;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t-- > 0) {
        cin >> a >> b;
        bfs();
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
pair<int, int> visit[100001];

bool EscapeRange(int x) {
    if (x > 100000 || x < 0) return true;
    return false;
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visit[start].first = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (!EscapeRange(x + 1) && !visit[x + 1].first) {
            q.push(x + 1);
            visit[x + 1].first = visit[x].first + 1;
            visit[x + 1].second = x;
        }
        if (!EscapeRange(x - 1) && !visit[x - 1].first) {
            q.push(x - 1);
            visit[x - 1].first = visit[x].first + 1;
            visit[x - 1].second = x;
        }
        if (!EscapeRange(x * 2) && !visit[x * 2].first) {
            q.push(x * 2);
            visit[x * 2].first = visit[x].first + 1;
            visit[x * 2].second = x;
        }
    }
}

int main(void) {
    cin >> n >> k;
    bfs(n);
    cout << visit[k].first - 1 << '\n';
    int i = k;
    vector<int> v;
    while (true) {
        v.push_back(i);
        if (i == n) break;
        i = visit[i].second;
    }
    while (!v.empty()) {
        cout << v.back() << ' ';
        v.pop_back();
    }
    return 0;
}
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define PLUS 32768
using namespace std;

int t, n;
pair<int, int> home, arrive;

int CalDis(int x1, int x2, int y1, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

string bfs(vector<pair<int, int>> combini) {
    queue<pair<int, int>> q;
    bool visit[100] = {
        false,
    };
    q.push(home);

    while (!q.empty()) {
        int curX = q.front().second;
        int curY = q.front().first;
        q.pop();

        if (CalDis(curX, arrive.second, curY, arrive.first) <= 1000)
            return "happy";

        for (int i = 0; i < combini.size(); i++) {
            int nextX = combini[i].second;
            int nextY = combini[i].first;

            if (CalDis(curX, nextX, curY, nextY) > 1000 || visit[i]) continue;

            visit[i] = true;
            q.push(combini[i]);
        }
    }
    return "sad";
}

int main(void) {
    cin >> t;
    while (t-- > 0) {
        vector<pair<int, int>> combini;

        cin >> n;
        cin >> home.second >> home.first;
        home.first += PLUS;
        home.second += PLUS;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            combini.push_back({b + PLUS, a + PLUS});
        }
        cin >> arrive.second >> arrive.first;
        arrive.first += PLUS;
        arrive.second += PLUS;

        cout << bfs(combini) << '\n';
    }
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string town[25];
bool visit[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt, n;

void dfs(int x, int y) {
    cnt++;
    visit[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && town[ny][nx] == '1' &&
            visit[ny][nx] == false)
            dfs(nx, ny);
    }
}

int main(void) {
    int number = 0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> town[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (town[i][j] == '1' && visit[i][j] == false) {
                dfs(j, i);
                number++;
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << number << '\n';
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> net[101];
bool visit[101];
int cnt;

void dfs(int n) {
    visit[n] = true;
    for (int i = 0; i < net[n].size(); i++) {
        int num = net[n][i];
        if (visit[num]) continue;
        cnt++;
        dfs(num);
    }
}

int main(void) {
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        net[a].push_back(b);
        net[b].push_back(a);
    }
    dfs(1);
    cout << cnt;
    return 0;
}
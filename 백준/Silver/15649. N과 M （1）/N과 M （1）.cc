#include <iostream>
#include <vector>
using namespace std;
bool visit[8];
vector<int> v;
void dfs(int start, int cnt, int n)
{
    if (cnt == 0)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
        cout << '\n';
        return ;
    }

    for (int i = 1; i <= start; i++)
    {
        if (visit[i])
            continue;
        v.push_back(i);
        visit[i] = true;
        dfs(start, cnt - 1, i);
        v.pop_back();
        visit[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    dfs(n, m, 1);

    return 0;
}
#include <iostream>
using namespace std;
int chess[15];
int c;
void dfs(int n, int cnt, int order)
{
    if (cnt == 0)
    {
        c++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int j;
        
        chess[order] = i;
        if (order != 0)
        {
            for (j = 0; j < order; j++)
            {
                if (chess[j] == chess[order] || ((i - chess[j]) / float(order - j) == 1 || (i - chess[j]) / float(order - j) == -1))
                    break;
            }
            if (j != order)
                continue;
        }
        dfs(n, cnt - 1, order + 1);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dfs(n, n, 0);
    cout << c;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n, m, y, x, k;
int map[21][21];
int order[1001];
vector<int> dice(7);

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        cin >> order[i];
    }
}

void rollEast()
{
    dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
}

void rollWest()
{
    dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}

void rollNorth()
{
    dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
}

void rollSouth()
{
    dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
}

void roll(int order)
{
    switch (order)
    {
    case 1:
        rollEast();
        break;
    case 2:
        rollWest();
        break;
    case 3:
        rollNorth();
        break;
    case 4:
        rollSouth();
        break;
    default:
        break;
    }
}

void solve()
{
    for (int i = 0; i < k; i++)
    {
        int my = dy[order[i]];
        int mx = dx[order[i]];
        if (y + my >= n || y + my < 0 || x + mx >= m || x + mx < 0)
            continue;
        y += my;
        x += mx;
        roll(order[i]);

        cout << dice[1] << '\n'; 

        if (map[y][x] == 0)
            map[y][x] = dice[6];
        else
        {
            dice[6] = map[y][x];
            map[y][x] = 0;
        }
    }
}

int main()
{
    input();
    solve();

    return 0;
}
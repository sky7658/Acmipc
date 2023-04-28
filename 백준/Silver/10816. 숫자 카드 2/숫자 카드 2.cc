#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, num;
    map<int, int> card;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (card.find(num) == card.end())
            card.insert({ num, 1 });
        else
            card[num]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        if (card[num])
            cout << card[num] << ' ';
        else
            cout << 0 << ' ';
    }

    return 0;
}
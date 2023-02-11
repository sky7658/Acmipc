#include <iostream>
#include <queue>
using namespace std;

int n, k, ax, ay, l, x, time;
pair<int, int> head, tail;
char c;
int map[2][101][101];
bool apple[101][101];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

queue<pair<int, char>> arrow;

int main(void) {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> ay >> ax;
        apple[ay - 1][ax - 1] = true;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x >> c;
        arrow.push({x, c});
    }

    int direction = 0;

    while (true) {
        time++;

        map[0][head.first][head.second] = direction;
        map[1][head.first][head.second] = 1;

        head.first += d[direction][0];
        head.second += d[direction][1];

        if (map[1][head.first][head.second] || head.first < 0 ||
            head.second < 0 || head.first >= n || head.second >= n)
            break;
        if (!apple[head.first][head.second]) {
            int px = tail.second;
            int py = tail.first;

            tail.first += d[map[0][py][px]][0];
            tail.second += d[map[0][py][tail.second]][1];

            map[1][py][px] = 0;
        }

        apple[head.first][head.second] = false;

        if (!arrow.empty() && arrow.front().first == time) {
            if (arrow.front().second == 'D')
                ++direction;
            else
                --direction += 4;
            direction %= 4;

            arrow.pop();
        }
    }

    cout << time;
    return 0;
}
#include <iostream>
using namespace std;

int n, max_xh = 0, min_xh = 0, max_yh = 0, min_yh = 0;
int arrow = 2;
pair<int, int> d[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
pair<int, int> current_d = {0, 0};
string str;
char miro[50][50];

int main(void) {
    cin >> n >> str;

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            miro[i][j] = '#';
        }
    }

    for (int i = 0; i < n; i++) {
        if (str[i] == 'R') {
            arrow++;
            if (arrow > 3) arrow = 0;
        } else if (str[i] == 'L') {
            arrow--;
            if (arrow < 0) arrow = 3;
        } else {
            current_d.first += d[arrow].first;
            current_d.second += d[arrow].second;
        }
        max_xh = max(max_xh, current_d.first);
        min_xh = min(min_xh, current_d.first);
        max_yh = max(max_yh, current_d.second);
        min_yh = min(min_yh, current_d.second);
    }

    current_d.first = -min_xh;
    current_d.second = -min_yh;
    miro[current_d.second][current_d.first] = '.';
    arrow = 2;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'R') {
            arrow++;
            if (arrow > 3) arrow = 0;
        } else if (str[i] == 'L') {
            arrow--;
            if (arrow < 0) arrow = 3;
        } else {
            current_d.first += d[arrow].first;
            current_d.second += d[arrow].second;
            miro[current_d.second][current_d.first] = '.';
        }
    }
    for (int i = 0; i < max_yh - min_yh + 1; i++) {
        for (int j = 0; j < max_xh - min_xh + 1; j++) cout << miro[i][j];
        cout << '\n';
    }

    return 0;
}
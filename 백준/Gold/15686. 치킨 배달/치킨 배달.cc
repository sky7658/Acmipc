#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n, m, answer = 999999999;
int city[50][50];

vector<pair<int, int>> all;
vector<pair<int, int>> part;

int Distance() {
    int min_distance = 1000, result;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (city[i][j] == 1) {
                for (int k = 0; k < m; k++) {
                    min_distance =
                        min(min_distance,
                            abs(i - part[k].first) + abs(j - part[k].second));
                }
                result += min_distance;
                min_distance = 1000;
            }
        }
    }

    return result;
}

void Choice(int start, int choose) {
    if (choose == m) {
        answer = min(answer, Distance());
        return;
    }

    for (int i = start; i < all.size(); i++) {
        part.push_back(all[i]);
        Choice(i + 1, choose + 1);
        part.pop_back();
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 2) all.push_back({i, j});
        }
    }

    Choice(0, 0);

    cout << answer;
    return 0;
}
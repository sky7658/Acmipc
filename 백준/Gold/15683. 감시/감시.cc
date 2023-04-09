#include <iostream>
#include <vector>
using namespace std;

int n, m, answer = 999;
int map[8][8];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<int> cctvType;
vector<pair<int, int>> cctvXY;

void ArrCopy(int (*arr)[8], int (*copyarr)[8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = copyarr[i][j];
        }
    }
}

void Fill(int x, int y, int arrow) {
    while (map[y][x] != 6) {
        if (map[y][x] == 0) map[y][x] = 7;
        y += d[arrow][0];
        x += d[arrow][1];
        if (y < 0 || x < 0 || y >= n || x >= m) break;
    }
}

void ProcessCCTV(int index) {
    if (index >= cctvType.size()) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (map[i][j] == 0) count++;
        }
        answer = min(answer, count);
        return;
    }

    int copy_map[8][8];
    ArrCopy(copy_map, map);
    int x = cctvXY[index].second;
    int y = cctvXY[index].first;

    switch ((cctvType[index])) {
        case 1:
            for (int i = 0; i < 4; i++) {
                Fill(x, y, i);
                ProcessCCTV(index + 1);
                ArrCopy(map, copy_map);
            }
            break;
        case 2:
            for (int i = 0; i < 2; i++) {
                Fill(x, y, i);
                Fill(x, y, i + 2);
                ProcessCCTV(index + 1);
                ArrCopy(map, copy_map);
            }
            break;
        case 3:
            for (int i = 0; i < 4; i++) {
                Fill(x, y, i);
                Fill(x, y, (i + 1) % 4);
                ProcessCCTV(index + 1);
                ArrCopy(map, copy_map);
            }
            break;
        case 4:
            for (int i = 0; i < 4; i++) {
                Fill(x, y, i);
                Fill(x, y, (i + 1) % 4);
                Fill(x, y, (i + 2) % 4);
                ProcessCCTV(index + 1);
                ArrCopy(map, copy_map);
            }
            break;
        case 5:
            for (int i = 0; i < 4; i++) Fill(x, y, i);
            ProcessCCTV(index + 1);
            ArrCopy(map, copy_map);
            break;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0 || map[i][j] == 6) continue;
            cctvType.push_back(map[i][j]);
            cctvXY.push_back({i, j});
        }
    }

    ProcessCCTV(0);
    cout << answer;
    return 0;
}
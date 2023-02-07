#include <cmath>
#include <iostream>
using namespace std;

int gear[4][8];
int front[4], r[4], l[4];
int k, gear_n, arrow, answer;
string n;

void Spin(int gearNum, int clockwise) {
    front[gearNum] += (-clockwise + 8);
    front[gearNum] %= 8;
    r[gearNum] += (-clockwise + 8);
    r[gearNum] %= 8;
    l[gearNum] += (-clockwise + 8);
    l[gearNum] %= 8;
}

int main(void) {
    for (int i = 0; i < 4; i++) {
        cin >> n;
        for (int j = 0; j < 8; j++) {
            gear[i][j] = n[j] - '0';
        }
        front[i] = 0;
        r[i] = 2;
        l[i] = 6;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> gear_n >> arrow;
        gear_n--;
        int j = 1, clockwise = arrow;
        bool isSpin = true;
        Spin(gear_n, clockwise);

        while (isSpin) {
            if (gear_n + j < 4 &&
                gear[gear_n + j - 1][(r[gear_n + j - 1] + clockwise + 8) % 8] !=
                    gear[gear_n + j][l[gear_n + j]]) {
                clockwise *= -1;
                Spin(gear_n + j, clockwise);
            } else {
                isSpin = false;
            }
            j++;
        }

        clockwise = arrow;
        isSpin = true;
        j = -1;

        while (isSpin) {
            if (gear_n + j >= 0 &&
                gear[gear_n + j + 1][(l[gear_n + j + 1] + clockwise + 8) % 8] !=
                    gear[gear_n + j][r[gear_n + j]]) {
                clockwise *= -1;
                Spin(gear_n + j, clockwise);
            } else {
                isSpin = false;
            }
            j--;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (gear[i][front[i]] == 1) {
            answer += pow(2, i);
        }
    }
    cout << answer;
    return 0;
}
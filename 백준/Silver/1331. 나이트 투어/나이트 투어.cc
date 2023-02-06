#include <cmath>
#include <iostream>
using namespace std;

string arrow[36];
bool chess[6][6];
bool check;

int main(void) {
    check = true;

    for (int i = 0; i < 36; i++) {
        cin >> arrow[i];
        if (i > 0) {
            if (abs(arrow[i - 1][1] - arrow[i][1]) == 2) {
                if (abs(arrow[i - 1][0] - arrow[i][0]) != 1) {
                    check = false;
                }
            } else if (abs(arrow[i - 1][1] - arrow[i][1]) == 1) {
                if (abs(arrow[i - 1][0] - arrow[i][0]) != 2) {
                    check = false;
                }
            } else {
                check = false;
            }
        }
        if (chess[arrow[i][1] - '1'][arrow[i][0] - 'A']) {
            check = false;
        }
        chess[arrow[i][1] - '1'][arrow[i][0] - 'A'] = true;
    }

    if (abs(arrow[0][1] - arrow[35][1]) == 2) {
        if (abs(arrow[0][0] - arrow[35][0]) != 1) {
            check = false;
        }
    } else if (abs(arrow[0][1] - arrow[35][1]) == 1) {
        if (abs(arrow[0][0] - arrow[35][0]) != 2) {
            check = false;
        }
    } else {
        check = false;
    }

    if (check)
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}
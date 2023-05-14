#include <iostream>
using namespace std;

int main(void) {
    int t, c;
    int change[4] = {25, 10, 5, 1};

    cin >> t;
    while (t-- > 0) {
        cin >> c;
        for (int i = 0; i < 4; i++) {
            if (c / change[i] > 0) {
                cout << c / change[i] << ' ';
                c %= change[i];
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
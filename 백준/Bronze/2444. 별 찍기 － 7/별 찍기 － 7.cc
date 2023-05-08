#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n * 2 - 1; i++) {
        if (i < n) {
            for (int j = 0; j < n - i - 1; j++) cout << ' ';
            for (int k = 0; k < 2 * i + 1; k++) cout << '*';
        } else {
            for (int j = 0; j < i - n + 1; j++) cout << ' ';
            for (int k = 0; k < 2 * (n * 2 - 1 - i) - 1; k++) cout << '*';
        }
        cout << '\n';
    }
    return 0;
}